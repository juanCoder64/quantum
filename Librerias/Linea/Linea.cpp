#include "Arduino.h"
#include "Linea.h"
Linea::Linea(int centro,int medio,int exterior,int ledpin){
pinMode(centro,OUTPUT);
pinMode(medio,OUTPUT);
pinMode(exterior,OUTPUT);
digitalWrite(ledpin,LOW);	
}
void Linea::calibrarV(){
	digitalWrite(ledpin,HIGH);
  a = analogRead(centro);
  b = analogRead(medio);
  c = analogRead(exterior);
  digitalWrite(ledpin,LOW);
  }
 void Linea::calibrarB(){
 digitalWrite(ledpin,HIGH);
  Ca = analogRead(centro);
  Cb = analogRead(medio);
  Cc = analogRead(exterior);
  Cc += c;
  Cb += b;
  Ca += a;
  Cc /= 2;
  Cb /= 2;
  Ca /= 2;
  digitalWrite(ledpin,LOW);
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
