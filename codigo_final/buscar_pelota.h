#ifndef BUSCAR_PELOTA_H
#define BUSCAR_PELOTA_H
#include "librerias.h"
#include "Arduino.h"
class pelota : public library  {
  public:
    pelota();
    void Begin();
    void run();
    void Lego();
private:
int posicion;
int speed;
};
#endif
