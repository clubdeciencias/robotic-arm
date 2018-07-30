#include <Servo.h>
#include <SoftwareSerial.h>
#include "ArduinoJson-v5.13.2.h" //JSON parsing library

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

int OutServo1 = 5;
int OutServo2 = 6;
int OutServo3 = 9;
int OutServo4 = 10;
int OutServo5 = 11; // YET TO DECIDE A PIN

int vel = 0;


void setup() {
	myservo1.attach(OutServo1);
	myservo2.attach(OutServo2);
	myservo3.attach(OutServo3);
	myservo4.attach(OutServo4);
	myservo5.attach(OutServo5);

	Serial.begin(9600);

	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(LED_BUILTIN, OUTPUT);

	StaticJsonBuffer<200> jsonBuffer;
	

}
void loop() {

	if (Serial.available()) {
		DynamicJsonBuffer jsonBuffer;
		JsonObject& root = jsonBuffer.parseObject(Serial); //Parse JSON
		if (!root.success()) {
			Serial.write("parseObject() failed \n");
			for (int a = 0; a < 10; a++) {
				led(100);
				delay(100);

			}
			return;
		}
		int servo = root["servo"]; // "servo" char
		int direction = root["direction"]; // "direction" char
		int angle = root["angle"]; // "angle" int
		Serial.println(servo);
		Serial.println(direction);
		rotate(servo, direction, angle); //execute rotation with the given data. 
		jsonBuffer.clear();
		

	}
}

void led(int timeInMiliseconds) { // method to have a LED on for a determinated time in miliseconds
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timeInMiliseconds);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void rotate(int servo, int direction, int angle) {
	
	int calculatedMiliseconds; //to-do mathematic method that turns "int angle" into miliseconds
	int speed; 


	switch (direction)
	{
	case 1:
		speed = 1600;
		break;

	case 0:
		speed = 1400;
		break;
	default:
		Serial.println("UNKNOWN DIRECTION ERROR");
		for (int a = 0; a < 5; a++) {
			led(100);
			delay(100);
		}
		break;
	}


	switch (servo)
	{
	case 1: 
		 
		myservo1.writeMicroseconds(speed);
		delay(calculatedMiliseconds);
		myservo1.writeMicroseconds(1500);
		break;

	case 2:
		myservo2.writeMicroseconds(speed);
		delay(calculatedMiliseconds);
		myservo2.writeMicroseconds(1500);
		break;

	case 3:
		myservo3.writeMicroseconds(speed);
		delay(calculatedMiliseconds);
		myservo3.writeMicroseconds(1500);
		break;

	case 4:
		myservo4.writeMicroseconds(speed);
		delay(calculatedMiliseconds);
		myservo4.writeMicroseconds(1500);
		break;

	case 5:
		myservo5.writeMicroseconds(speed);
		delay(calculatedMiliseconds);
		myservo5.writeMicroseconds(1500);
		break;

	
	default:
		Serial.println("UNKNOWN SERVO ERROR");
		for (int a = 0; a < 10; a++) {
			led(100);
			delay(100);
		}
		break;
	}
}
