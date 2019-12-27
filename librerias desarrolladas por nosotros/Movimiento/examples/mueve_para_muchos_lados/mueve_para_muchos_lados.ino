/*ejemplo para la librería Movimiento.h de chabots Quantum -[:]
 */
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include<Movimiento.h>
Adafruit_BNO055 bruj = Adafruit_BNO055(55, 0x28);
float lectura;
void setup() {
  // put your setup code here, to run once:
bruj.begin();
}
Movimiento mueve(1,2,3);//el primer valor es P, el segundo I y el tercero es D
void loop() {
  // put your main code here, to run repeatedly:
  imu::Vector<3> brujula= bruj.getVector(Adafruit_BNO055::VECTOR_EULER);
  lectura=atan2(brujula.x(),brujula.y());
mueve.muevete(0,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
delay(500);
mueve.muevete(45,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
delay(500);
mueve.muevete(90,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
delay(500);
mueve.muevete(135,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
delay(500);
mueve.muevete(180,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
delay(500);
mueve.muevete(225,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
delay(500);
mueve.muevete(270,150,lectura);
delay(500);
mueve.muevete(0,0,lectura);
}
