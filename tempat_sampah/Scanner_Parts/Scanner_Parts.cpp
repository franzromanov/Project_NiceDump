#include "Scanner_Parts.h"
// initiate ------------------------------------------------------------------

// HCSR04_func
// ACTIVATE_HCSR04
void HCSR04_ON(int trig) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}

// conversion_[servoANGLE->realANGLE]
float Change_RealAngle(float *theta) { // change_to_realAngle
  // 90-180
  if (*theta > 90 && *theta <= 180) {
    *theta = (*theta) - 90;
    return 0;
  }
  // 90-0
  if (*theta < 90 && *theta >= 0) {
    *theta = (*theta) + 270;
    return 0;
  }
  // 90
  if (*theta == 90)
    *theta = 0;
  return 0;
}

// HCSR04_SCANNING
void HCSR04_SCANNING(float theta, float *arrCoordinate, HCSR04 Dist, int *state) {
  float a, g, dur, nilai1, batas1 = 13.3, batas2 = 8.5;
  // Distance_measurement_start ---------------------
  HCSR04_ON(Dist.Trig);
  dur = pulseIn(Dist.Echo, HIGH);
  g = (dur * 0.0343) / 2;
  // input_from servo

  // scaleOFservo
  // (90->180 and 90 ->0)

  // REALscale
  // (0->90 and 0->270)

  // conversion
  Change_RealAngle(&theta);
   theta = (theta / 180.0) * PI;

  // checking_condition ------------------------

  // field==>[A,B]
  if (theta >= 0 && theta <= PI/2){

    // A
    if ((theta) <= ((32.58/180.0)*PI)) {
       //Serial.println("A");
      nilai1 = abs(g * cos(theta));
      if (nilai1 >= 15.78) {
        //Serial.println(theta);
        // Serial.println("tidak ada benda");
      } else if (nilai1 < 15.78) {
        // Serial.print(nilai1);

        // assignValueToArray
        for (int i = 0; i < 4; i++) {
          if (i == 0)
            *(arrCoordinate + i) = g;
          if (i == 1)
            *(arrCoordinate + i) = (theta / PI) * 180;
          if (i == 2)
            *(arrCoordinate + i) =  abs(g*sin(theta));
          if (i == 3)
            *(arrCoordinate+i) = nilai1;
        }
        *state = 1;
        //Serial.println("benda terdeteksi");
      }
    }

    // B
    if (theta > ((32.58/180.0)*PI)) {
     // Serial.println("B");
      theta=(PI/2.0) + (theta);
    //  Serial.println(theta);
      nilai1 = cos(theta);
      nilai1=(-1)*nilai1*g;
     // Serial.println(nilai1);
      if (nilai1 >= 8.5) {
        // Serial.print("benda tidak terdeteksi");
        // Serial.println(nilai1);
      } else if ((int)nilai1< 8.5) {
        // assignValueToArray
        for (int i = 0; i < 4; i++) {
          if (i == 0)
            *(arrCoordinate + i) = g;
          if (i == 1)
            *(arrCoordinate + i) = (theta / PI) * 180;
          if (i == 2)
            *(arrCoordinate + i) = nilai1;
	  if (i == 3)
	    *(arrCoordinate+i) = abs(g*sin(theta));
        }
        *state = 1;
        //Serial.println("benda terdeteksi");
        //Serial.println(nilai1);
      }
    }
  }

  // field==>[A',B']
  if (theta >= (270.0/180.0)*PI && theta <= 2*PI) {
   
    //theta = (theta / 180.0) * PI;

    // A'
    if ((theta) >= (337.39/180)*PI) {
       //Serial.println("A-");
      nilai1 = abs(g * cos(theta));
      // Serial.println(theta);
      if (nilai1 >= 15.78) {
        // Serial.print(nilai1);
        // Serial.println("tidak ada benda");
      } else if (nilai1 < 15.78) {
        // assignValueToArray
        for (int i = 0; i < 3; i++) {
          if (i == 0)
            *(arrCoordinate + i) = g;
          if (i == 1)
            *(arrCoordinate + i) = (theta / PI) * 180;
          if (i == 2)
            *(arrCoordinate + i) = abs(g*sin(theta));
          if (i == 3)
            *(arrCoordinate+i) = nilai1;
        }
              *state = 1;
      }

      // Serial.print(nilai1);
      //Serial.println("benda terdeteksi");
    }
  }

  // B'
  if (theta < (337.39/180.0)*PI) {
     //Serial.println("B-");
    nilai1 = abs(g * cos((theta)-((270/180)*PI) ));
     //Serial.println(g);
    if (nilai1 >= 8.5) {
      // Serial.print("benda tidak terdeteksi");
      // Serial.println(nilai1);
    } else if (nilai1 < 8.5) {
      // assignValueToArray
      for (int i = 0; i < 3; i++) {
        if (i == 0)
          *(arrCoordinate + i) = g;
        if (i == 1)
          *(arrCoordinate + i) = (theta / PI) * 180;
        if (i == 2)
          *(arrCoordinate + i) = nilai1;
          if (i == 3)
            *(arrCoordinate+i) = abs(g * sin((theta)-((270/180)*PI) ));
      }
      *state = 1;
      //Serial.println("benda terdeteksi");
      // Serial.println(nilai1);
    }
  }
}


