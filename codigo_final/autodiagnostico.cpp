#include "librerias.h"
#include "Arduino.h"
#include "autodiagnostico.h"
autodiagnostico::autodiagnostico() {

}
void autodiagnostico::Begin(){
  begin();
}
void autodiagnostico::run(){
  borra();
  imprime();
}
