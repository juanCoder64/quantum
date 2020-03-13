#include "Arduino.h"
#include "librerias.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Movimiento.h>
#include <Linea.h>
Adafruit_BNO055 osas = Adafruit_BNO055(55, 0x28);
Adafruit_SSD1306 oled(128, 64, &Wire, 4);
Movimiento mueve(0, 0, 0); //los valore son P,I,D
Linea frente(A0, A1, A2, 48);
Linea izq(A3, A4, A5, 49);
Linea der(A6, A7, A8, 50);
Linea abajo(A9, A10, A11, 51);
library::library(){
  
}
void library::begin() {
  Serial.begin(9600);
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  osas.begin();
  oled.clearDisplay();
}
void library::brujula() {
  sensors_event_t orientationData , linearAccelData;
  osas.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  valor = orientationData.orientation.x;
}
void library::display(int T, int X, int Y, String val) {
  oled.setTextSize(T);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(X, Y);
  oled.print(val);
}
void library::imprime() {
  oled.display();
}
void library::borra() {
  oled.clearDisplay();
}
void library::grado(int grado, int velocidad) {
  mueve.muevete(grado, velocidad, valor);
}
void library::freno() {
  mueve.recio();
}
void library::orientar(float val) {
  mueve.rota(val);
}
int library::getLinea(int numero) {
  if (numero == 2) {
    return der.lectura();
  }
  else if (numero == 1) {
    return izq.lectura();
  }
  else if (numero == 0) {
    return abajo.lectura();
  }
  else if (numero == 3) {
    return frente.lectura();
  }
}
void library::calibrate() {
  pinMode(45,INPUT);
oled.clearDisplay();
  oled.setTextSize(2);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 0);
  oled.print("verde");
  oled.display();
int boton = digitalRead(45);
  while (boton == 0) {
    boton = digitalRead(45);
  }
  boton = digitalRead(45);
  frente.calibrarV();
  izq.calibrarV();
  der.calibrarV();
  abajo.calibrarV();
  oled.clearDisplay();
oled.print("laterales");
  oled.display();

  while (boton == 0) {
    boton = digitalRead(45);
  }
  delay(1000);
  boton = digitalRead(45);

  izq.calibrarB();
  der.calibrarB();
  oled.clearDisplay();
oled.print("frente");
  oled.display();
  while (boton == 0) {
    boton = digitalRead(45);
  }
  delay(1000);
  frente.calibrarB();
  abajo.calibrarB();
}
