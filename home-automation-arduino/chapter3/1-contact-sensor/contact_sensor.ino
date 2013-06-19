// Push button pin
int pushButton = 2;

// Setup
void setup() {
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // read the pin number 2
    int buttonState = digitalRead(pushButton);
    
    // print out the state of the button
    Serial.println(buttonState);
    delay(1);
}
