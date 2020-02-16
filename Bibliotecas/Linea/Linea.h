#include "Arduino.h"
#ifndef Linea_h
#define Linea_h
class Linea{
public:
Linea(int centro,int medio,int exterior,int ledpin);
void calibrarV();
void calibrarB();
int lectura();
private:
int a, b, c, Ca, Cb, Cc,centro,medio,exterior,ledpin;
};
#endif