// Pins
int sensorPin = 0;
int lightPin = 2;

// Variables
int lightState = 0;
int lowThreshold = 500;
int highTreshold = 600;

// Setup
void setup() {
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // Read the sensor pin
    int sensorValue = analogRead(sensorPin);
    
    // If light level is low is detected, switch light on
    if (sensorValue < lowThreshold){
        digitalWrite(lightPin, HIGH);
    }
    
    // If light level goes up again, switch the lights off
    if (sensorValue > highTreshold){
        digitalWrite(lightPin, LOW);
    }
}
