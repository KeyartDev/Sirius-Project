#include "DHT11.h"

void DHT11_S::initialize() {
  Serial.println("DHT11 successfully connected!");
}

String  DHT11_S::gethumidity() {
  switch (sensor.read()) {
    case DHT_OK: return String(sensor.hum); break;
    default: return "ERROR!"; break;
  }
}

DHT11_S::DHT11_S() : sensor(DHT11_PIN) {
  pinMode(DHT11_PIN, INPUT);
}
