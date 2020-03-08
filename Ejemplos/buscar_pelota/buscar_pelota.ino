#include <IR360.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <HTInfraredSeeker.h>
#include <Movimiento.h>
unsigned long tardanza = 0;
//objetos para cada cosa
Adafruit_BNO055 osas = Adafruit_BNO055(55, 0x28);
Adafruit_SSD1306 oled(128, 64, &Wire, 4);
Movimiento mueve(0, 0, 0); //los valore son P,I,D
IR360 ir360(1);
float valor;
void brujula() {
  sensors_event_t orientationData , linearAccelData;
  osas.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  valor = orientationData.orientation.x;
}
void setup() {
  Serial.begin(9600);
  InfraredSeeker::Initialize(); //initializes the IR sensor
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() {
  brujula();
  tardanza = millis();
  oled.clearDisplay();
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);
  oled.print("lego");
  oled.setCursor(90, 0);
  oled.print("360");
  oled.setTextSize(1);
  oled.setCursor(20, 30);
  if (ir360.posicion() == 1275) {
    oled.print(InfraredBall.Direction);
    Lego();
  }
  else {
    oled.setCursor(70, 30);
    oled.print(ir360.posicion());
    mueve.muevete(ir360.posicion(), 255, valor);
  }
  tardanza = millis() - tardanza;
  oled.setCursor(30, 40);
  oled.print("milis por ciclo");
  oled.setCursor(70, 50);
  oled.print(tardanza);
  oled.display();
}
void Lego() {
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  int a = 0;
  int muestras = 10;
  for (int i = 0 ; i < muestras; i++)
  {
    InfraredResult InfraredBall = InfraredSeeker::ReadAC();
    a += InfraredBall.Direction;
  }
  a /= muestras;
  a = InfraredBall.Direction;
  //,,,,,,ADELANTE,,,,,,
  if (a < 6 && a > 4) {
    mueve.muevete(0, 255, valor);
  }
  //,,,,,,,,,,,,,,,,,,,
  //,,,ATRAS IZQUIERDA,,,,,
  else if (a <= 4 && a > 0) {
    mueve.muevete(225, 150, valor);
  }
  //,,,,,,,,,,,,,,,,,,,,,,
  //,,,,,ATRAS DERECHA,,,,,
  else if (a >= 7) {
    mueve.muevete(135, 150, valor);
  }
  //,,,,,,,,,,,,,,,,,,,,,
  else {
    mueve.muevete(0, 0, valor);
  }
}
