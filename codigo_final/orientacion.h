#ifndef ORIENTACION_H
#define ORIENTACION_H
#include "Arduino.h"
#include "librerias.h"
class orientacion : public library {
public:
orientacion();
void run();
bool frente();
};
#endif
