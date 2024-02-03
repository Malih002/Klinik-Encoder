/*
  KLEncoder.cpp - Library for receive data from encoder module.
  Created by Klinik Led, August 15, 2023.
  Released into customer.
*/
#include "Arduino.h"
#include "KLEncoder.h"

KLEncoder::KLEncoder(int sw, int cw, int ccw) {
  _sw = sw;
  _cw = cw;
  _ccw = ccw;
}

void KLEncoder::begin() {
  pinMode(_sw, INPUT);
  pinMode(_cw, INPUT);
  pinMode(_ccw, INPUT);
}


bool KLEncoder::detectSw(bool pressOrRelease) {
  if (digitalRead(_sw) == 0 && stateSw == 0) {
    stateSw = 1;
    if (pressOrRelease == _pres) {
      return 1;
    }
  }

  if (digitalRead(_sw) != 0 && stateSw != 0) {
    stateSw = 0;
    if (pressOrRelease == _rilis) {
      return 1;
    }
  }
  return 0;
};

bool KLEncoder::press() {
  bool _i = detectSw(_pres);
  return _i;
};

bool KLEncoder::release() {
  bool _i = detectSw(_rilis);
  return _i;
};

bool KLEncoder::hold() { 
  if (digitalRead(_sw) == 0) {
  return 1;
  }
  return 0;
};

bool KLEncoder::CCW() { 
  if (digitalRead(_ccw) == 1) {
    fall1 = 1;  
  } 
  if (fall1 == 1 && digitalRead(_ccw) == 0) {
    fall1 = 0; 
    return 1; 
  } 

  return 0;
}

bool KLEncoder::CW() {  
  if (digitalRead(_cw) == 1) {
    fall2 = 1;  
  } 
  if (fall2 == 1 && digitalRead(_cw) == 0) {
    fall2 = 0; 
    return 1; 
  } 

  return 0; 
};
