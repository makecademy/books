// Includes
#include <OneWire.h>

// Define pin for temperature sensor
int DS18S20_Pin = 8;

// Temperature sensor instance
OneWire sensor(DS18S20_Pin);

// Setup
void setup() {
    
    // Init serial communication
    Serial.begin(9600);
    
}

// Main loop
void loop() {
    
    // Read temperature & print it on the Serial monitor
    float temperature = getTemp();
    Serial.println(temperature);
    
    // Wait 100 ms between each measurement
    delay(100);
    
}
