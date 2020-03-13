#ifndef EVITARLINEA_H
#define EVITARLINEA_H
#include "Arduino.h"
#include "librerias.h"
class evitarLinea : public library  { 
  public:
  evitarLinea();
  void run();
  void calibrar();
  bool linea();
  private:
  
};
#endif
