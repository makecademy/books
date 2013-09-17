int motorPinPlus = 4;
int motorPinMinus = 5;
int motorPinEnable = 6;

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
    
    // Accelerate forward
    for (int i = 100; i < 250; i++){
        setMotor(true, i);
        delay(10);
    }
    
    // Decelerate forward
    for (int i = 255; i > 100; i--){
        setMotor(true, i);
        delay(10);
    }
    
    // Accelerate reverse
    for (int i = 100; i < 250; i++){
        setMotor(false, i);
        delay(10);
    }
    
    // Decelerate reverse
    for (int i = 255; i > 100; i--){
        setMotor(false, i);
        delay(10);
    }
}

// Function to control the motor
void setMotor(boolean forward, int speed){
    digitalWrite(motorPinPlus, forward);
    digitalWrite(motorPinMinus, !forward);
    analogWrite(motorPinEnable, speed);
}
