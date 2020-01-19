#include "Arduino.h"
#ifndef Enviar_h
#define Enviar_h
class Movimiento{
public:
Movimiento(float KP,float KI, float KD);
void muevete(int ANGLE,int MAXSpeed,int brujula);
void rota(int brujula);
void recio();
private:
int a;
int b;
int c;
int d;
int speed;
float P,I,D,PID,KP,KI,KD,kP,kI,kD,error,pastError,errorSum,errorPrev;
int _angle;
int _MAXSpeed;
};
#endif
