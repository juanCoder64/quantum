#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <IR360.h>
Adafruit_SSD1306 oled(128, 64, &Wire, 4);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
IR360 ir(1);
void loop() {
  oled.clearDisplay();
  oled.setTextSize(3);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 0);
  oled.print(ir.posicion());
  // put your main code here, to run repeatedly:
  Serial.println(ir.intensidad());
  Serial.println(ir.posicion());
  oled.display();
}
