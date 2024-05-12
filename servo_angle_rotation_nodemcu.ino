#include <Servo.h>
Servo servo1;
int servoPin = 2;
int Dir = D3;
int Pul= D2;
int arc = 15;
int pd = 100;

void setup(){
  Serial.begin(9600);
  servo1.attach(servoPin);
  pinMode(Dir, OUTPUT);
  pinMode(Pul, OUTPUT);
}

void loop(){
  float s = 6.37*arc;
  int steps = round(s);
  servo1.write(0);
  delay(1500);
  
  for(int i = 0; i <= steps; i++)
  { 
    Serial.println(i);
    digitalWrite(Dir, HIGH);
    delayMicroseconds(pd);
    digitalWrite(Pul, HIGH);
    delayMicroseconds(pd);
    digitalWrite(Pul, LOW);
    delayMicroseconds(pd);
  }
  delay(500);
  servo1.write(180);
  delay(1500);

  // for(int i = 0; i <= 5; i++)
  // { 
  //   Serial.println(i);
  //   digitalWrite(Dir, LOW);
  //   delayMicroseconds(pd);
  //   digitalWrite(Pul, HIGH);
  //   delayMicroseconds(pd);
  //   digitalWrite(Pul, LOW);
  //   delayMicroseconds(pd);
  // }
  
}