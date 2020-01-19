void setup(){
   Serial.begin(9600);
   pinMode(13,OUTPUT); 
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);

pinMode(4,OUTPUT);
pinMode(5,OUTPUT);

pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

pinMode(8,OUTPUT);
pinMode(9,OUTPUT);

}

void loop(){
  if(Serial.available() > 0 ){
      char Dato = Serial.read();
      if(Dato == 'q'){   
      adelante();
      }
      else if(Dato == 'w'){
       atras();
       }
      else if(Dato == 'e'){
       apagado();
       } 
       else if(Dato == 'z'){
       digitalWrite(2, LOW);
digitalWrite(3, HIGH);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
       }
       else if(Dato == 'Z'){
       digitalWrite(2, HIGH);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
       }

  else if(Dato == 'x'){
       digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, HIGH);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
       }
       else if(Dato == 'X'){
       digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, HIGH);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
       }
       else if(Dato == 'c'){
       digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, HIGH);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
       }
       else if(Dato == 'C'){
       digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, HIGH);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
       }
       else if(Dato == 'v'){
       digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, HIGH);
       }
       else if(Dato == 'V'){
       digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, HIGH);
digitalWrite(9, LOW);
       }
            
      
  }
}
void adelante(){
digitalWrite(2, LOW);
digitalWrite(3, HIGH);

digitalWrite(4, LOW);
digitalWrite(5, HIGH);

digitalWrite(6, LOW);
digitalWrite(7, HIGH);

digitalWrite(8, LOW);
digitalWrite(9, HIGH);
 }
void atras(){
digitalWrite(3, LOW);
digitalWrite(2, HIGH);

digitalWrite(5, LOW);
digitalWrite(4, HIGH);

digitalWrite(7, LOW);
digitalWrite(6, HIGH);

digitalWrite(9, LOW);
digitalWrite(8, HIGH);
}
void apagado(){
digitalWrite(2, LOW);
digitalWrite(3, LOW);

digitalWrite(4, LOW);
digitalWrite(5, LOW);

digitalWrite(6, LOW);
digitalWrite(7, LOW);

digitalWrite(8, LOW);
digitalWrite(9, LOW);
}

