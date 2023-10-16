float tetha, a, g, us = A0, nilai1, nilai2, nilai3, batas1 = 21.0,batas2 = 8.75;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(us,INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  g = analogRead(us);
  if (tetha <= 22,61){
    nilai1 = g*cos(tetha);
    if (nilai1 == 21.0){
      Serial.println("tidak ada benda");
    }else if (nilai1 != 21.0){
      Serial.println("benda terdeteksi");
    }
  }else if (tetha > 22.61){
    if (tetha > 180){
      a = 180 - (90 + tetha);
      nilai2 = g*cos(a);
      if (nilai2 == 8.75){
        Serial.println("benda tidak terdeteksi");
      }else if (nilai2 != 8.75){
        Serial.println("benda terdeteksi");
      }
    }else if (tetha < 180){
      a = 360 - (270 + tetha);
      nilai3 = g*cos(a);
      if (nilai3 == 8.75){
        Serial.println("benda tidak terdeteksi");
      }else if (nilai3 != 8.75){
        Serial.println("benda terdeteksi");
      }


    }
  } 


}
