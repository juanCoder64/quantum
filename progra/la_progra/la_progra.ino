#include <Wire.h>
#include <Movimiento.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 oled(128, 64, &Wire, 4);
#include <Adafruit_Sensor.h>
#include <HTInfraredSeeker.h>
#include <Adafruit_HMC5883_U.h>
float ini;
int a;
int l1 = 60;
int b;
int vuelta = 250;
int S;
float valor;
int compas;
int ir;
int oledP;
int adelante;
float headingDegrees;
unsigned long inicio;
unsigned long termino;
unsigned long tardanza;
/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);
Movimiento mueve(0);
/*void brujula(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  /* Get a new sensor event 
  sensors_event_t event;
  mag.getEvent(&event);

  /* oled the results (magnetic vector values are in micro-Tesla (uT)) 
  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);

  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;

  // Correct for when signs are reversed.
  if (heading < 0)
    heading += 2 * PI;

  // Check for wrap due to addition of declination.
  if (heading > 2 * PI)
    heading -= 2 * PI;

  // Convert radians to degrees for readability.
  headingDegrees = heading * 180 / M_PI;
}*/

void setup(void)
{
  pinMode(22, INPUT_PULLUP);
  Serial.begin(9600);
  Wire.begin();
  /* Initialise the sensor */
  //mag.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  /* oled some basic information on this sensor */
  //brujula();
  //ini = headingDegrees;
  //checar();
  analogWrite(13, 100);
}

void loop(void)
{
  
  inicio = millis();
  int debug = digitalRead(22);
  oled.clearDisplay();
  if (debug == 0) {
    checar();
  }
  //else {
  /*  orientar();
    if (adelante == 0) {
//      brujula();
      oled.setTextSize(2);             // Normal 1:1 pixel scale
      oled.setTextColor(WHITE);        // Draw white text
      oled.setCursor(0, 0);            // Start at top-left corner
      oled.print("orientando");
      oled.setTextSize(1);             // Normal 1:1 pixel scale
      oled.setTextColor(WHITE);        // Draw white text
      oled.setCursor(50, 20);            // Start at top-left corner
      oled.print("centro");
      oled.setTextSize(1);             // Normal 1:1 pixel scale
      oled.setTextColor(WHITE);        // Draw white text
      oled.setCursor(50, 30);            // Start at top-left corner
      oled.print(valor);
      oled.setTextSize(1);             // Normal 1:1 pixel scale
      oled.setTextColor(WHITE);        // Draw white text
      oled.setCursor(0, 20);            // Start at top-left corner
      oled.print("norte");
      oled.setTextSize(1);             // Normal 1:1 pixel scale
      oled.setTextColor(WHITE);        // Draw white text
      oled.setCursor(0, 30);            // Start at top-left corner
      oled.print(headingDegrees);
      oled.setTextSize(1);             // Normal 1:1 pixel scale
      oled.setTextColor(WHITE);        // Draw white text
      oled.setCursor(0, 40);            // Start at top-left corner
      oled.print("girar hacia");
      Movimiento mueve();
      if (valor < vuelta) {
        oled.setTextSize(1);             // Normal 1:1 pixel scale
        oled.setTextColor(WHITE);        // Draw white text
        oled.setCursor(0, 50);            // Start at top-left corner
        oled.print("izquierda");
        l1 = map(valor, 10, vuelta, 30, 255);
        }
      else {
        oled.setTextSize(1);             // Normal 1:1 pixel scale
        oled.setTextColor(WHITE);        // Draw white text
        oled.setCursor(0, 50);            // Start at top-left corner
        oled.print("derecha");
        l1 = map(valor, vuelta, 350, 255, 30);
        
      }
    }*/
    else {
      buscar();
    
    termino = millis();
    tardanza = termino - inicio;
    oled.setTextSize(1);             // Normal 1:1 pixel scale
    oled.setTextColor(WHITE);        // Draw white text
    oled.setCursor(80, 40);            // Start at top-left corner
    oled.print("tardanza");
    oled.setTextSize(1);             // Normal 1:1 pixel scale
    oled.setTextColor(WHITE);        // Draw white text
    oled.setCursor(80, 50);            // Start at top-left corner
    oled.print(tardanza);
  }
  

  oled.display();

}
int frente() {
  if (valor < 10 || valor > 350) {
    return 1;
  }
  else {
    return 0;
  }
}
void orientar() {
  adelante = frente();
  Serial.print(adelante);
  Serial.print("\t");
//  brujula();
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
  valor = headingDegrees - ini;
  if (valor < 0) {
    valor += 360;
  }
}
void buscar() {
  oled.setTextSize(2);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 0);            // Start at top-left corner
  oled.print("buscando P");
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  b = InfraredBall.Strength;
  a = InfraredBall.Direction;

  Serial.print(" ir= ");
  Serial.print(a);
  Serial.print("\t");
  oled.setTextSize(1);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 20);            // Start at top-left corner
  oled.print("pelota");
  oled.setTextSize(1);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(0, 30);            // Start at top-left corner
  oled.print(a);
  oled.setTextSize(1);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(50, 20);            // Start at top-left corner
  oled.print("intensidad");
  oled.setTextSize(1);             // Normal 1:1 pixel scale
  oled.setTextColor(WHITE);        // Draw white text
  oled.setCursor(50, 30);            // Start at top-left corner
  oled.print(b);
  
  //,,,,,,ADELANTE,,,,,,
  if (a <= 6 && a >= 4 || a >= 8 && b < 160) {
    
    mueve.muevete(0,255);
  }
  //,,,,,,,,,,,,,,,,,,,
  //,,,ATRAS IZQUIERDA,,,,,
  else if (a < 4 && a > 0) {
    //atrasIzquierda();

    mueve.muevete(225,255);
    //225,255
  }
  //,,,,,,,,,,,,,,,,,,,,,,
  //,,,,,ATRAS DERECHA,,,,,
  else if (a >= 7 || a > 4 && b < 100) {
    //atrasDerecho();
     mueve.muevete(135,255);
   //(135,255);
  }
  
  //,,,,,,,,,,,,,,,,,,,,,
  else {
    //  apagado();
    mueve.muevete(0,0);
  }
 
}

