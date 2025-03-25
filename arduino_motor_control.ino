#include <AFMotor.h>
#include <SoftwareSerial.h>
#include "timer.h"

Timer timer;
const int LM393 = 2;
int counter = 0;
float distancePerRevolution = 0.6; 
float secondsPerMinute = 60.0;

SoftwareSerial bluetooth(1, 0); // RX, TX
#define trigPin 26
#define echoPin 24

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 
char _buffercommand;

void setup() {
  Serial.begin(9600);       
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Motor Kontrolü, Bluetooth ve Ultrasonik Sensör!"); 

  attachInterrupt(digitalPinToInterrupt(LM393), count, RISING);
  timer.setInterval(1000);
  timer.setCallback(RPM);
  timer.start();
}

void count() {
  counter++;
}

void RPM() {
  float revolutionsPerMinute = counter;
  float speed = (revolutionsPerMinute * distancePerRevolution) / secondsPerMinute;
  
  Serial.print("Hiz: ");
  Serial.print(speed);
  Serial.println(" m/s");
  counter = 0;
}

void loop() {
  timer.update();
  long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(1500);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1500);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) * 0.0343;
    
    Serial.print("Mesafe: ");
    Serial.print(distance);
    Serial.println(" cm");
    

    command = Serial.read();
    if(command=='B' || command=='L' || command=='R' || command=='F' || command=='S'){
        _buffercommand=command;
      }

    switch(_buffercommand){  
    case 'F':  
      forward();
      break;
    case 'B':
      if (distance < 10) {
        stop();
        Serial.print("Mesafe: ");
        Serial.print(distance);
        Serial.println(" cm - Dur!");
        delay(1000);
        
    } else{
        back();
    }
    break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'S':
      stop();
      break;
    }

}

void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(FORWARD);  
  motor4.setSpeed(255); 
  motor4.run(FORWARD);  
}

void right()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
} 

void stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0);
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
  Serial.print("durduruldu");
}