// Sensor pin
int sensorPin = 5;

// Setup
void setup() {
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // Read the sensor pin
    int sensorState = digitalRead(sensorPin);
    
    // Print out the state of the sensor
    Serial.println(sensorState);
    delay(10);
}
