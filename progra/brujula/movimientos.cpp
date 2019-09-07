#include "Arduino.h"
#include "movimientos.h"
Movimiento::Movimiento(int velocidad){
  _velocidad=vel;
}
void Movimiento::derecha() {
  analogWrite(2, vel);
  analogWrite(3, 0);
  analogWrite(4, vel);
  analogWrite(5, 0);
  analogWrite(6, vel);
  analogWrite(7, 0);
  analogWrite(8, vel);
  analogWrite(9, 0);
}
void Movimiento::izquierda() {
  analogWrite(2, 0);
  analogWrite(3, vel);
  analogWrite(4, 0);
  analogWrite(5, vel);
  analogWrite(6, 0);
  analogWrite(7, vel);
  analogWrite(8, 0);
  analogWrite(9, vel);
}
void Movimiento::apagado() {
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(7, 0);
  analogWrite(8, 0);
  analogWrite(9, 0);
}
