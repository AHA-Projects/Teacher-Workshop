// Importing Wire.h, it helps in communicating with I2C devices
// What is I2C?
// I@C is a communication protocol that allows a microcontroller to communicate with multiple peripherals, such as sensors or displays.
#include <Wire.h>

// Importing Sensor Libraries - Light Sensor
#include "Adafruit_APDS9960.h"

// Instantiating our sensor object
Adafruit_APDS9960 apds;

// Initializing all the sensor outputs variables
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

 
void setup() {
  
  // Start the Serial Monitor (for printing results on the computer)
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("AdaFruit APDS-9960 - LightSensor"));
  Serial.println(F("--------------------------------"));
  

  // Start the light sensor

  if(!apds.begin()){
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  // Turn on the color sensing mode
  apds.enableColor(true);
  
  // Wait for the sensor to get ready
  delay(500);
}

void loop() {

  uint16_t red_light, green_light, blue_light, ambientLight;
  
  // Wait until the sensor has color data ready
  while(!apds.colorDataReady()){
    delay(5);
  }

  // Read color data from the sensor
  apds.getColorData(&red_light, &green_light, &blue_light, &ambientLight);
  
  // Print the values

  Serial.print("Ambient: ");
  Serial.print(ambientLight);

  Serial.print(" Red: ");
  float R = (255.*red_light/ambientLight);
  Serial.print(R);
  
  Serial.print(" Green: ");
  float G = (255.*green_light/ambientLight);
  Serial.print(G);
  
  Serial.print(" Blue: ");
  float B = (255.*blue_light/ambientLight);
  Serial.println(B);
  
  // Wait 1 second before next reading
  delay(100);
  

}
