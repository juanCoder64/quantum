#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include"movimientos.h"
float ini;
int l1 = 60;
int adelante;
float headingDegrees;
float valor;
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

void brujula(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  sensors_event_t event;
  mag.getEvent(&event);
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  float declinationAngle = 0.22;
  heading += declinationAngle;
  if (heading < 0)
    heading += 2 * PI;
  if (heading > 2 * PI)
    heading -= 2 * PI;
  headingDegrees = heading * 180 / M_PI;
}
void setup() {
  Wire.begin();
  mag.begin();
  brujula();
  ini = headingDegrees;
}

void loop() {
  Movimiento mueve(l1);
  orientar();
  if (adelante == 0) {
    if (valor < 100) {
      mueve.derecha();
      if (valor >= 30) {
        l1 = 255;
      }
      else if (valor >= 24 && valor < 30) {
        l1 = 50;
      }
      else {
        l1 = 40;
      }
    }
    else {
      mueve.izquierda();

      if (valor <= 315) {
        l1 = 255;
      }
      else if (valor <= 310 && valor > 315) {
        l1 = 50;
      }
      else {
        l1 = 40;
      }
    }
  }
  else{
    mueve.apagado();
  }
}
int frente() {
  if (valor < 10 || valor > 350) {
    return 1;
  }
  else {
    return 0;
  }
}
void orientar() {
  adelante = frente();
  Serial.print(adelante);
  Serial.print("\t");
  brujula();
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  valor = headingDegrees - ini;
  if (valor < 0) {
    valor += 360;
  }
}
