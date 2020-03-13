#ifndef LIBRERIA_H
#define LIBRERIA_H
#include "Arduino.h"
class library {
  public:
    library();
    void begin();
    //brujula
    void brujula();
    float valor;
    //pantalla
    void display(int T, int X, int Y, String val);
    void imprime();
    void borra();
    //motores
    void grado(int, int);
    void freno();
    void orientar(float);
    //sensores de linea
    int getLinea(int);
    void calibrate();

};
#endif
