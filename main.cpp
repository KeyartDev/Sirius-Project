#include <LittleFS.h>
#include <Wire.h>

#include "variables.h"
#include "MPU-9250.h"
#include "UV.h"
#include "BMP-180.h"
#include "DHT11.h"
#include "web.h"
#include "CJMCU-811.h"
#include "TDS.h"
#include "datchik_mutnosti.h"
#include "DS18B20.h"
#include "ph.h"
#include "holl.h"
#include "YF-S201.h"


void setup() {
  Serial.begin(115200);
  //analogReference(EXTERNAL); //НЕ РАБОТАЕТ НА ESP!
  Wire.begin();
  //mpu9250::init();
  uv::init();
  bmp180::init();
  cjmcu811::init();
  tds::init();
  holl::init();
  yfs201::init();
  
  
  WiFi.softAP(AP_SSID, AP_PASS);
   
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  ui.attachBuild(build);
  ui.attach(action);
  ui.start();

  ui.uploadAuto(true);
  ui.downloadAuto(true);
  ui.start();
    if (!LittleFS.begin(true)) {
    Serial.println("FS Error"); 
  }
  ui.setFS(&LittleFS);

}

void loop() {
  //xyzFloat gyr = getGyroValues();

  //Serial.print("Temp: "); Serial.println(getT());
  
  //Временная альтернатива данным с датчиков:
  //dataTemp = getTempFromMPU(); 
  dataPressure = getBMPPressure();
  dataWindSpeed = String(random(20, 25));
  //dataHumidity = gethumidity();
  dataCarbonDyoxide = getCarbonDyoxide();
  dataWaterPolution = getTurbidity();
  //dataAxel = String(getResultantAxel());
  //dataGyro = String(gyr.x) + " " + String(gyr.y) + " " + String(gyr.z);
  dataWaterSpeed = getWaterSpeed();
  dataUV = String(getUV());
  dataPoison = getPH();
  dataWaterMin = getTDSData();
  
  ui.tick();
}

