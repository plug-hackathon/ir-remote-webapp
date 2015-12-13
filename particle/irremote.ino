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
        RGB.color(74, 255, 0); // GREEN
        
        delay(1000);
    }
    
}

int emitIRSignal(String command) {
    if(command == "start") {
        
        Serial.begin(9600);
        Serial1.begin(9600);
        
        Serial.println("Start sending...");
        
        RGB.control(true);
        RGB.color(54, 0, 255); // BLUE
        
        return 0;
    }
    else if(command == "stop") {
        
        Serial.println("Stop sending...");
        
        RGB.control(false);
        
        Serial.end();
        Serial1.end();
        return 0;
    }
    else {
        RGB.control(true);
        RGB.color(255, 0, 0); // RED
        delay(1000);
        RGB.control(false);
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
