#include <Movimiento.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
float vuelta = 180;
float ini;
int l1;
Movimiento mueve(0);
int adelante;
float headingDegrees;
float valor;
Adafruit_BNO055 osas = Adafruit_BNO055(55, 0x28);
void brujula(){
  
  sensors_event_t orientationData , linearAccelData;
  osas.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
    valor=orientationData.orientation.x; 
}
void setup() {
  Serial.begin(9600);
  Wire.begin();

osas.begin();

}

void loop() {
  brujula();
  Movimiento mueve(l1);
  if (frente() == 0) {
    if (valor < vuelta) {
      l1 = map(valor, 10, vuelta, 30, 255);
      mueve.rota(l1,0);
    }
    else {
      l1 = map(valor, vuelta, 350, 255, 30);
      mueve.rota(l1,1);
    }
  }
else {
    mueve.muevete(0,0);
 }
  Serial.print("\t");
  Serial.println(valor);

}
int frente() {
  if (valor < 10 || valor > 350) {
    return 1;
  }
  else {
    return 0;
  }
}
