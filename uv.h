#pragma once

#include "GlobalVars.h"
#include "Arduino.h"

class UV_S {
public:
  void initialize();
  String getUV();
  String getLMHUV();
  UV_S();
private:
  int uv = 0;
};
