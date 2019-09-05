void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  atrasizquierda();
  delay(500);
  apagado();
  delay(500);
  atrasderecha();
  delay(500);
  apagado();
  delay(500);
  atras();
  delay(500);
  apagado();
  delay(500);
  adelante();
  delay(500);
  apagado();
  delay(500);
  derecha();
  delay(500);
  apagado();
  delay(500);
  izquierda();
  delay(500);
  apagado();
  delay(500);

}
void adelante() {
  analogWrite(2, LOW);
  analogWrite(3, 150);

  analogWrite(4, 150);
  analogWrite(5, LOW);

  analogWrite(6, LOW);
  analogWrite(7, 150);

  analogWrite(8, 150);
  analogWrite(9, LOW);
}
void atras() {
  analogWrite(2, 150);
  analogWrite(3, LOW);

  analogWrite(4, LOW);
  analogWrite(5, 150);

  analogWrite(6, 150);
  analogWrite(7, LOW);

  analogWrite(8, LOW);
  analogWrite(9, 150);
}
void apagado() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}
void atrasizquierda() {
  analogWrite(2, 150);
  analogWrite(3, LOW);

  analogWrite(4, LOW);
  analogWrite(5, LOW);

  analogWrite(6, LOW);
  analogWrite(7, LOW);

  analogWrite(8, LOW);
  analogWrite(9, 150);
}
void atrasderecha() {
  analogWrite(2, LOW);
  analogWrite(3, LOW);

  analogWrite(4, LOW);
  analogWrite(5, 150);

  analogWrite(6, 150);
  analogWrite(7, LOW);

  analogWrite(8, LOW);
  analogWrite(9, LOW);
}
void derecha() {
  analogWrite(2, 150);
  analogWrite(3, LOW);

  analogWrite(4, 150);
  analogWrite(5, LOW);

  analogWrite(6, LOW);
  analogWrite(7, 150);

  analogWrite(8, LOW);
  analogWrite(9, 150);
}
void izquierda() {
  analogWrite(2, LOW);
  analogWrite(3, 150);

  analogWrite(4, LOW);
  analogWrite(5, 150);

  analogWrite(6, 150);
  analogWrite(7, LOW);

  analogWrite(8, 150);
  analogWrite(9, LOW);
}
