// Example for an i2c connector to communicate with ulnoiot-node via i2c
//
// Author: ulno (http://ulno.net)
// Created: 2017-10-20
//


#include <UlnoiotI2c.h>
#include "HX711.h"


void myreceive( char *msg, int len ) {
    Serial.print("Received a message of length: ");
    Serial.println(len);
    Serial.print("Message:");
    Serial.println(msg); // is properly 0 terminated - but len can used to
}

UlnoiotI2c ui2c(1000,myreceive);
HX711 scale;

void setup() {
  Serial.begin(115200); // start serial for debug output
  Serial.println("Starting.");

  scale.begin(9,10);
  scale.set_scale(440.f);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
  
}

int counter = 0;
int weight = 0;

void loop() {
  Serial.print("one reading:\t");
  weight = scale.get_units();
  Serial.print(weight, 1);
  Serial.print("\t| average:\t");
  Serial.println(scale.get_units(10), 1);

  scale.power_down();              // put the ADC in sleep mode
  
  char mystr[20];
  ui2c.suspend(100);
  snprintf(mystr, 19, "%d", weight);
  ui2c.write(mystr);
  Serial.println(mystr);
  delay(1000);
  counter += 1;
  scale.power_up();
}
