#include <IRremote.h>
#include <IRremoteInt.h>
#include <Wire.h>

int RECV_PIN = 7;
int SPARK_CORE = 4;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  // put your setup code here, to run once:
  
  // Enalble serial communication
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  //Enable communication with spark core.
  Wire.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    
    Wire.beginTransmission(SPARK_CORE);
    Wire.print(results.value);
    delay(1000);
    Wire.endTransmission();
    delay(1000);
    Serial.println(results.value); // TODO: Check if HEX should be used or not!
    irrecv.resume(); // Recieve the next value
  }

}

/* 
 *  [] Få signal ifrån fjärren som hexadecimal
 *  [] Console log på aurdino
 *  [] Skicka vidare den signalen via transmit till spark
 *  [] Console log på spark
 */
