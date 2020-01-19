#include "Arduino.h"
#include "Linea.h"
Linea::Linea(int centro,int medio,int exterior){
pinMode(centro,OUTPUT);
pinMode(medio,OUTPUT);
pinMode(exterior,OUTPUT);
}
void Linea::calibrar(){
	Serial.println("poner en color verde");
  delay(1000);
  a = analogRead(centro);
  b = analogRead(medio);
  c = analogRead(exterior);
  Serial.println("poner en color blanco");
  delay(1000);
  Ca = analogRead(centro);
  Cb = analogRead(medio);
  Cc = analogRead(exterior);
  Cc += c;
  Cb += b;
  Ca += a;
  Cc /= 2;
  Cb /= 2;
  Ca /= 2;
}

int Linea::lectura(){
  a = analogRead(centro);
  b = analogRead(medio);
  c = analogRead(exterior);
  if (a >= Ca) {
  	return 3;
  }
  if (b >= Cb) {
  	return 2;
  }
  if (c >= Cc) {
  	return 1;
  }
  if(c <= Cc && b >= Cb && a >= Ca){
  	return 0;
  }
}
