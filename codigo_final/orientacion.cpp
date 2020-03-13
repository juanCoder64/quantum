#include "Arduino.h"
#include "orientacion.h"
orientacion::orientacion(){
  
}
void orientacion::Begin(){
  begin();
}
void orientacion::run(){
  orientar(valor);
}
bool orientacion::frente() {
  brujula();
  if (valor < 10 || valor > 350) {
    return 1;
  }
  else {
    return 0;
  }
}
