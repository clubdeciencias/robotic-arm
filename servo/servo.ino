#include <Servo.h>
Servo miServo;
Servo miSegundoServo;
int angulo=90;

void setup() {
miServo.attach(9);
miSegundoServo.attach(10);
Serial.begin(9600); 
}

void loop() {
unsigned char comando=0;
if(Serial.available()){

  comando=Serial.read();
  

  if(comando=='a')angulo+=10;
  else if(comando=='z')angulo-=10;
  angulo=constrain(angulo,0,180);
  comando=0;
}
miServo.write(angulo);
miSegundoServo.write(angulo);
Serial.print("Angulo:");Serial.println(angulo);
delay(100);
}

