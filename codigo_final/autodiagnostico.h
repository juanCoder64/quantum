#ifndef AUTODIAGNOSTICO_H
#define AUTODIAGNOSTICO_H
#include "librerias.h"
#include "Arduino.h"
class autodiagnostico : public library  {
  public:
    autodiagnostico();
    void Begin();
    void run();
private:
int posicion;
int speed;
};
#endif
