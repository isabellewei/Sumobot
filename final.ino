#include "Timer.h"
Timer t;

//global variable declarations
int IRpin = 4; 
int line1pin = 0;
int line2pin = 1;
//motor1
int InA1 = 12;
int InB1 = 13;
int En1 = 11;
//motor2
int InA2 = 8;
int InB2 = 7;
int En2 = 6;

float dis;
int front;
int back;

//function declarations
void IR_sensor();
void check();
void straight();
void backwards();
void spinLeft();
void off();
  

void setup(){
  //Serial.begin(9600); 
  
  pinMode(InA1, OUTPUT);
  pinMode(InB1, OUTPUT);
  pinMode(En1, OUTPUT);

  pinMode(InA2, OUTPUT);
  pinMode(InB2, OUTPUT);
  pinMode(En2, OUTPUT);

  delay(3000); //bot must wait 3 secs before moving

  t.every(100,check);    //checks sensors and acts accordingly every 1/10s
  
}

void loop(){
  t.update();
 }

void check(){
  front = analogRead(line1pin);
  back = analogRead(line2pin);
  dis = analogRead(IRpin);

  if(front > 800){
    straight();
  }
  else if(back > 800){
    backwards();
  }
  else if(dis < 400){
    straight();  
  }
  else{
    spinLeft();
  }
  
  
}

void straight(){
  digitalWrite(En1, HIGH);
  digitalWrite(InA1, LOW);
  digitalWrite(InB1, HIGH);

  digitalWrite(En2, HIGH);
   digitalWrite(InA2, LOW);
  digitalWrite(InB2, HIGH);

}

void backwards(){
  digitalWrite(En1, HIGH);
  digitalWrite(InA1, HIGH);
  digitalWrite(InB1, LOW);

  digitalWrite(En2, HIGH);
  digitalWrite(InA2, HIGH);
  digitalWrite(InB2, LOW);
}

void spinLeft(){
  digitalWrite(En1, HIGH);
  digitalWrite(InA1, LOW);
  digitalWrite(InB1, HIGH);

  digitalWrite(En2, HIGH);
  digitalWrite(InA2, HIGH);
  digitalWrite(InB2, LOW);

}

void off(){
  digitalWrite(En1, LOW);
  digitalWrite(En2, LOW);
}


//  int dis = 0;
//  int averaging = 0;             //  Holds value to average readings
//  // Get a sampling of 5 readings from sensor
//  for (int i=0; i<5; i++) {
//    dis = analogRead(IRpin);
//    averaging = averaging + dis;
//    delay(20); 
// }
//   distance = averaging / 5;      // Average out readings
//   distance = pow(3027.4/distance, 1.2134);
//   Serial.print("cm: ");                   
//   Serial.print(distance);
//}
//
//void line_sensor1 (){ 
//  front = analogRead(line1pin);
//  Serial.print(" line1: ");
//  Serial.print (front);
//}
//
//void line_sensor2(){
//  back = analogRead(line2pin);
//  Serial.print(" line2: ");
//  Serial.println(back);
//}

