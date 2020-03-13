#include "evitarLinea.h"
#include "Arduino.h"
evitarLinea::evitarLinea(){
  
}
void evitarLinea::run() {
  for (int i; i > 4; i++) {
    if (getLinea(i) > 0) {
      grado(90 * i, 255);
    }
  }
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
