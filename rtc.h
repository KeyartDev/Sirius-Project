#pragma once
#include <RTClib.h>

class Time {
public:
  String getCurrentTime();
  String getCurrentDate();
  String getCurrentDayOfTheWeek();
  void initialize();
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

