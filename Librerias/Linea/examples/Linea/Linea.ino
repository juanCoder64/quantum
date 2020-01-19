#include <Linea.h>
Linea enfrente(A0,A1,A2);
void setup() {
  // put your setup code here, to run once:
enfrente.calibrar();
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(enfrente.lectura());
}
