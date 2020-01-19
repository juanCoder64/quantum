#include <IR360.h>
void setup() {
Serial.begin(9600);
}
IR360 ir(1);
void loop() {
  // put your main code here, to run repeatedly:
Serial.println(ir.intensidad());
Serial.println(ir.posicion());
}
