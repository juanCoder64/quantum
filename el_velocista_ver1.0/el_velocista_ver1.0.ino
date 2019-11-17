/*
   Código del seguidor de linea.
   Desarollado por chaBots Quantum.
*/
const int vmin = 80;
const int vmax = 150;
const float kp = .015;
const float ki = 0.0003;
const float kd = 0.2;
const float kv = 0.07;
unsigned int IR[3];
int p, d, u, vbase;
long i = 0;
int p_old = 0;
void setup() {
  pinMode(22, INPUT);
  pinMode(24, INPUT);
  pinMode(26, INPUT);
  pinMode(28, INPUT);
  Serial.begin(9600);
}
void loop() {
  IR[0] = digitalRead(22);
  IR[1] = digitalRead(24);
  IR[2] = digitalRead(26);
  IR[3] = digitalRead(28);
  p =  -2 * IR[0] -   IR[1] + IR[2] + 2 * IR[3]; //en la variable p(proporcional) se unifican todas las lecturas de los sensores
  i = i + p;//en la variable i (integral) se van sumando todos los valores de p
  d = p - p_old;//en la variable d(direccional)
  p_old = p;//actualiza la variable p_old para el proximo ciclo
  if ((p * i) < 0) i = 0; // limpia el valor de i
  u = kp * p + ki * i + kd * d; //calcula el pwm que le tiene que dar a las llantas
  vbase = vmin + (vmax - vmin) * exp(-kv * abs(kp * p));//hace que en las rectas vaya más rapido
  moverse(vbase + u, vbase - u);
  Serial.println(u);
}
void moverse(float valorder, float valorizq) {

}
