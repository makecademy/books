// Includes
#include "DHT.h"

// Sensor pin
#define DHTPIN 2

// Type of sensor
#define DHTTYPE DHT11

// Create sensor instance
DHT dht(DHTPIN, DHTTYPE);

// Setup
void setup() {
    Serial.begin(9600);
    dht.begin();
}

// Main loop
void loop() {
    
    // Get data from sensor
    float h = dht.readHumidity();
    
    // Check if readout is valid
    if (isnan(h)) {
        Serial.println("Failed to read from sensor");
    } else {
        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.println(" %\t");
    }
}
