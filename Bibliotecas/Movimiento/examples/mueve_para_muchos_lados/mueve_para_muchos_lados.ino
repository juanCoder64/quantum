/*ejemplo para la librería Movimiento.h de chabots Quantum -[:]
*/
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include<Movimiento.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 oled(128, 64, &Wire, 4);
Adafruit_BNO055 bruj(55, 0x28);
float lectura;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bruj.begin();
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
Movimiento mueve(0, 0, 0); //el primer valor es P, el segundo I y el tercero es D
void loop() {
    sensors_event_t orientationData , linearAccelData;

  
  imu::Vector<3> brujula = bruj.getEvent(&orientationData, Adafruit_BNO055::VECTOR_EULER);
  lectura =  orientationData.orientation.x;
  oled.clearDisplay();
  oled.setTextSize(2);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(20, 0);
  oled.print(lectura);
  mueve.muevete(0,255, lectura);
  /*delay(500);
    mueve.muevete(0, 0, lectura);
    delay(500);
    mueve.muevete(45, 150, lectura);
    delay(500);
    mueve.muevete(0, 0, lectura);
    delay(500);
    mueve.muevete(90, 150, lectura);
    delay(500);
    mueve.muevete(0, 0, lectura);
    delay(500);
    mueve.muevete(135, 150, lectura);
    delay(500);
    mueve.muevete(0, 0, lectura);
    delay(500);
    mueve.muevete(180, 150, lectura);
    delay(500);
    mueve.muevete(0, 0, lectura);
    delay(500);
    mueve.muevete(225, 150, lectura);
    delay(500);
    mueve.muevete(0, 0, lectura);
    delay(500);
    mueve.muevete(270, 150, lectura);
    delay(500);
    mueve.muevete(0, 0, lectura);
    Serial.println(lectura);*/
  oled.display();
}
