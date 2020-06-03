#include "evitarLinea.h"
#include "Arduino.h"
evitarLinea::evitarLinea(){
  
}
void evitarLinea::run() {
for (int i=0; i < 4; i++) {
Serial.print(getLinea(i));
Serial.print("\t");
    if (getLinea(i) > 0) {
      grado(90 * i, 255);
    }
  }
  Serial.println("");

}
bool evitarLinea::linea() {
  if (getLinea(0) + getLinea(1) + getLinea(2) + getLinea(3) > 0) {
    return 1;
  }
  else {
    return 0;
  }

}
void evitarLinea::calibrar() {
  calibrate();
}
