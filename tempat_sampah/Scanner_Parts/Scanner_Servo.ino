#include <Servo.h>
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
  //initiate
  serv.write(90);
  delay(1000);
  
  
}

void loop() {
  //serv.write(0);



while(1){
  
  //rotate_right
  //generate_time
  t_=millis();
  to_=((t_-time_up)/1000)*15;

  //Angle_management
  Ang=(((2*PI)/To_)*(to_))+(PI/2);
  deg_=deg(Ang);
  Serial.println(deg_);
  //Serial.println(to_);
  //servo_section
  serv.write(deg_);
  if(to_>=(To_/4)||deg_>=180){
    Serial.print("time:");
    Serial.println(to_);
    to_=0;
    time_up=t_;  
    break;    
    }
    
  }

  while(1){
    //rotate_left
  //generate_time
  t_=millis();
  to_=((t_-time_up)/1000)*15;

  //Angle_management
  Ang=(PI/2)-(((2*PI)/To_)*(to_));
  deg_=deg(Ang);
  Serial.println(deg_);
  //Serial.println(to_);
  //servo_section
  serv.write(deg_);
  if(to_>(To_/4)){
    Serial.print("time:");
    Serial.println(to_);
    to_=0;
    time_up=t_;  
    break;
    
    }
  }
  
  
}
