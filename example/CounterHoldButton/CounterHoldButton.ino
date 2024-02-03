/*
  ---Exampel for Counter while holding button & dynamic delay---
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

  int value = 0;

  while (enkoder.hold()) {  //when button holded

    value++;

    const uint16_t firstDelay = 300;
    int delayVal = firstDelay - (value * 20);
    if (delayVal < 50) { delayVal = 50; }
    delay(delayVal);
    Serial.println(value);
  }
  
}