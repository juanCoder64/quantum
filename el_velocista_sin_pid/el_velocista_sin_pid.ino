void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int valor1 = digitalRead(8);
  int valor2 = digitalRead(9);
 
  
  if (valor1 == 1) {
    //derecha
    digitalWrite(5, HIGH);
  }
  else{
     analogWrite(5, 125);
  }
  if (valor2 == 1) {
    //izquierda
    digitalWrite(6, HIGH);

  }
  else{
    analogWrite(6, 125);
  }
  Serial.print(valor1);
  Serial.print("\t");
  Serial.println(valor2);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
}
