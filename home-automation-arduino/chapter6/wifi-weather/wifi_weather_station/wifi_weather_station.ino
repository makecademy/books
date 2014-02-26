/* 
*  Simple WiFi weather station with Arduino, the DHT11 sensor & the CC3000 chip
*  Part of the code is based on the work done by Adafruit on the CC3000 chip & the DHT11 sensor
*  Writtent by Marco Schwartz for Open Home Automation
*/

// Include required libraries
#include <ccspi.h>
#include <SPI.h>
#include "DHT.h"
#include "iot2.h"

// WiFi network (change with your settings !)
#define WLAN_SSID       "marco"        
#define WLAN_PASS       "beyond08"
#define WLAN_SECURITY   WLAN_SEC_WPA2 // This can be WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA or WLAN_SEC_WPA2

// Server port & IP
#define SERVER_PORT_TCP 80
#define SERVER_FOLDER "/simple-weather-station/"
#define IP1 192
#define IP2 168
#define IP3 0
#define IP4 1

// Define CC3000 chip pins
hardwarePins pins = {8, 2, A3};

// DHT11 sensor pins
#define DHTPIN 7 
#define DHTTYPE DHT11

// Create CC3000 & DHT instances
// DHT dht(DHTPIN, DHTTYPE);

// Create IoT module
Module module = Module(pins); 

void setup(void)
{
 
  // Initialize DHT sensor
  //dht.begin();
  
  Serial.begin(115200);
    
  // Initialise & connect the CC3000 module
  module.cc3000_init();
  module.cc3000_connect(WLAN_SSID, WLAN_PASS, WLAN_SECURITY);

}

void loop(void)
{

    // Measure the humidity & temperature
    //float h = dht.readHumidity();
    //float t = dht.readTemperature();
     
    // Transform to String
    //String temperature = String((int) t);
    //String humidity = String((int) h);
    
    String temperature = "34.0";
    String humidity = "41.0";
    
    // Print data
    Serial.print("Temperature: ");
    Serial.println(temperature);
    Serial.print("Humidity: ");
    Serial.println(humidity);
    Serial.println("");
    
    // Send request
    String request = "GET "+ String(SERVER_FOLDER) + "sensor.php?temp=" + temperature + "&hum=" + humidity + " HTTP/1.0";
    String result = module.send_request_tcp(request, 80);
    
    // Update every second
    delay(1000);
}
