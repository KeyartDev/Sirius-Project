#include "RTC.h"

void RTC_S::initialize() {
  if (!isInited) {
    rtc.begin();
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    isInited=true;
    Serial.println("...RTC successfully connected!...");
  } else {
    Serial.println("...RTC connection error!...");
  }
  
}

String RTC_S::getCurrentTime() {
  String currentTime;
  DateTime nows = rtc.now();

  currentTime+=String(nows.hour());
  currentTime+=":";
  currentTime+=String(nows.minute());
  currentTime+=":";
  currentTime+=String(nows.second());

  return currentTime;
}

String RTC_S::getCurrentDate() {
  String currenrDate;
  DateTime nows = rtc.now();

  currenrDate+=String(nows.day());
  currenrDate+="/";
  currenrDate+=String(nows.month());
  currenrDate+="/";
  currenrDate+=String(nows.year());

  return currenrDate;
}

String RTC_S::getCurrentDayOfTheWeek() {
  DateTime nows = rtc.now();

  return String(daysOfTheWeek[nows.dayOfTheWeek()]);
}

RTC_S::RTC_S() {
  pinMode(RTC_PIN, INPUT);
}
