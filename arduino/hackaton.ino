#include <IRremote.h>
#include <IRremoteInt.h>
#include <Wire.h>

int RECV_PIN = 7;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  // put your setup code here, to run once:
  //Wire.begin();
  //pinMode(TRANSMITTER_PIN, OUTPUT); // Set pin as an output

  // Enalble serial communication
  Serial.begin(9600);
  irrecv.enableIRIn();

  

}

void loop() {
  // put your main code here, to run repeatedly:

  if (irrecv.decode(&results)) {
    //Wire.beginTransmission(TRANSMITTER_PIN);
    //Wire.send(results.value);
    //Wire.endTransmission();
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
