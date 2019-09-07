#ifndef Enviar_h
#define Enviar_h
#include "Arduino.h"
class Movimiento{
public:
Movimiento(int velocidad);
void derecha();
void izquierda();
void apagado();
private:
int vel;
};
#endif
