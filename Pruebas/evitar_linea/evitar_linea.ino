#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Linea.h>
#include <Movimiento.h>
Adafruit_SSD1306 oled(128, 64, &Wire, 4);
Linea frente(A0, A1, A2, 50);
Linea izq(A3, A4, A5, 51);
Linea der(A6, A7, A8, 52);
Linea abajo(A9, A10, A11, 53);
Movimiento mueve(1, 2, 3);
Adafruit_BNO055 bruj(55, 0x28);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  calibrar();
  digitalWrite(50, HIGH);
}

void loop() {
  oled.clearDisplay();
  oled.setTextSize(2);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(64, 0);
  oled.print(izq.lectura());
  oled.setCursor(20, 32);
  oled.print(abajo.lectura());
  oled.setCursor(108, 32);
  oled.print(frente.lectura());
  oled.setCursor(64, 50);
  oled.print(der.lectura());

  // put your main code here, to run repeatedly:
  imu::Vector<3> brujula = bruj.getVector(Adafruit_BNO055::VECTOR_EULER);
  float bruj = atan2(brujula.x(), brujula.y());
  Serial.print(frente.lectura());
  Serial.print("\t");
  Serial.print(der.lectura());
  Serial.print("\t");
  Serial.print(abajo.lectura());
  Serial.print("\t");
  Serial.println(izq.lectura());
  if (izq.lectura() != 0) {
    if (izq.lectura() == 1) {
      mueve.muevete(90, 85, bruj);
    }
    if (izq.lectura() == 2) {
      mueve.muevete(90, 170, bruj);
    }
    else if (izq.lectura() == 3) {
      mueve.muevete(90, 255, bruj);
    }
    //delay(500);
  }
  if (der.lectura() != 0) {
    if (der.lectura() == 1) {
      //mueve.muevete(270, 85, bruj);
    }
    else if (der.lectura() == 2) {
      mueve.muevete(270, 170, bruj);
    }
    else if (der.lectura() == 3) {
      mueve.muevete(270, 255, bruj);
    }
    //delay(500);
  }
  if (frente.lectura() != 0) {
    if (frente.lectura() == 1) {
      mueve.muevete(0, 85, bruj);
    }
    else if (frente.lectura() == 2) {
      mueve.muevete(0, 170, bruj);
    }
    else if (frente.lectura() == 3) {
      mueve.muevete(0, 255, bruj);
    }
    //delay(500);
  }
  if (abajo.lectura() != 0) {
    if (abajo.lectura() == 1) {
      mueve.muevete(0, 85, bruj);
    }
    else if (abajo.lectura() == 2) {
      mueve.muevete(0, 170, bruj);
    }
    else if (abajo.lectura() == 3) {
      mueve.muevete(0, 255, bruj);
    }
    //delay(500);
  }

  oled.display();
}
void calibrar() {
  Serial.println("poner todos los sensores en verde");
  for (int i = 0; i < 5; i++) {
    oled.clearDisplay();
    oled.setTextSize(2);             // Normal 1:1 pixel scale
    oled.setTextColor(WHITE);        // Draw white text
    oled.setCursor(20, 0);
    oled.print("verde");
    oled.setCursor(20, 64);
    oled.print(i + 1);
    Serial.print(i + 1);
    oled.display();
    delay(1000);

  }
  frente.calibrarV();
  izq.calibrarV();
  der.calibrarV();
  abajo.calibrarV();
  Serial.println("poner los sensores laterales en blanco");
  for (int i = 0; i < 5; i++) {
    oled.clearDisplay();
    oled.setTextSize(2);             // Normal 1:1 pixel scale
    oled.setTextColor(WHITE);        // Draw white text
    oled.setCursor(20, 0);
    oled.print("laterales");
    oled.setCursor(20, 64);
    oled.print(i + 1);
    Serial.print(i + 1);
    oled.display();
    delay(1000);

  }
  izq.calibrarB();
  der.calibrarB();
  Serial.println("poner los sensores de arriba y abajo en blanco");
  for (int i = 0; i < 5; i++) {
    oled.clearDisplay();
    oled.setTextSize(2);             // Normal 1:1 pixel scale
    oled.setTextColor(WHITE);        // Draw white text
    oled.setCursor(20, 0);
    oled.print("arriba");
    oled.setCursor(20, 64);
    oled.print(i + 1);
    Serial.print(i + 1);
    oled.display();
    delay(1000);
  }
  frente.calibrarB();
  abajo.calibrarB();
}
