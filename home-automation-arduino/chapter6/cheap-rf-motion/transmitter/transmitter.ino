// Include VirtualWire library
#include <VirtualWire.h>

// Define pins
const int led_pin = 13;
const int transmit_pin = 12;
const int sensor_pin = 7;

int sensor_value;

void setup()
{
    // Init
    vw_set_tx_pin(transmit_pin);
    vw_setup(2000); // Transmission rate
    pinMode(led_pin, OUTPUT);
    pinMode(sensor_pin,INPUT);
}

void loop()
{
    // Get sensor value
    sensor_value = digitalRead(sensor_pin);
    
    // Init message
    char msg[3] = {'o','f','f'};
    
    // Change message if motion is detected
    if (sensor_value == 1){
        msg[0] = 'o';
        msg[1] = 'n';
        msg[2] = '#';
    }
    
    // Transmit data every second
    digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
    vw_send((uint8_t *)msg, 3);
    vw_wait_tx(); // Wait until the whole message is gone
    digitalWrite(led_pin, LOW);
    delay(1000);
}
