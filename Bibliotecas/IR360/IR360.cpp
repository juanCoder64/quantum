 #include "Arduino.h"
#include "IR360.h"
#include <Wire.h>
IR360::IR360(int){
  Wire.begin();   
  }
  int IR360::posicion(){
  Wire.beginTransmission(0x0E);
  Wire.write(0x06);
  Wire.endTransmission();
  Wire.requestFrom(0x0E, 1);    // request 6 bytes from slave device #8
  while (Wire.available() > 0) // slave may send less than requested
     L = Wire.read(); // receive a byte as character
    L=L*5;        
  return L;
  }
  int IR360::intensidad(){
  Wire.beginTransmission(0x0E);
  Wire.write(0x07);
  Wire.endTransmission();
  Wire.requestFrom(0x0E, 1);    // request 6 bytes from slave device #8
  while (Wire.available() > 0)  // slave may send less than requested
     I = Wire.read(); // receive a byte as character 
   return I;
  }
  