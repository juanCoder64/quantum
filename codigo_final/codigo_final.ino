/*
    Código del equipo Chabots Quantum -[:] para el torneo mexicano de robotica 2020
*/
#include "evitarLinea.h"
#include "buscar_pelota.h"
#include "orientacion.h"
orientacion orientation;
evitarLinea linea;
pelota IR;
void setup() {
  IR.Begin();
    orientation.Begin();
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
