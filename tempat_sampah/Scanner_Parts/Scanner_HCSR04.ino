//initiate------------------------------------------------------------------
//declare_Var
float theta,a, g,dur, nilai1, batas1 = 21.0,batas2 = 8.75;

typedef struct hcsr04 {
  int Trig;
  int Echo;
  
}HCSR04;

HCSR04 Dist={9,10};

//HCSR04_func
//ACTIVATE_HCSR04
void HCSR04_ON(int trig){

  digitalWrite(trig, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trig, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trig, LOW);
  
}

//conversion_[servoANGLE->realANGLE]
float Change_RealAngle(float *theta){        //change_to_realAngle

 
 //90-180
 if(*theta > 90 && *theta<=180){*theta=(*theta)-90;return 0;}
 //90-0
 if(*theta < 90 && *theta>=0){*theta=(*theta)+270;return 0;}
 //90
 if(*theta==90)*theta=0;
 return 0;
   
  }

//--------------------------------------------------------
void setup() {
  
  Serial.begin(9600);
  pinMode(Dist.Trig,OUTPUT);
  pinMode(Dist.Echo,INPUT);

}

void loop() {
  //Distance_measurement_start---------------------
  HCSR04_ON(Dist.Trig);
  dur = pulseIn(Dist.Echo, HIGH);
  g = (dur*.0343)/2;
  theta=0;//input_from servo

  //scaleOFservo
  //(90->180 and 90 ->0)
  
  //REALscale
  //(0->90 and 0->270)

  //conversion
  
  Change_RealAngle(&theta);

  //checking_condition------------------------
 
 // Serial.println(theta);
  if(theta>=0 && theta<=90){

    
    

   // Serial.println(cos(*theta));
    if((theta)<=22.61){
       nilai1 =abs(g*cos(theta));
    if (nilai1 >= 21.0){
      Serial.print(nilai1);
      Serial.println("tidak ada benda");
    }else if (nilai1 < 21.0){
      Serial.print(nilai1);
      Serial.println("benda terdeteksi");
      
      }
      }

    //B_Field:66
    if(theta>22.61){
      nilai1 =abs(g*cos(90-(theta)));
      
      if (nilai1>=  8.75){
        Serial.print("benda tidak terdeteksi");
        Serial.println(nilai1);
        
      }else if (nilai1 < 8.75){
        Serial.print("benda terdeteksi");
        Serial.println(nilai1);
        
    
    }    
    }
    
  }
  
 if(theta>=270 && theta<=360){

    
    //Serial.println(theta);

   // Serial.println(cos(theta));
    if((theta)>=337.39){
       nilai1 =abs(g*cos(theta));
    if (nilai1 >= 21.0){
      Serial.print(nilai1);
      Serial.println("tidak ada benda");
    }else if (nilai1 < 21.0){
      Serial.print(nilai1);
      Serial.println("benda terdeteksi");
   
      }
      }

    //B_Field:66
    if(theta<337.39){
      nilai1 =abs(g*cos(270-(theta)));
      if (nilai1>=  8.75){
        Serial.print("benda tidak terdeteksi");
        Serial.println(nilai1);
        
      }else if (nilai1 < 8.75){
        Serial.print("benda terdeteksi");
        Serial.println(nilai1);
        
    
    }    
    }
    
  }

}
