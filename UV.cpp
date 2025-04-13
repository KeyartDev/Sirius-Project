#include "UV.h"

void UV_S::initialize() {
  Serial.println("UV successfullu connected!");
}

String UV_S::getUV() {
  uv = analogRead(UV_PIN);
  return String(uv);
}

String UV_S::getLMHUV() {
  if (uv >= 0 && uv <= 1360) {
    return "Низкий";
  } else if (uv > 1360 && uv <= 2720) {
    return "Средний";
  } else if (uv > 2720) {
    return "Высокий";
  } else {
    return "Ошибка!";
  }
}

UV_S::UV_S() {
  pinMode(UV_PIN, INPUT);
}
