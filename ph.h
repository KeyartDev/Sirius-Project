#include <Wire.h>
float calibration_value = 21.34+10.68;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp,analogData;


String getPH() { 
 analogData=analogRead(A0);
 delay(30);
 
 avgval=0;
 for(int i=2;i<8;i++)
 avgval=analogData;
 float volt=(float)avgval*5.0/1024/6;
 float ph_act = -5.70 * volt + calibration_value;

 return String(ph_act);
}

