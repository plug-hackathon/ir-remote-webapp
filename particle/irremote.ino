// This #include statement was automatically added by the Particle IDE.
#include "IRremote.h"

IRsend irsend(D2);

String result;

void setup() {

    // Able request to record IR-signals
    Particle.function("emitIRSignal", emitIRSignal);
    
    // Able request to send IR-signals
    Particle.function("sendIRSignal", sendIRSignal);
    
}

void loop() {
    
    if(Serial1.available()) {
        
        //Read serial data from arduino
        result = Serial1.readStringUntil('\n');
        
        Particle.publish("emitIRSignal", result);
        
        delay(1000);
    }
    
}

int emitIRSignal(String command) {
    if(command == "start") {
        
        Serial.begin(9600);
        Serial1.begin(9600);
        
        Serial.println("Start sending...");
        
        return 0;
    }
    else if(command == "stop") {
        
        Serial.println("Stop sending...");
        
        Serial.end();
        Serial1.end();
        return 0;
    }
    else {
        return -1;
    }
}

int sendIRSignal(String irSignal) {

    int irCode = (int)strtol(irSignal, NULL, 10);
    
    Serial.begin(9600);
    
    Serial.println(irCode);
    
    irsend.sendNEC(irCode, 32);
    
    Serial.end();
    
    return 0;
}