/*#pragma once

#include <iarduino_DHT.h> 
#include "variables.h"

iarduino_DHT sensor(DHT11PIN);
// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.


String gethumidity() {
  switch (sensor.read()) {
    case DHT_OK: return String(sensor.hum); break;
    default: ERR; break;
  }
}*/

