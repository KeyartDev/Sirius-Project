#pragma once
#ifndef VARIABLES_H
# define VARIABLES_H

#include "Arduino.h"

#define MPU9250_ADDR 0x68
#define UV_PIN 12
#define DHT11_PIN 8 
#define HOLL_PIN 3
#define YFS201C_PIN 0
#define CJMCU811_ADDRESS 0x5A
#define CJMCU811_PIN 0
#define DM_PIN 1
#define TDS_PIN A0
#define BMP180_PIN 0
#define HMC58831L_PIN 0
#define PH_PIN 0
#define RTC_PIN 0


const int MPU_PIN = 0;

//Переменные, в которые необходимо записать данные с датчиков:
inline String dataTemp{"???"}; //Температура
inline String dataPressure{"???"}; //Давление
inline String dataWindSpeed{"???"}; //Скорость ветра
inline String dataHumidity{"???"}; //Влажность воздуха
inline String dataWaterSpeed{"???"}; //Расход воды
inline String dataWaterPolution{"???"}; //Мутность воды
inline String dataAxel{"???"}; //Данные акселерометра
inline String dataGyro{"???"}; //Данные гироскопа
inline String dataCarbonDyoxide{"???"}; //CO2 в воздухе
inline String dataUV{"???"}; //Датчик УФ
inline String dataPoison{"???"}; //Кислотность
inline String dataWaterMin{"???"}; //Минерализация

inline String valueLMHPolution{"Неизвестно"};
inline String valueLMHUV{"Неизвестно"};
#endif
