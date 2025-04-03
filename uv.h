#pragma once

#include "variables.h"

int getUV() {
  auto datasUV = analogRead(UV_PIN);
  Serial.print("UV: "); Serial.println(datasUV);
  if (datasUV >= 0 && datasUV <= 100) {
    valueLMHUV = LMH_LOW;
  } else if (datasUV > 100 && datasUV <= 500) {
    valueLMHUV = LMH_MEDIUM;
  } else if (datasUV > 500) {
    valueLMHUV = LMH_HIGH;
  } else {
    valueLMHUV = ERR;
  }
  return datasUV;
}

namespace uv {
  void init() {
    Serial.println("UV is connected!");
    delay(200);
  }
}

