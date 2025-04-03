#include "RTC.h"

void Time::initialize() {
  if (!isInited) {
    rtc.begin();
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    isInited=true;
  } else {
    //Pass
  }
  
}

String Time::getCurrentTime() {
  String currentTime;
  DateTime nows = rtc.now();

  currentTime+=String(nows.hour());
  currentTime+=":";
  currentTime+=String(nows.minute());
  currentTime+=":";
  currentTime+=String(nows.second());

  return currentTime;
}

String Time::getCurrentDate() {
  String currenrDate;
  DateTime nows = rtc.now();

  currenrDate+=String(nows.day());
  currenrDate+="/";
  currenrDate+=String(nows.month());
  currenrDate+="/";
  currenrDate+=String(nows.year());

  return currenrDate;
}

String Time::getCurrentDayOfTheWeek() {
  DateTime nows = rtc.now();

  return String(daysOfTheWeek[nows.dayOfTheWeek()]);
}

