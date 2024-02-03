/*
  KLEncoder.h - Library for receive data from encoder module.
  Created by Klinik Led, August 15, 2023.
  Released into customer.
*/
#ifndef KLEncoder_h
#define KLEncoder_h

#include "Arduino.h"

class KLEncoder {
public:
  KLEncoder(int sw, int cw, int ccw);
  void begin();
  bool CCW();
  bool CW();
  bool press();
  bool release();
  bool hold();
private:
  bool detectSw(bool pressOrRelease);
  enum {
    _rilis,
    _pres
  };
   bool stateSw = 0;
   bool stateSw2 = 0;
   bool dir = 0;
   bool dir2 = 0;
   bool fall1 = 0;
   bool fall2 = 0;
  int _sw;
  int _cw;
  int _ccw;
};

#endif