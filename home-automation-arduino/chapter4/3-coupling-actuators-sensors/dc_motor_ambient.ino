// Pins
int motorPinPlus = 4;
int motorPinMinus = 5;
int motorPinEnable = 6;
int sensorPin = 0;

// Tresholds and curtains state
int lowThresh = 100;
int highThresh = 200;
boolean curtainsUp = false;

// Setup
void setup()
{
    pinMode(motorPinPlus, OUTPUT);
    pinMode(motorPinMinus, OUTPUT);
    pinMode(motorPinEnable, OUTPUT);
    Serial.begin(9600);
}

// Loop
void loop()
{
    // Get ambient light level
    int sensorState = analogRead(sensorPin);
    
    // If there is light and the curtains are up, set them down
    if (sensorState > highThresh && curtainsUp == true) {
        setMotor(true, 255);
        delay(2000);
        curtainsUp = false;
        setMotor(true, 0);
    }
    
    // If the light is low and the curtains are down, set them up
    if (sensorState < lowThresh && curtainsUp == false) {
        setMotor(false, 255);
        delay(2000);
        curtainsUp = true;
        setMotor(false, 0);
    }
    
}

// Function to control the motor
void setMotor(boolean forward, int speed){
    digitalWrite(motorPinPlus, forward);
    digitalWrite(motorPinMinus, !forward);
    analogWrite(motorPinEnable, speed);
}
