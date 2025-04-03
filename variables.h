#pragma once
#ifndef VARIABLES_H
# define VARIABLES_H

//Макросы
#define AP_SSID "DIRECT-g9-Pantum M6550 Series"
#define AP_PASS "123456780"
#define MPU9250_ADDR 0x68
#define UV_PIN 12
#define DHT11PIN 8 
#define HOLL_PIN 3
#define YFS201_PIN 35
#define TOPA 0.00750063755419211
#define CJMCU_811_ADDRESS 0x5A
#define DATCHIK_MUTNOSTI_PIN 1
#define TdsSensorPin A0
#define VREF 5.0              
#define SCOUNT  30
#define ERR "Ошибка!"
#define LMH_LOW "Низкий"
#define LMH_MEDIUM "Средний"
#define LMH_HIGH "Высокий"

inline const char *namesTH[] = {
  "temp", "humidity"
};

inline const char *namesP[] = {
  "pressure"
};

inline const char *namesWS[] = {
  "wind speed", "water speed"
};



inline String pageTitle{"Гидрометеорологический буй"}; //Заголовок веб-страницы

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

