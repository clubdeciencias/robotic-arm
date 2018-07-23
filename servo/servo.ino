#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
char servo;
int OutServo1=5;
int OutServo2=6;
int OutServo3=9;
int OutServo4=10;
int vel = 0;
boolean rotating = false;

void setup() {
myservo1.attach(OutServo1);
myservo2.attach(OutServo2);
myservo3.attach(OutServo3);
myservo4.attach(OutServo4);
Serial.begin(9600);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() {

  if (Serial.available()){
    servo = Serial.read();
    if(servo=='O'){ 
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(12,LOW);
      servo='Z';
      rotating = true;
      giros();
      }
    if(servo=='X'){
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(12,LOW);
      servo='Z'; 
      rotating = true;
      giros2();
    }
     if(servo=='A'){
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(12,LOW);
      servo='Z'; 
      rotating = true;
      giros3();
     }
     if(servo=='U'){
      digitalWrite(12,HIGH);
      delay(200);
      digitalWrite(12,LOW);
      servo='Z';
      rotating = true;
      giros4();
    }
  }
}
void giros(){
  while(rotating){
   if (Serial.available()){
    delay(200);
    servo = Serial.read();
  digitalWrite(13,HIGH);
    if (servo== '2')
    {
      digitalWrite(13,LOW);
      myservo1.writeMicroseconds(1700);
      servo='Z';
     }
     if(servo=='3')
      {
      myservo1.writeMicroseconds(1300);
      digitalWrite(13,HIGH);
      servo='Z';

      }
      if(servo=='1')
     {
     myservo1.writeMicroseconds(1500);
     digitalWrite(13,LOW);  
     servo='Z';
     }
     if (servo=='E'){
      myservo1.writeMicroseconds(1500);
      rotating = false;
     }     
     else {
        Serial.write("Error, introduce un comando válido. 1,2 o 3");
     }
    }
  }
}
void giros2(){
  while(rotating){
   if (Serial.available()){
    delay(200);
    servo = Serial.read();
  digitalWrite(13,HIGH);
    if (servo== '2')
    {
      digitalWrite(13,LOW);
      myservo2.writeMicroseconds(1700);
      servo='Z';
     }
     if(servo=='3')
      {
      myservo2.writeMicroseconds(1300);
      digitalWrite(13,HIGH);
      servo='Z';

      }
      if(servo=='1')
     {
     myservo2.writeMicroseconds(1500);
     digitalWrite(13,LOW);  
     servo='Z';
     }
     if (servo=='E'){
      myservo2.writeMicroseconds(1500);
      rotating = false;
     }     
     else {
        Serial.write("Error, introduce un comando válido. 1,2 o 3");
     }
    }
  }
}
void giros3(){
  while(rotating){
   if (Serial.available()){
    delay(200);
    servo = Serial.read();
  digitalWrite(13,HIGH);
    if (servo== '2')
    {
      digitalWrite(13,LOW);
      myservo3.writeMicroseconds(1700);
      servo='Z';
     }
     if(servo=='3')
      {
      myservo3.writeMicroseconds(1300);
      digitalWrite(13,HIGH);
      servo='Z';

      }
      if(servo=='1')
     {
     myservo3.writeMicroseconds(1500);
     digitalWrite(13,LOW);  
     servo='Z';
     }
     if (servo=='E'){
      myservo3.writeMicroseconds(1500);
      rotating = false;
     }     
     else {
        Serial.write("Error, introduce un comando válido. 1,2 o 3");
     }
    }
  }
}
void giros4(){
  while(rotating){
   if (Serial.available()){
    delay(200);
    servo = Serial.read();
  digitalWrite(13,HIGH);
    if (servo== '2')
    {
      digitalWrite(13,LOW);
      myservo4.writeMicroseconds(1700);
      servo='Z';
     }
     if(servo=='3')
      {
      myservo4.writeMicroseconds(1300);
      digitalWrite(13,HIGH);
      servo='Z';

      }
      if(servo=='1')
     {
     myservo4.writeMicroseconds(1500);
     digitalWrite(13,LOW);  
     servo='Z';
     }
     if (servo=='E'){
      myservo4.writeMicroseconds(1500);
      rotating = false;
     }     
     else {
        Serial.write("Error, introduce un comando válido. 1,2 o 3");
     }
    }
  }
}


