// Input
int input;

const int NB_OF_VALUES = 3;
int valuesIndex = 0;
int values[NB_OF_VALUES];

// LED state and speed
int redState;
int blueState;
int greenState;

// LED pins
int redPin = 10;
int greenPin = 11;
int bluePin = 12;

// Setup of the board
void setup() {                
  // Initialize pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize serial port
  Serial.begin(9600);
  
  // Initialize LED state
  redState = 255;
  blueState = 255;
  greenState = 255;
  
}

// Main loop
void loop() {
  
  if (Serial.available())
  {
    if (Serial.read() == 'H')
    {
      for(valuesIndex = 0; valuesIndex < NB_OF_VALUES; valuesIndex++)
     {
       values[valuesIndex] = Serial.parseInt();
     }
     
     redState = values[0];
     blueState = values[2];
     greenState = values[1];
   
    valuesIndex = 0; 
    }
  }
  
  setRGB(redState,greenState,blueState);
   
}

// Function to set RGB color
void setRGB(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

