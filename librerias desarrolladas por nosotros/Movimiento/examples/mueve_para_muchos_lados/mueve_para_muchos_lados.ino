/*ejemplo para la librería Movimiento.h de chabots Quantum -[:]
 */
#include<Movimiento.h>
void setup() {
  // put your setup code here, to run once:

}
Movimiento mueve(1);//variable que no es significante
void loop() {
  // put your main code here, to run repeatedly:
mueve.muevete(0,150);
delay(500);
mueve.muevete(0,0);
delay(500);
mueve.muevete(45,150);
delay(500);
mueve.muevete(0,0);
delay(500);
mueve.muevete(90,150);
delay(500);
mueve.muevete(0,0);
delay(500);
mueve.muevete(135,150);
delay(500);
mueve.muevete(0,0);
delay(500);
mueve.muevete(180,150);
delay(500);
mueve.muevete(0,0);
delay(500);
mueve.muevete(225,150);
delay(500);
mueve.muevete(0,0);
delay(500);
mueve.muevete(270,150);
delay(500);
mueve.muevete(0,0);
}
