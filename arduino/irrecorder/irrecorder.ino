#include <IRremote.h>
//#include <Wire.h>

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);
IRsend irsend;

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

// Storage for the recorded code
int codeType = -1; // The type of code
unsigned long codeValue; // The code value if not raw
unsigned int rawCodes[RAWBUF]; // The durations if raw
int codeLen; // The length of the code

/*
 * The code 
 */
void sendCodeToSerial(decode_results *results) {
  int count = results->rawlen;
  
  //Serial.println("Received unknown code, saving as raw");
  codeLen = results->rawlen - 1;
  // To store raw codes:
  // Drop first value (gap)
  // Convert from ticks to microseconds
  // Tweak marks shorter, and spaces longer to cancel out IR receiver distortion
  for (int i = 1; i <= codeLen; i++) {
    if (i % 2) {
      // Mark
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK - MARK_EXCESS;
    } else {
      // Space
      rawCodes[i - 1] = results->rawbuf[i]*USECPERTICK + MARK_EXCESS;
    }
    Serial.print(rawCodes[i - 1], DEC);
    Serial.print(" ");
  }
  Serial.println();
}

// Stores the code for later playback
// Most of this code is just logging
void storeCode(decode_results *results) {
  codeType = results->decode_type;
  if (codeType == UNKNOWN || codeType == SONY || codeType == RC5 || codeType == RC6) {
    // For this hackaton we only support NEC. The only reason is that the data will be to big for the Spark Core to send over the internet.
  } else if (codeType == NEC && results->value != REPEAT) {
    //sendCodeToSerial(results);
    Serial.println(results->value);
  }
  codeValue = results->value;
  codeLen = results->bits;
}

void loop() {
  if (irrecv.decode(&results)) {
    storeCode(&results);
    irrecv.resume(); // resume receiver
  }
}
