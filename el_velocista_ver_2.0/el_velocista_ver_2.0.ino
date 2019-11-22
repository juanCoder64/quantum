/*
   Código del seguidor de linea.
   Desarollado por chaBots Quantum.
*/
const int vmin = 80;
const int vmax = 150;
const float kp = .5;
const float ki = 0.0003;
const float kd = 0.2;
const float kv = 0.07;
int p, d, u, vbase=120;
long i = 0;
int p_old = 0;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(26, INPUT);
  pinMode(28, INPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // IR[0] = digitalRead(22);//se leen los sensores
int  IR1 = analogRead(A0);
int  IR2 = analogRead(A1);
  // IR[3] = digitalRead(28);
  Serial.print(IR1);
  Serial.print("\t");
  Serial.print(IR2);
  Serial.print("\t");
  p =    IR1 - IR2;
  u = kp * p;
  Serial.print(u);
  Serial.print("\t");
//  vbase = vmin + (vmax - vmin) * exp(-kv * abs(kp * p));//hace que en las rectas vaya más rapido
  moverse(vbase + u, vbase - u);

}
void moverse(float R, float L) {
  L = constrain(L, -255, 255); // hace que el pwm no se exceda de 255
  R = constrain(R, -255, 255);// hace que el pwm no se exceda de 255
  //rueda izquierda
  digitalWrite(7, 0);
  analogWrite(6, abs(L));//solo un pin se declara como analogico porque solo se necesia ir hacia adelante
  //rueda derecha
  digitalWrite(4, 0);
  analogWrite(5, abs(R));//solo un pin se declara como analogico porque solo se necesia ir hacia adelantes
  Serial.print(abs(R));
  Serial.print("\t");
  Serial.println(abs(L));
}
