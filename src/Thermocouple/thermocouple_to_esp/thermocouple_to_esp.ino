/***************************************************
  This is an example for the Adafruit Thermocouple Sensor w/MAX31855K

  Designed specifically to work with the Adafruit Thermocouple Sensor
  ----> https://www.adafruit.com/products/269

  These displays use SPI to communicate, 3 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <SPI.h>
#include "Adafruit_MAX31855.h"
#include<SoftwareSerial.h>
#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Float64.h>
#include <stdlib.h>

// Default connection is using software SPI, but comment and uncomment one of
// the two examples below to switch between software SPI and hardware SPI:

// Example creating a thermocouple instance with software SPI on any three
// digital IO pins.
#define MAXDO   4
#define MAXCS   5
#define MAXCLK  6

SoftwareSerial espSerial(7,8);

// initialize the Thermocouple
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);

ros::NodeHandle nh;
std_msgs::Float64 temperature;

ros::Publisher temp("temperature", &temperature);

void setup() {
  Serial.begin(115200);
  espSerial.begin(115200);
  
  while (!Serial) delay(1); // wait for Serial on Leonardo/Zero, etc

  Serial.println("MAX31855 test");
  // wait for MAX chip to stabilize
  delay(500);
  Serial.print("Initializing sensor...");
  if (!thermocouple.begin()) {
    Serial.println("ERROR.");
    while (1) delay(10);
  }
  Serial.println("DONE.");

  nh.getHardware()->setBaud(115200);
  nh.initNode();
  nh.advertise(temp);
}

void loop() {
  // basic readout test, just print the current temp
   Serial.print("Internal Temp = ");
   Serial.println(thermocouple.readInternal());

   float c = thermocouple.readCelsius();
   temperature.data = c;
   
   if (isnan(c)) {
     Serial.println("Something wrong with thermocouple!");
   } else {
     Serial.print("C = ");
     Serial.println(c);
   }
   espSerial.println(c);

   temp.publish(&temperature);
   
   nh.spinOnce();
   
   delay(33);
}
