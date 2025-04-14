#include "Holl.h"

int counter=0;

void Holl_S::initialize() {
  attachInterrupt(digitalPinToInterrupt(HOLL_PIN), onSwitch, CHANGE);
  Serial.println("Holl successfully connected!");
}

void Holl_S::onSwitch() {
  counter++;
}

String Holl_S::getWindSpeed() {
  return "";
}

Holl_S::Holl_S() {
  pinMode(HOLL_PIN, INPUT);
}
