// Pins
int sensorPin = 1;
int lightPin = 9;

// Variables
int lightState = 0;
int lowThreshold = 50;
int highTreshold = 100;

// Setup
void setup() {
    Serial.begin(9600);
    pinMode(lightPin, OUTPUT);
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
