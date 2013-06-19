int motorPin = 3;

// Setup
void setup()
{
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);
}

// Loop
void loop()
{
    // Accelerate
    for (int i = 0; i < 250; i++){
        Serial.println(i);
        analogWrite(motorPin, i);
        delay(100);
    }
    
    // Decelerate
    for (int i = 255; i > 0; i--){
        Serial.println(i);
        analogWrite(motorPin, i);
        delay(100);
    }
}
