// Define analog pin
int sensorPin = 0;

// Setup
void setup() {
    // Init serial
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // Get temperature
    int sensorValue = analogRead(sensorPin);
    
    // Put temperature on the serial port
    Serial.println(sensorValue,DEC);
    
    // Wait for 1 sec
    delay(1000);
}
