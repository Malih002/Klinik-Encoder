/*
  ---Exampel counter with rotary encoder---
  Created by Klinik Led
*/


#include "KLEncoder.h"

#define sw_pin D6
#define cw_pin D5
#define ccw_pin D0

KLEncoder enkoder(sw_pin, cw_pin, ccw_pin);

int value = 0;

void setup() {
  Serial.begin(9600);
  enkoder.begin();
}

void loop() {

  if (enkoder.CW()) {  //when turn ClockWise
    value++;
    Serial.println(value);
  }
  if (enkoder.CCW()) {  //when turn Counter ClockWise
    value--;
    Serial.println(value);
  }
  
}
