#include "Arduino.h"
//HCSRO4_SESSION-----------------------
//HCSR04_Struct
typedef struct hcsr04{
  int Trig;
  int Echo;

}HCSR04;

//Vector_Struct
typedef struct Vector{
	float x;
	float y;
}Vector;

//WASTE_STRUCT
typedef struct Waste{
	int C;
	int L;
}waste;

//MOTOR_STRUCT
typedef struct Motor{
	int moto_x[2];
	int moto_y[2];
	int ENA;
	int ENB;
	uint32_t x_time;
	uint32_t y_time;
}motor;



//ACTIVATE_HCSR04
void HCSR04_ON(int trig);

//change_to_realAngle
float Change_RealAngle(float *theta);

//activate_HCSR04
void HCSR04_SCANNING(float theta, float *arrCoordinate, HCSR04 Dist,int *state);

//Displacement
void MOVE(Vector displacement,motor* MOTOR_SCANNER,int theta, int bit_op);
//void MOVE_BACKWARD(Vector displacement,motor* MOTOR_SCANNER);

//WASTE_CHECK
void WasteCheck(int* correct_waste, waste check_waste);

//clocked_up
void clock_up(uint32_t *time_start, uint32_t* time_stop, uint32_t second_interval);
