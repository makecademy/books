// Define pins
int switchPin = 2;

// Setup
void setup() {
    // Init serial
    Serial.begin(115200);
}

// Main loop
void loop() {
    
    // Get temperature
    int sensorValue = digitalRead(sensorPin);
    
    // Put temperature on the serial port
    Serial.println(sensorValue,DEC);
    
    // Wait for 1 sec
    delay(1000);
}