void checar() {
  compas = 0;
  ir = 0;
  oledP = 0;
  byte error, address;
  int nDevices;

  nDevices = 0;
  for (address = 1; address < 127; address++ )
  {
    // El i2c_scanner utiliza el valor devuelto o el
    // Write.endTransmisstion para ver si un
    // dispositivo reconoció la dirección.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      if (address < 16)
        nDevices++;

      if (address == 8) {
        Serial.print("se detecta el ir");
        ir = 1;
      }
      else if (address == 60) {
        Serial.print("\t");
        Serial.print("se detecta el oled");
        oledP = 1;

      }
      else if (address == 30) {
        Serial.print("\t");
        Serial.print("se detecta compass");
        compas = 1;
      }
    }
    else {
      S = 0;
    }
  }
  if (S == 0) {

    if (nDevices < 0) {
      Serial.print("nada detectado :(\n");
    }
    else if (ir + oledP + compas == 3) {
      Serial.print("\t");
      Serial.print("senores y oled detectados\n");
      oled.setTextSize(2);
      oled.setTextColor(WHITE);
      oled.setCursor(0, 0);
      oled.print("sensores  detectados");
    }
    else {
      Serial.print("\t");
      Serial.println("falta algo");
      oled.setTextSize(2);
      oled.setTextColor(WHITE);
      oled.setCursor(0, 0);
      oled.print("revisar");
      if (compas == 0) {
        oled.setTextSize(2);
        oled.setTextColor(WHITE);
        oled.setCursor(0, 20);
        oled.print("compas");


      }
      if (ir == 0) {
        oled.setTextSize(2);
        oled.setTextColor(WHITE);
        oled.setCursor(0, 40);
        oled.print("ir");
      }
    }
  }
}
  
