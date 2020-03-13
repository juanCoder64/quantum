/*
    Código del equipo Chabots Quantum -[:] para el torneo mexicano de robotica 2020
    este y otros códigos más se pueden encontrar en https://github.com/juanCoder64/quantum
*/
#include "evitarLinea.h"
#include "buscar_pelota.h"
#include "orientacion.h"
orientacion orientation;
evitarLinea linea;
pelota IR;
void setup() {
  IR.Begin();
  linea.calibrar();
}
void loop() {
  if (orientation.frente()) {
    if (!linea.linea()) {
      IR.run();
    }
    else {
      linea.run();
    }
  }
  else {
    orientation.run();
  }
}
