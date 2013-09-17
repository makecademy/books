// Variables declaration
int received_value = 0;

// State of the device to control
int device_state;

// LED pin
int led = 9;

// Setup of the board
void setup() {
    // Initialize pins
    pinMode(led, OUTPUT);
    
    // Initialize serial port
    Serial.begin(9600);
    
    // Initialize led state
    device_state = 0;
    
}

// Main loop
void loop() {
    
    if (Serial.available())
    {
        if (Serial.read() == 'H')
        {
            received_value = Serial.parseInt();
            device_state = received_value;
        }
    }
    
    digitalWrite(led,device_state);
    
}

