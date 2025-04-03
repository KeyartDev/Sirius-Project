#pragma once
/*
#include <MPU9250_WE.h>
#include <Wire.h>
#include "variables.h"

MPU9250_WE myMPU9250 = MPU9250_WE(MPU9250_ADDR);
  
xyzFloat getGyroValues() {
  float dataX=0;
  float dataY=0;
  float dataZ=0;
  for (int x=0;x<10;x++) {
    xyzFloat mpuData = myMPU9250.getGyrValues();
    dataX+=mpuData.x;
    dataY+=mpuData.y;
    dataZ+=mpuData.z;
  }

  float finalDataX = dataX/10;
  float finalDataY = dataY/10;
  float finalDataZ = dataZ/10;

  xyzFloat returnValue = xyzFloat(finalDataX, finalDataY, finalDataZ);
  
  return returnValue;
}

xyzFloat getAxelValues() {
  return myMPU9250.getGValues();
}

xyzFloat getMagnValues() {
  return myMPU9250.getMagValues();
}

String getTempFromMPU() {
  return String(myMPU9250.getTemperature());
}

float getResultantAxel() {
  return myMPU9250.getResultantG(getAxelValues());
}

namespace mpu9250 {
  void init() {
    if(!myMPU9250.init()){
      Serial.println("MPU9250 does not respond");
    }
    else{
      Serial.println("MPU9250 is connected");
    }
    if(!myMPU9250.initMagnetometer()){
      Serial.println("Magnetometer does not respond");
    }
    else{
      Serial.println("Magnetometer is connected");
    }

    Serial.println("Position you MPU9250 flat and don't move it - calibrating...");
    delay(1000);
    myMPU9250.autoOffsets();
    Serial.println("Done!");

    myMPU9250.enableGyrDLPF();
    myMPU9250.setGyrDLPF(MPU9250_DLPF_6);
    myMPU9250.setSampleRateDivider(5);
    myMPU9250.setGyrRange(MPU9250_GYRO_RANGE_250);
    myMPU9250.setAccRange(MPU9250_ACC_RANGE_2G);
    myMPU9250.enableAccDLPF(true);
    myMPU9250.setAccDLPF(MPU9250_DLPF_6);
    myMPU9250.setMagOpMode(AK8963_CONT_MODE_100HZ);
    delay(200);

    Serial.println("MPU-9250 init process is done!");
  }
}*/

