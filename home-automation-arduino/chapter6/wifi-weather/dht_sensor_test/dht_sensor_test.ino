/* 
*  Test for the DHT11 sensor
*  Part of the code is based on the work done by Adafruit for the DHT11 sensor
*  Writtent by Marco Schwartz for Open Home Automation
*/

// Include required libraries
#include <SPI.h>
#include <string.h>
#include "DHT.h"

// DHT instance
DHT dht;

void setup(void)
{
 
  // Initialize DHT sensor
  dht.setup(4);
  
  Serial.begin(9600);
    
}
  
void loop(void)
{
  
    delay(dht.getMinimumSamplingPeriod());
  
    // Measure the humidity & temperature
    float h = dht.getHumidity();
    float t = dht.getTemperature();
   
    // Transform to String
    String temp = String((int) t);
    String hum = String((int) h);
    
    Serial.print("Temperature: ");
    Serial.println(temp);
    Serial.print("Humidity: ");
    Serial.println(hum);
    Serial.println("");
    
    delay(2000);
  
}
