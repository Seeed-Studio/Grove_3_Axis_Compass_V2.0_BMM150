#include <Arduino.h>
#include "bmm150.h"
#include <Wire.h>

BMM150 bmm = BMM150();

void setup()
{
  Serial.begin(9600);

  if(bmm.initialize() == BMM150_E_ID_NOT_CONFORM) {
    Serial.println("Chip ID can not read!");
    while(1);
  } else {
    Serial.println("Initialize done!");
  }
}

void loop()
{
  bmm.read_mag_data();

  Serial.print("Raw Data:         ");
  Serial.print(bmm.raw_mag_data.raw_datax);
  Serial.print(" ");
  Serial.print(bmm.raw_mag_data.raw_datay);
  Serial.print(" ");
  Serial.print(bmm.raw_mag_data.raw_dataz);
  Serial.print(" ");
  // Serial.println(bmm.raw_mag_data.raw_data_r);
  
  Serial.print("Compensated Data: ");
  Serial.print(bmm.mag_data.x);
  Serial.print(" ");
  Serial.print(bmm.mag_data.y);
  Serial.print(" ");
  Serial.println(bmm.mag_data.z);
  Serial.println();

  delay(100);
}