//defineSystem_as_a_one_Variable
typedef struct In_Lock{

  //HCSR04_SECTION

  //SERVER_SECTION

  //SOLENOID_LOCK_SECTION

}IN_LOCK;


//open_tray>>>>>>(FromServerInterrupt)||(Condition)
int _SYS_VALVE(int _sTalk; int height){

  //conditional_Causes
  int max;  
  uint8_t regCon,sInterrupt,SUM_LOGIC;
  if (height>=max) regCon=1;
  else regCon=0;

  //Interrupt_causes
  if( sTalk == /*value*/ )sInterrupt=1;
  else sInterrupt=0;

  //sum_logic
  SUM_LOGIC = sInterrupt+regCon;

  if(SUM_LOGIC>0)return 1;
  else return 0;  
};


void setup(){



  
}

void loop(){
















  
}
