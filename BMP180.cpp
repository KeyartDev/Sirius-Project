#include "BMP180.h"

String BMP_S::getBmpPressure() {
  if (bmp.read(2)) {
    return bmp.pressure == 0 ? String(bmp.pressure) : "ERROR!";
  } else {
    return "ERROR!";
  }
}

void BMP_S::initialize() {
  bmp.begin(&Wire);
  Serial.println("BMP-180 successfully connected!");
}

BMP_S::BMP_S() {
  pinMode(BMP180_PIN, INPUT);
}
