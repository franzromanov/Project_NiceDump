#include <Scanner_Parts.h>
#include <Servo.h>
#include <math.h>


//angle_converter
int deg(float Ang){
  float deg_=(180/PI)*Ang;
  return (int)deg_;
  }

//declare
HCSR04 Dist={9,10};//HCSR04_STRUCT
float arrCoordinate[3];
int motox_pin[2]={2,3};
int motoy_pin[2]={4,5};
int state=1,start_scan=1,deg_,correct_waste=0;
float to_ = 0, t_, To_ = 60; // Set your time interval to 60 seconds
float time_up = 0; // Track the last reset time
float Ang;
Servo serv,valve;//SERVO_STRUCT
Vector displace;//VECTOR_STRUCT
waste check_waste={7,8};//WASTE_STRCUCT

void setup() {

  for(int i=0;i<2;i++){
    
    if(i==0)
      pinMode(Dist.Trig,OUTPUT);
      pinMode(check_waste.C,INPUT);
    if(i==1)
      pinMode(Dist.Echo, INPUT);
      pinMode(check_waste.L,INPUT);
    
    }
  Serial.begin(9600);
  serv.attach(3);
  valve.attach(5);
  //initiate
  serv.write(90);
  delay(1000);
  valve.write(105);
  
  //////MOTOR_PIN//////
  for(int i=0; i<2;i++){
    
    //MOTOR_X
    pinMode(motox_pin[i],OUTPUT);
    //MOTOR_Y    
    pinMode(motoy_pin[i],OUTPUT);
     
    }

}

void loop(){
  //serv.write(0);


//HCSR04_SCANNER_SESSION---------------------------------------------------------
/*
  if(start_scan==1){
  while(state!=1){
  
          while(state!=1){
            
            //rotate_right
            //generate_time
            t_=millis();
            to_=((t_-time_up)/1000)*15;
          
            //Angle_management
            Ang=(((2*PI)/To_)*(to_))+(PI/2);
            deg_=deg(Ang);
            HCSR04_SCANNING((float)deg_,arrCoordinate,Dist,&state);
            Serial.println(deg_);
            Serial.print(arrCoordinate[0]);
            Serial.print("::::::");
            Serial.println(arrCoordinate[1]);        ;
            Serial.print("::::::");
            Serial.println(arrCoordinate[2]);  
            //Serial.println(to_);
            //servo_section
            serv.write(deg_);
            if(to_>=(To_/4)||deg_>=180){
              Serial.print("time:");
              Serial.println(to_);
              //Serial.print(arrCoordinate[0]);
              //Serial.println(arrCoordinate[1]);
              to_=0;
              time_up=t_;  
              break;    
              }
              
            }
          
            while(state!=1){
              //rotate_left
            //generate_time
            t_=millis();
            to_=((t_-time_up)/1000)*15;
          
            //Angle_management
            Ang=(PI/2)-(((2*PI)/To_)*(to_));
            deg_=deg(Ang);
            HCSR04_SCANNING((float)deg_,arrCoordinate,Dist,&state);
            Serial.println(deg_);
            Serial.print(arrCoordinate[0]);
            Serial.print("::::::");
            Serial.println(arrCoordinate[1]);        ;
            Serial.print("::::::");
            Serial.println(arrCoordinate[2]);  
            
            //Serial.println(deg_);
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
  start_scan=0;
  }
  */


/*
//MOTOR_MOVEMENT_SESSION------------------
  displace.x = arrCoordinate[2]*cos((arrCoordinate[1]/180)*PI);
  displace.y = arrCoordinate[2]*sin((arrCoordinate[1]/180)*PI);
/*
  //define motor
  motor MOTOR_CTRL;
  for(int i=0;i<2;i++){
    MOTOR_CTRL.moto_x[i]=motox_pin[i];
    MOTOR_CTRL.moto_y[i]=motoy_pin[i];
  }
  MOTOR_CTRL.velo_x=;
  MOTOR_CTRL.velo_y=;

  //To_obj
  MOVE(displace,&MOTOR_CTRL,false);

*/

//WASTE_CHECK_SESSION
  WasteCheck(&correct_waste, check_waste);
/*
  //To_starting_point
  MOVE(displace,&MOTOR_CTRL,true);
*/




//VALVE_SESSION----------------------------

  if(state==1 && correct_waste==1){
  // Wait for 1 second
    valve.write(180);
    delay(2000); // Wait for 1 second
    valve.write(105);
    //state=0;
    }



}
