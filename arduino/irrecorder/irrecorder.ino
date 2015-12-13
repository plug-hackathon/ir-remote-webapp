#include <IRremote.h>

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void storeCode(decode_results *results) {
  if (results->decode_type == NEC && results->value != REPEAT) {
    Serial.println(results->value);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    storeCode(&results);
    irrecv.resume();
  }
}
