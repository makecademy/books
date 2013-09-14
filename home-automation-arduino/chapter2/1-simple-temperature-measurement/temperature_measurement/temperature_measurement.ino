// Variables declaration
int raw_temperature;

// Setup
void setup() {
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // Analog acquisition
    raw_temperature = analogRead(0);
    
    // Print every 1 s
    Serial.println(raw_temperature, DEC);
    delay(1000);
}