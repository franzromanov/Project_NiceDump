o#include <Servo.h>
#include <math.h>

//angle_converter
int deg(float Ang){

  float deg_=(180/PI)*Ang;
  
  return (int)deg_;
  }
 

//declare
float to_ = 0, t_, To_ = 60; // Set your time interval to 60 seconds
float time_up = 0; // Track the last reset time
int deg_;
float Ang;
Servo serv;



void setup() {
  Serial.begin(9600);
  serv.attach(3);
  
}

void loop() {
  
  //generate_time
  t_=millis();
  to_=((t_-time_up)/1000)*15;

  //Angle_management
  Ang=(((2*PI)/To_)*(to_));
  deg_=deg(Ang);
  Serial.println(deg_);
  //Serial.println(to_);

  if(to_>(To_/2)){
    Serial.println(to_);
    to_=0;
    time_up=t_;  
    
    }
