#include <Wire.h> //I2C Arduino Library
int angulo;
int a;
#define addr 0x1E //I2C Address for The HMC5883

void setup(){
  
  Serial.begin(9600);
  Wire.begin();
  
  
  Wire.beginTransmission(addr); //start talking
  Wire.write(0x02); // Set the Register
  Wire.write(0x00); // Tell the HMC5883 to Continuously Measure
  Wire.endTransmission();
}


void loop(){
  
  int x,y,z; //triple axis data

  //Tell the HMC what regist to begin writing data into
  Wire.beginTransmission(addr);
  Wire.write(0x03); //start with register 3.
  Wire.endTransmission();
  
 
 //Read the data.. 2 bytes for each axis.. 6 total bytes
  Wire.requestFrom(addr, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //MSB  x 
    x |= Wire.read(); //LSB  x
    z = Wire.read()<<8; //MSB  z
    z |= Wire.read(); //LSB z
    y = Wire.read()<<8; //MSB y
    y |= Wire.read(); //LSB y
  }
  
  // Show Values
  angulo=x;
  a=es_frente();
Serial.print("angulo: ");
Serial.print(angulo);
Serial.print("  ");
  Serial.println(a);
 

  
  delay(100);
}
void compi(){
  
}
int es_frente(){
if(angulo<10 || angulo>350){
  return 1;
}
  else{
    return 0;
  }
}

