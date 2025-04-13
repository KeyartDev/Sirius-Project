#include "MPU-9250.h"

void MPU9250_S::initialize() {
  if(!myMPU9250.init()){
      Serial.println("MPU9250 connection error!");
    }
    else{
      Serial.println("MPU9250 calibration process started...");
    }

    Serial.println("...Position you MPU9250 flat and don't move it - calibrating...");
    delay(1000);
    myMPU9250.autoOffsets();
    Serial.println("..Done!");

    myMPU9250.enableGyrDLPF();
    myMPU9250.setGyrDLPF(MPU9250_DLPF_6);
    myMPU9250.setSampleRateDivider(5);
    myMPU9250.setGyrRange(MPU9250_GYRO_RANGE_250);
    myMPU9250.setAccRange(MPU9250_ACC_RANGE_2G);
    myMPU9250.enableAccDLPF(true);
    myMPU9250.setAccDLPF(MPU9250_DLPF_6);
    myMPU9250.setMagOpMode(AK8963_CONT_MODE_100HZ);
    delay(200);

    Serial.println("MPU9250 successfully connected!");
}

xyzFloat MPU9250_S::getGyroValues() {
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

xyzFloat MPU9250_S::getAxelValues() {
  return myMPU9250.getGValues();
}

String MPU9250_S::getMpuTemp() {
  return String(myMPU9250.getTemperature());
}

float MPU9250_S::getResultantAxel() {
  return myMPU9250.getResultantG(getAxelValues());
}

MPU9250_S::MPU9250_S() : myMPU9250(MPU_PIN) {
  pinMode(MPU_PIN, INPUT);
}
