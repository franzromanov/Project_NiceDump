#include <Servo.h>
#define PORT 1

//input_system_
int IR[PORT]={13};

//actuator_
/*
 Servo

*/

//object_scanner[Ultrasonic_proximity]
void SCAN_ON(){}

void setup(){

  for(int i=0; i<PORT; i++)pinMode(IR[i],OUTPUT);

  }

void loop(){
	for(int i=0; i<PORT; i++){
		IR_val=digitalRead();
		if(IR_val==LOW)SCAN_ON();
	}else;

}
