// This #include statement was automatically added by the Particle IDE.
#include "IRremote.h"

IRsend irsend(D2);

//int rawCode = 0xFFA857;

String result;

void setup() {

    Serial.begin(9600);
    Serial1.begin(9600);
    
    // Able request to record IR-signals
    Particle.function("emitIRSignals", emitIRSignals);
    
    // Able request to send IR-signals
    Particle.function("sendIRSignal", sendIRSignal);
    
}

void loop() {

}

int emitIRSignals(String command) {
    if(command == "start" && Serial1.available()) {
        // Read serial data from arduino
        result = Serial1.readStringUntil('\n');
        
        Particle.publish(result);
        
        return 0;
    }
    else if(command == "stop") {
        return 0;
    }
    else {
        return -1;
    }
}

int sendIRSignal(String irSignal) {

    int number = (int)strtol(irSignal, NULL, 10);
    
    Serial.println(number);
    
    irsend.sendNEC(number, 32);
    
    return 0;
}