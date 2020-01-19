#include "Arduino.h"
#ifndef IR360_h
#define IR360_h
class IR360{
public:
IR360(int);
int posicion();
int intensidad();
private:
int L;
int I;
};
#endif
