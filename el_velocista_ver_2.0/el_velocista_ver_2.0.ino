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
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  IR[0] = digitalRead(22);//se leen los sensores
  IR[1] = digitalRead(24);
  IR[2] = digitalRead(26);
  IR[3] = digitalRead(28);
  p =  -2 * IR[0] -   IR[1] + IR[2] + 2 * IR[3]; //en la variable p(proporcional) se unifican todas las lecturas de los sensores
  i = i + p;//en la variable i (integral) se van sumando todos los valores de p
  d = p - p_old;//en la variable d(direccional) se saca la diferencia del p pasado y el actual
  p_old = p;//actualiza la variable p_old para el proximo ciclo
  if ((p * i) < 0) i = 0; // limpia el valor de i
  u = kp * p + ki * i + kd * d; //calcula el pwm que le tiene que dar a las llantas
  vbase = vmin + (vmax - vmin) * exp(-kv * abs(kp * p));//hace que en las rectas vaya más rapido
  moverse(vbase + u, vbase - u);
  Serial.println(u);
}
void moverse(float valorder, float valorizq) {
  L = constrain(L, -255, 255); // hace que el pwm no se exceda de 255
  R = constrain(R, -255, 255);// hace que el pwm no se exceda de 255
//rueda izquierda
  digitalWrite(7, 0);
  analogWrite(6, abs(L));//solo un pin se declara como analogico porque solo se necesia ir hacia adelante
//rueda derecha
  digitalWrite(4, 0);
  analogWrite(5, abs(R));//solo un pin se declara como analogico porque solo se necesia ir hacia adelante
}
