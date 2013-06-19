// Define relay pin
int relayPin = 2;

// Setup
void setup() {
    // Set pin to output
    pinMode(relayPin, OUTPUT);
}

// Main loop
void loop() {
    
    // Switch betwen state
    digitalWrite(relayPin, LOW);
    delay(5000);
    digitalWrite(relayPin,HIGH);
    delay(5000);
    
}
