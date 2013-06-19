// LED pin
int led = 9;

// Setup
void setup() {
    pinMode(led, OUTPUT);
}

// Main loop
void loop() {
    // Make the LED blink
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led,LOW);
    delay(2000);
}
