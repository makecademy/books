// Sensor pin
int sensor = 2;

// Setup
void setup() {
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // Read the sensor pin
    int sensorState = digitalRead(sensor);
    
    // Print out the state of the sensor
    Serial.println(sensorState);
    delay(10);
}
