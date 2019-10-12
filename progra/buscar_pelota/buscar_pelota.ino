#include <HTInfraredSeeker.h>
#include <Movimiento.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
Adafruit_SSD1306 oled(128, 64, &Wire, 4);
Movimiento mueve(0);
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600); //Starts the Serial Monitor so we can read output
  InfraredSeeker::Initialize(); //initializes the IR sensor
  Wire.begin();
   oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop() {
// put your main code here, to run repeatedly:

InfraredResult InfraredBall = InfraredSeeker::ReadAC();
int a=0;
int muestras=10;
  for(int i= 0 ; i< muestras; i++)
  {
      // put your main code here, to run repeatedly:
     InfraredResult InfraredBall = InfraredSeeker::ReadAC();
    a += InfraredBall.Direction;
  }
a/=muestras;
a = InfraredBall.Direction;
Serial.print(" ir= ");
Serial.println(a);
oled.clearDisplay();
    oled.setTextSize(2);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 0);            // Start at top-left corner
  oled.print("buscando P");
  oled.setTextSize(1);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 20);            // Start at top-left corner
  oled.print("pelota");
  oled.setTextSize(1);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 30);            // Start at top-left corner
  oled.print(a);
  oled.display();
//,,,,,,ADELANTE,,,,,,
if(a<6 && a>4){
mueve.muevete(0,255);
}
//,,,,,,,,,,,,,,,,,,,
//,,,ATRAS IZQUIERDA,,,,, 
else if(a<=4 && a>0){
mueve.muevete(225,150);
}
//,,,,,,,,,,,,,,,,,,,,,,
//,,,,,ATRAS DERECHA,,,,,
else if(a>=7){
mueve.muevete(135,150);
}
//,,,,,,,,,,,,,,,,,,,,,
else{
mueve.muevete(0,0);
}
}
