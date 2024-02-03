/*
  ---Exampel for all function---
  Created by Klinik Led
*/
 

#include "KLEncoder.h"

#define sw_pin D6
#define cw_pin D5
#define ccw_pin D0

KLEncoder enkoder(sw_pin, cw_pin, ccw_pin);

void setup() {
  Serial.begin(9600);
  enkoder.begin();
}

void loop() {
  //for button , choose one between press and release

  // if(enkoder.press()){   //when button Pressed
  // Serial.println("press");
  // }

  if (enkoder.release()) {  //when button Released
    Serial.println("release");
  }


  if (enkoder.CW()) {  //when turn ClockWise
    Serial.println("CW");
  }
  if (enkoder.CCW()) {  //when turn Counter ClockWise
    Serial.println("CCW");
  }
}
