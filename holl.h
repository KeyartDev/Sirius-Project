#include "variables.h"

int counter = 0;

//ФОРМУЛА РАСЧЁТА СКОРОСТИ ОТСУТСТВУЕТ


//Выполняемый код:
void onSwitch() {
  counter++;
}

namespace holl {
  void init() {
    attachInterrupt(digitalPinToInterrupt(HOLL_PIN), onSwitch, CHANGE);
  }
}

