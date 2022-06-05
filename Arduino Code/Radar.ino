//**************************************************************************************
//                Arduino Based Radar using Ultrasonic and Servo motor
//**************************************************************************************

/*
 * LearnElectronics India Internship Project
*/

#include <Servo.h>

#define trig 3
#define echo 4

Servo myservo;

int pos = 0;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(9);

  Serial.begin(9600);
  Serial.println("Radar Start");
}

int calculateDistance(){ 
  
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              
    delay(60); 

    distance = calculateDistance();

    Serial.print(pos);
    Serial.print(",");
    Serial.println(distance);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              
    delay(60);  

    distance = calculateDistance();

    Serial.print(pos);
    Serial.print(",");
    Serial.println(distance);
  }
}
