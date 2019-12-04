float color[2];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  color[0] = analogRead(A0);
  color[1] = analogRead(A1);
  color[2] = analogRead(A2);
  for (int i=0; i <= 2; i++) {
    Serial.print(color[i]);
    Serial.print("\t");
  }
  Serial.println("");
}
