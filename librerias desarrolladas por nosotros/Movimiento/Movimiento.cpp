#include "Arduino.h"
#include "Movimiento.h"
Movimiento::Movimiento(float KP,float KI, float KD) {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  kP = KP;
  kI = KI;
  kD = KD;
}
void Movimiento::muevete(int ANGLE, int MAXSpeed, int brujula) {
  P = ANGLE - brujula;
  error = P;
  errorSum += error;
  I = ANGLE-errorSum;
  D = errorPrev-error;
  P *= KP;
  I *= KI;
  D *= KD;
  errorPrev=error;
  PID = P+I+D;
  a = sin(((PID + 45) * PI) / 180) * MAXSpeed;
  b = sin(((PID + 135) * PI) / 180) * MAXSpeed;
  c = sin(((PID + 225) * PI) / 180) * MAXSpeed;
  d = sin(((PID + 315) * PI) / 180) * MAXSpeed;
  a = constrain(a, -255, 255);
  b = constrain(b, -255, 255);
  c = constrain(c, -255, 255);
  d = constrain(d, -255, 255);
  if (a > 0) {
    analogWrite(2, LOW);
    analogWrite(3, -a);
    a = -a;
  }
  else {
    analogWrite(2, a);
    analogWrite(3, LOW);

  }
  //----------------
  if (b > 0) {
    analogWrite(4, LOW);
    analogWrite(5, -b);
    b = -b;
  }
  else {
    analogWrite(4, b);
    analogWrite(5, LOW);
  }
  if (c > 0) {
    analogWrite(6, LOW);
    analogWrite(7, -c);
    c = -c;
  }
  else {
    analogWrite(6, c);
    analogWrite(7, LOW);

  }
  if (d > 0) {
    analogWrite(8, LOW);
    analogWrite(9, -d);
    d = -d;
  }
  else {
    analogWrite(8, d);
    analogWrite(9, LOW);
  }
}
void Movimiento::rota(int brujula) {
  if (brujula < 180) {
  	P = map(brujula, 10, 180, 30, 200);
    PID =P+I+D;
    analogWrite(2, PID);
    analogWrite(3, LOW);
    analogWrite(4, PID);
    analogWrite(5, LOW);
    analogWrite(6, PID);
    analogWrite(7, LOW);
    analogWrite(8, PID);
    analogWrite(9, LOW);
  }
  else {
  	P = map(brujula, 180, 350, 200, 30);
  	PID =P+I+D;
    analogWrite(2, LOW);
    analogWrite(3, PID);
    analogWrite(4, LOW);
    analogWrite(5, PID);
    analogWrite(6, LOW);
    analogWrite(7, PID);
    analogWrite(8, LOW);
    analogWrite(9, PID);
  }
}
void Movimiento::recio() {
  analogWrite(2, HIGH);
  analogWrite(3, HIGH);
  analogWrite(4, HIGH);
  analogWrite(5, HIGH);
  analogWrite(6, HIGH);
  analogWrite(7, HIGH);
  analogWrite(8, HIGH);
  analogWrite(9, HIGH);
}
