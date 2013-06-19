// Pins
int sensorPin = 7;
int lightPin = 2;

// Variables
int timerStart = 0;
unsigned long sensorTimer = 0;
int lightState = 0;

// Setup
void setup() {
    Serial.begin(9600);
}

// Main loop
void loop() {
    
    // Read the sensor pin
    int sensorState = digitalRead(sensorPin);
    
    // If motion is detected, switch light on
    if (lightState == 0 && sensorState == 1){
        digitalWrite(lightPin, HIGH);
        lightState = 1;
        timerStart = 0;
    }
    
    // If no motion is detected, and light is on, start timer
    if (lightState == 1 && sensorState == 0 && timerStart == 0){
        timerStart = 1;
        sensorTimer = millis();
    }
    
    // If the timer was started, and more than 5 seconds passed by, switch the light off
    if (timerStart == 1 && ((millis()-sensorTimer) > 5000)) {
        digitalWrite(lightPin, LOW);
        lightState = 0;
        timerStart = 0;
    }
}
