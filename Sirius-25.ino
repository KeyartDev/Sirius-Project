#include <LittleFS.h>
#include <Wire.h>

#include "BMP180.h"
#include "CJMCU-811.h"
#include "DHT11.h"
#include "HMC58831.h"
#include "MPU-9250.h"
#include "TDS.h"
#include "UV.h"
#include "20240415.h"
#include "Holl.h"
#include "PH.h"
#include "YF-S201C.h"
#include "Website.h"
#include "GlobalVars.h"

#define AP_SSID "DIRECT-g9-Pantum M6550 Series"
#define AP_PASS "123456780"

BMP_S bmp;
CJMCU811_S cjmcu;
DHT11_S dht;
HMC58831L_S hmc58831;
MPU9250_S mpu;
TDS_S tds;
UV_S uv;
DM_S dm;
Holl_S holl;
PH_S ph;
YFS201C_S yfs;

void setup() {
  Serial.begin(115200);
  setupWebsite();
  //analogReference(EXTERNAL); //НЕ РАБОТАЕТ НА ESP!
  Wire.begin();

  //init
  bmp.initialize();
  cjmcu.initialize();
  dht.initialize();
  hmc58831.initialize();
  mpu.initialize();
  tds.initialize();
  uv.initialize();
  dm.initialize();
  holl.initialize();
  ph.initialize();
}

void loop() {
  dataTemp = mpu.getMpuTemp(); //Температура
  dataPressure = bmp.getBmpPressure(); //Давление
  dataWindSpeed = holl.getWindSpeed(); //Скорость ветра
  dataHumidity = dht.gethumidity(); //Влажность воздуха
  dataWaterSpeed = yfs.getWaterSpeed(); //Расход воды
  dataWaterPolution = dm.getTurbidity(); //Мутность воды
  dataAxel = "0"; //Данные акселерометра
  dataGyro = "0"; //Данные гироскопа
  dataCarbonDyoxide = cjmcu.getCarbonDyoxide(); //CO2 в воздухе
  dataUV = uv.getUV(); //Датчик УФ
  dataPoison = ph.getPH(); //Кислотность
  dataWaterMin = tds.getTDSData(); //Минерализация

  valueLMHPolution = "???";
  valueLMHUV = uv.getLMHUV();
  
  ui.tick();
}

void setupWebsite() {
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
