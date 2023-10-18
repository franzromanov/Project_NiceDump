//initiate------------------------------------------------------------------
//declare_Var
float tetha, a, g,dur, nilai1, nilai2, nilai3, batas1 = 21.0,batas2 = 8.75;

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
  g = (dur*.0343)/2;;
  tetha=10;

  //checking_condition------------------------
  if (tetha >= 67.39||tetha <= 112.61){
    nilai1 =abs( g*cos(tetha-90));
   
    if (nilai1 >= 21.0){
      Serial.print(nilai1);
      Serial.println("tidak ada benda");
    }else if (nilai1 < 21.0){
      Serial.print(nilai1);
      Serial.println("benda terdeteksi");
    }
  }else if ( tetha < 67.39 || tetha > 112.61 ){
    
      nilai2 = abs(g*cos(tetha-90));
      if (nilai2 >=  8.75){
        Serial.println("benda tidak terdeteksi");
      }else if (nilai2 < 8.75){
        Serial.println("benda terdeteksi");

}
} 
}
