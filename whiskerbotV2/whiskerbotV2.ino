#include<Servo.h>
Servo servoLeft;
Servo servoRight;
int wRight = 7;
int wLeft = 5;

void setup( ){
  servoLeft.attach(13);
  servoRight.attach(12);
  
  pinMode(7, INPUT);
  pinMode(5, INPUT);
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
  
  Serial.begin(9600);
  
  tone(4,3000,1000);
  delay(1000);
  
}

void loop( ){
  
  byte wRightVal = digitalRead(7);
  byte wLeftVal = digitalRead(5);
  
  if(wRightVal == 0 && wLeftVal == 0){
    digitalWrite(8,HIGH);
    digitalWrite(2,HIGH);
    backward(1000);
    turnRight(1000);
    
    
  }
  
  else if(wRightVal == 0){
    digitalWrite(8,HIGH);
    backward(1000);
    turnRight(1000);

    
  }
  
  else if(wLeftVal == 0){
    digitalWrite(2,HIGH);
    backward(1000);
    turnLeft(1000);

  }
  
  else{
    forward(200);
    digitalWrite(8,LOW);
    digitalWrite(2,LOW);
    
  }
  
}

void backward(int time){
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(time);
}

void forward( int time){
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(time);
}

void turnLeft( int time){
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
  delay(time);
}

void turnRight( int time){
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
  delay(time);
  
}


