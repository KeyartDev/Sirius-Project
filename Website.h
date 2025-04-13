#pragma once
#include <GyverPortal.h>
#include "GlobalVars.h"
#include "RTC.h"

GyverPortal ui;
RTC_S rtc;

const char *namesTH[] = {
  "temp", "humidity"
};

const char *namesP[] = {
  "pressure"
};

const char *namesWS[] = {
  "wind speed", "water speed"
};

String pageTitle = "Гидрометеорологический буй"; //Заголовок веб-страницы

void action() {
  if (ui.update()) {
     if (ui.updateName() == "lbl/0") {
       ui.answer(dataTemp);
     } else if (ui.updateName() == "lbl/1") {
       ui.answer(dataPressure);
     } else if (ui.updateName() == "lbl/2") {
       ui.answer(dataWindSpeed);
     } else if (ui.updateName() == "lbl/3") {
       ui.answer(dataHumidity);
     } else if (ui.updateName() == "lbl/4") {
       ui.answer(dataWaterSpeed);
     } else if (ui.updateName() == "lbl/5") {
       ui.answer(dataWaterPolution);
     } else if (ui.updateName() == "lbl/6") {
       ui.answer(dataAxel);
     } else if (ui.updateName() == "lbl/7") {
       ui.answer(dataGyro);
     } else if (ui.updateName() == "lbl/8") {
       ui.answer(dataCarbonDyoxide);
     } else if (ui.updateName() == "lbl/9") {
       ui.answer(dataUV);
     } else if (ui.updateName() == "lbl/10") {
       ui.answer(dataPoison);
     } else if (ui.updateName() == "lbl/11") {
       ui.answer(dataWaterMin);
     } else if (ui.updateName() == "lbl/lmh/pol") {
       ui.answer(valueLMHPolution);
     } else if (ui.updateName() == "lbl/lmh/uv") {
       ui.answer(valueLMHUV);
     } else if (ui.updateName() == "lbl/date") {
       ui.answer(rtc.getCurrentDate());
     } else if (ui.updateName() == "lbl/day") {
       ui.answer(rtc.getCurrentDayOfTheWeek());
     } else if (ui.updateName() == "lbl/time") {
       ui.answer(rtc.getCurrentTime());
     }
  } 

  if (ui.update("plot1")) {
    int answ[] = {dataTemp.toInt(), dataHumidity.toInt()};
    ui.answer(answ, 2);
  } else if (ui.update("plot2")) {
    int answ[] = {dataPressure.toInt()};
    ui.answer(answ, 1);
  } else if (ui.update("plot3")) {
    int answ[] = {dataWindSpeed.toInt(), dataWaterSpeed.toInt()};
    ui.answer(answ, 2);
  } 
}


void build() {
  rtc.initialize();
  
  GP.BUILD_BEGIN();
  GP.THEME(GP_DARK);
  GP.TITLE(pageTitle);

  String updateList;
  for (int i{0};i<12;i++) {
    updateList += "lbl/";
    updateList += i;
    updateList += ",";
  }
  updateList += "lbl/lmh/pol,lbl/lmh/uv,lbl/date,lbl/day,lbl/time";
  GP.UPDATE(updateList);

  GP.LABEL("", "lbl/date"); GP.BREAK();
  GP.LABEL("", "lbl/day"); GP.BREAK();
  GP.LABEL("", "lbl/time"); GP.BREAK();

  GP.BLOCK_BEGIN(GP_THIN, "", "Датчики", GP_GREEN_B);

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Температура: ");
  GP.LABEL_BLOCK("", "lbl/0");
  GP.LABEL(" градусов");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Давление: ");
  GP.LABEL_BLOCK("", "lbl/1");
  GP.LABEL(" Па");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Скорость ветра: ");
  GP.LABEL_BLOCK("", "lbl/2");
  GP.LABEL(" м/с");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Влажность: ");
  GP.LABEL_BLOCK("", "lbl/3");
  GP.LABEL(" %");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Скорость теч. воды: ");
  GP.LABEL_BLOCK("", "lbl/4");
  GP.LABEL(" л/мин");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Мутность воды: ");
  GP.LABEL_BLOCK("", "lbl/5");
  GP.LABEL("", "lbl/lmh/pol");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Уск. своб. падения: ");
  GP.LABEL_BLOCK("", "lbl/6");
  GP.LABEL(" м/с/с");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Наклон: ");
  GP.LABEL_BLOCK("", "lbl/7");
  GP.LABEL(" градусов");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Кол-во CO2 в воздухе: ");
  GP.LABEL_BLOCK("", "lbl/8");
  GP.LABEL(" ppm");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("УФ: ");
  GP.LABEL_BLOCK("", "lbl/9");
  GP.LABEL("", "lbl/lmh/uv");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Кислотность: ");
  GP.LABEL_BLOCK("", "lbl/10");
  GP.LABEL("pH");
  GP.BREAK();
  GP.BOX_END();

  GP.BOX_BEGIN(GP_LEFT);
  GP.LABEL("Минерализация воды: ");
  GP.LABEL_BLOCK("", "lbl/11");
  GP.LABEL("ppm");
  GP.BREAK();
  GP.BOX_END();

  GP.BLOCK_END();

  GP.BLOCK_BEGIN(GP_THIN, "", "Графики", GP_GREEN_B);
  
  GP.SPOILER_BEGIN("Температура/влажность", GP_GREEN_B);
  GP.AJAX_PLOT_DARK("plot1", namesTH, 2, 20, 1000,400,1);
  GP.SPOILER_END();
  GP.HR();

  GP.SPOILER_BEGIN("Давление", GP_GREEN_B);
  GP.AJAX_PLOT_DARK("plot2", namesP, 1, 20, 1000,400,1);
  GP.SPOILER_END();
  GP.HR();

  GP.SPOILER_BEGIN("Скорость ветра/воды", GP_GREEN_B);
  GP.AJAX_PLOT_DARK("plot3", namesWS, 2, 20, 1000,400,1);
  GP.SPOILER_END();

  GP.BLOCK_END();

  GP.BUILD_END();
}
