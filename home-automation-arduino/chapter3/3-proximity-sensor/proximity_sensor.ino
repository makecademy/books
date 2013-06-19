// Includes
#include <Wire.h>
#include "vcnl4000.h"

// Define pin for audio output
int audioPin = 8;

// Setup
void setup() {
    
    // Init serial communication and configure the sensor with config()
    Serial.begin(9600);
    config();
    
}

// Main loop
void loop() {
    
    // Read proximity data
    long proximityData = readProximity();
    
    // Make a sound if something is detected
    if (proximityData > 4000){
        tone(audioPin, 440, 200);
    }
    
    // Print data every 10 ms
    Serial.println(proximityData);
    delay(10);
    
}
