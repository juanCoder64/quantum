#include "librerias.h"
#include "Arduino.h"
#include "buscar_pelota.h"
#include <HTInfraredSeeker.h>
#include <IR360.h>
IR360 ir360(1);

pelota::pelota() {

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
    omnidIR();
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
  posicion = map(a, 1, 9, -135, 255);
  if (posicion < 0) {
    posicion += 360;
  }
  grado(posicion, 255);

  /*,,,,,,ADELANTE,,,,,,
    if (a < 6 && a > 4) {
    grado(0, 170);
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
    else{
    grado(0,0);
    }
    //,,,,,,,,,,,,,,,,,,,,,*/
}
void pelota::omnidIR() {
  speed = map(ir360.intensidad(), 40, 0, 170, 255);
  borra();
  pantalla(3, 0, 0, speed);
  imprime();
  if (ir360.intensidad() > 30) { //encontrar un mejor valor
    grado(ir360.posicion(), speed);
  }
  else {
    if (ir360.posicion() < 180 && ir360.posicion() > 20) {
      grado(ir360.posicion() + 90, speed);
    }
    else if (ir360.posicion() > 180 && ir360.posicion() < 350) {
      grado(ir360.posicion() - 90, speed);
    }
    else {
      grado(ir360.posicion(), speed);
    }
  }
}
