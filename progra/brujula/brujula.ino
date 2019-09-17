#include <movimientos.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
int vuelta = 180;
float ini;
int l1;
Movimiento mueve(l1);
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

  Serial.begin(9600);
  Wire.begin();
  mag.begin();
  brujula();
  ini = headingDegrees;
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  Serial.print("\t");
  Serial.println(l1);
  Movimiento mueve(l1);
  orientar();
  if (frente() == 0) {
    if (valor < vuelta) {
      l1 = map(valor, 10, vuelta, 30, 255);
      mueve.derecha();
    }
    else {
      l1 = map(valor, vuelta, 350, 255, 30);
      mueve.izquierda();
    }
  }
  else {
    mueve.apagado();
  }
  //Serial.print("\t");
  //Serial.print(valor);

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
  //Serial.print(frente());
  //Serial.print("\t");
  brujula();
  //Serial.print("Heading (degrees): "); //Serial.println(headingDegrees);
  valor = headingDegrees - ini;
  if (valor < 0) {
    valor += 360;
  }
}
