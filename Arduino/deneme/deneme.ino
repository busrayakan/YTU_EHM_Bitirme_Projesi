#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(10,11);
int  n;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ArduinoUno.begin(4800);
  
pinMode (11,INPUT);
pinMode (10,OUTPUT);

}

void  loop() {
  // put your main code here, to run repeatedly:
  n=analogRead(A2);
   ArduinoUno.print(n);
  ArduinoUno.println("\
");
  Serial.println(n);
  delay(300);
}