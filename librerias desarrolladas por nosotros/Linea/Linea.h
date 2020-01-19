#include "Arduino.h"
#ifndef Linea_h
#define Linea_h
class Linea{
public:
Linea(int centro,int medio,int exterior);
void calibrar();
int lectura();
private:
int a, b, c, Ca, Cb, Cc,centro,medio,exterior;
};
#endif