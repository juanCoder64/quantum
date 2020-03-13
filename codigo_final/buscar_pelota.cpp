#include "librerias.h"
#include "Arduino.h"
#include "buscar_pelota.h"
#include <HTInfraredSeeker.h>
#include <IR360.h>
IR360 ir360(1);

pelota::pelota(){
  
  }
void pelota::Begin() {
  InfraredSeeker::Initialize();
  begin();

}
void pelota::run() {

  if (ir360.posicion() == 1275) {
    Lego();
  }
  else {
    grado(ir360.posicion(), 255);
  }

}
void pelota::Lego() {
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  int a = 0;
  int muestras = 10;
  for (int i = 0 ; i < muestras; i++)
  {
    InfraredResult InfraredBall = InfraredSeeker::ReadAC();
    a += InfraredBall.Direction;
  }
  a /= muestras;
  a = InfraredBall.Direction;
  //,,,,,,ADELANTE,,,,,,
  if (a < 6 && a > 4) {
    grado(0, 255);
  }
  //,,,,,,,,,,,,,,,,,,,
  //,,,ATRAS IZQUIERDA,,,,,
  else if (a <= 4 && a > 0) {
    grado(225, 150);
  }
  //,,,,,,,,,,,,,,,,,,,,,,
  //,,,,,ATRAS DERECHA,,,,,
  else if (a >= 7) {
    grado(135, 150);
  }
  //,,,,,,,,,,,,,,,,,,,,,
}