//------MOTOR_SESSION------
void MOVE(Vector displacement,motor* MOTOR_SCANNER,int theta,int bit_op){

	//bit_op::1>>>normal
	//bit_op::0>>>inverted
	//init
	for(int i=0; i<2; i++){

		pinMode(*MOTOR_SCANNER.moto_x[i],LOW);
		pinMode(*MOTOR_SCANNER.moto_y[i],LOW);

	}


	int velocity,pwm_val;
	//INPUT_PWM
	analogWrite(*MOTOR_SCANNER.ENA,pwm_val);
	analogWrite(*MOTOR_SCANNER.ENB,pwm_val);


	//get_time
	*MOTOR_SCANNER.x_time= displacement.x/velocity;
	*MOTOR_SCANNER.y_time= displacement.y/velocity;

	//x_axis
	if(theta<=90 && theta>=0){
		//run
		pinMode(*MOTOR_SCANNER.moto_x[0],~(1^bit_op));
		pinMode(*MOTOR_SCANNER.moto_x[1],~(0^bit_op));
		delay(x_time);


		//stop
        	for(int i=0; i<2; i++){

                	pinMode(*MOTOR_SCANNER.moto_x[i],LOW);


        	}

	}

        //x_axis
        if(theta<=360 && theta>=270){
                //run
                pinMode(*MOTOR_SCANNER.moto_x[0],~(0^bit_op));
                pinMode(*MOTOR_SCANNER.moto_x[1],~(1^bit_op));
                delay(x_time);


                //stop
                for(int i=0; i<2; i++){

                        pinMode(*MOTOR_SCANNER.moto_x[i],LOW);


                }

        }


        //y_axis
	//run
        pinMode(*MOTOR_SCANNER.moto_y[0],~(1^bit_op));
        pinMode(*MOTOR_SCANNER.moto_y[1],~(0^bit_op));
        delay(y_time);


        //stop
        for(int i=0; i<2; i++){

                pinMode(*MOTOR_SCANNER.moto_y[i],LOW);

        }




}



//------WasteTypeCheck------
void WasteCheck(int* correct_waste, waste check_waste){

  int capSensorValue = digitalRead(check_waste.C);
  //Serial.println(capSensorValue);
  int indSensorValue = digitalRead(check_waste.L);
  //Serial.println(indSensorValue);
  if (capSensorValue == HIGH && indSensorValue == HIGH) {
    *correct_waste=1;
    }else{
        *correct_waste=0;
    }
}
