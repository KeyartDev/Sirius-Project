#pragma once

#include <RTClib.h>
#include "GlobalVars.h"
#include "Arduino.h"

class RTC_S {
public:
  String getCurrentTime();
  String getCurrentDate();
  String getCurrentDayOfTheWeek();
  void initialize();
  RTC_S();
private:
  RTC_DS1307 rtc;
  char daysOfTheWeek[7][12] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
  };
  bool isInited=false;
};
