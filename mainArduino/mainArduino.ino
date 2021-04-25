/*  _________________________________________________________________________
    |                     Robotic Arm project (RARM)                        |
    -------------------------------------------------------------------------
    |------------------------Supervisor: Dr.Chan----------------------------|
    |----------------------Student: Lưu Quang Minh--------------------------|
    |------------------Built for Senior project at VGU----------------------|
    |-------All Algorithms and Codes are created by Luu Quang Minh----------|
    |-------------------------Updated on Github:----------------------------|
    |------https://github.com/minminlittleshrimp/RARM_senior_project--------|
    |--------------------Built for non-commercial use-----------------------|
    |_______________________________________________________________________|
*/
#include<stdint.h>
#include <Servo.h>

//Servo list
Servo Joint1,Joint2,Joint3;
Servo Gripper,Turning,Rotate;

char buff;

//Max & Min rotation
#define Joint1DH 140
#define Joint1DL 50

#define Joint2DH 160
#define Joint2DL 20

#define Joint3DH 160
#define Joint3DL 50

#define TurningDH 170
#define TurningDL 20

#define RotateDH 180
#define RotateDL 0

#define GripperDH 180
#define GripperDL 125

//--------------------------------------------------//

//Global Variable
uint8_t StepX=1;
uint8_t _DegJoint1=100,_DegJoint2=80,_DegJoint3=60;
uint8_t _DegGripper=30,_DegTurning=90,_DegRotate=90;

//Function for each Servo
//------------------Joint1-------------------------//
uint8_t __Joint1(uint8_t _TempDegJoint1)
{
  if(_TempDegJoint1>_DegJoint1)
  {
  _DegJoint1 += StepX;
//Max rotation
  if(_DegJoint1>Joint1DH)
  _DegJoint1=Joint1DH;
  Joint1.write(_DegJoint1);
  delay(10);
  return 2;
  }
  else if(_TempDegJoint1<_DegJoint1)
  {
  _DegJoint1 -= StepX;
//Min rotation
  if(_DegJoint1<Joint1DL)
  _DegJoint1=Joint1DL;
  Joint1.write(_DegJoint1);
  delay(10);
  return 1;
  }
  else {Joint1.write(_DegJoint1);return 0;}
}

//------------------Joint2-------------------------//
uint8_t __Joint2(uint8_t _TempDegJoint2)
{
  if(_TempDegJoint2>_DegJoint2)
  {
  _DegJoint2 += StepX;
//Max rotation
  if(_DegJoint2>Joint2DH)
  _DegJoint2=Joint2DH;
  Joint2.write(_DegJoint2);
  delay(20);
  return 2;
  }
  else if(_TempDegJoint2<_DegJoint2)
  {
  _DegJoint2 -= StepX;
//Min rotation
  if(_DegJoint2<Joint2DL)
  _DegJoint2=Joint2DL;
  Joint2.write(_DegJoint2);
  delay(20);
  return 1;
  }
  else {Joint2.write(_DegJoint2);return 0;}
}

//------------------Joint3-------------------------//
uint8_t __Joint3(uint8_t _TempDegJoint3)
{
  if(_TempDegJoint3>_DegJoint3)
  {
  _DegJoint3 += StepX;
//Max rotation
  if(_DegJoint3>Joint3DH)
  _DegJoint3=Joint3DH;
  Joint3.write(_DegJoint3);
  delay(10);
  return 2;
  }
  else if(_TempDegJoint3<_DegJoint3)
  {
  _DegJoint3 -= StepX;
//Min rotation
  if(_DegJoint3<Joint3DL)
  _DegJoint3=Joint3DL;
  Joint3.write(_DegJoint3);
  delay(10);
  return 1;
  }
  else {Joint3.write(_DegJoint3);return 0;}
}

//------------------Gripper-------------------------//
uint8_t __Gripper(uint8_t _TempDegGripper)
{
  if(_TempDegGripper>_DegGripper)
  {
  _DegGripper += StepX;
//Max rotation
  if(_DegGripper>GripperDH)
  _DegGripper=GripperDH;
  Gripper.write(_DegGripper);
  delay(10);
  return 2;
  }
  else if(_TempDegGripper<_DegGripper)
  {
  _DegGripper -= StepX;
//Min rotation
  if(_DegGripper<GripperDL)
  _DegGripper=GripperDL;
  Gripper.write(_DegGripper);
  delay(10);
  return 1;
  }
  else {Gripper.write(_DegGripper); return 0;}
}

//------------------Turning-------------------------//
uint8_t __Turning(uint8_t _TempDegTurning)
{
  if(_TempDegTurning>_DegTurning)
  {
  _DegTurning += StepX;
//Max rotation
  if(_DegTurning>TurningDH)
  _DegTurning=TurningDH;
  Turning.write(_DegTurning);
  delay(10);
  return 2;
  }
  else if(_TempDegTurning<_DegTurning)
  {
  _DegTurning -= StepX;
//Min rotation
  if(_DegTurning<TurningDL)
  _DegTurning=TurningDL;
  Turning.write(_DegTurning);
  delay(10);
  return 1;
  }
  else {Turning.write(_DegTurning); return 0;}
}

//------------------Rotate-------------------------//
uint8_t __Rotate(uint8_t _TempDegRotate)
{
  if(_TempDegRotate>_DegRotate)
  {
  _DegRotate += StepX;
//Max rotation
  if(_DegRotate>RotateDH)
  _DegRotate=RotateDH;
  Rotate.write(_DegRotate);
  delay(10);
  return 2;
  }
  else if(_TempDegRotate<_DegRotate)
  {
  _DegRotate -= StepX;
//Min rotation
  if(_DegRotate<RotateDL)
  _DegRotate=RotateDL;
  Rotate.write(_DegRotate);
  delay(10);
  return 1;
  }
  else {Rotate.write(_DegRotate);return 0;}
}

//----------------Main code for control 6 servos--------------//
void setup()
{
  Serial.begin(9600);
  Serial.println("D6ARMv01");

//Set servos to pins
  
  Turning.attach(11);
  Joint3.attach(10);
  Joint2.attach(9);
  Joint1.attach(6);
  Rotate.attach(5);
  Gripper.attach(3);

//Set all check-variable-->.write(); return 0;

  __Joint1(70);
  __Joint2(70);
  __Joint3(70);
  __Gripper(130);
  __Turning(90);
  __Rotate(90);
}
void loop()
{

//Variable to increase by StepX in rotation
  uint8_t TempJoint1,TempJoint2, TempJoint3;
  uint8_t TempGripper, TempTurning, TempRotate;
  uint8_t StepJoint1, StepJoint2, StepJoint3;
  uint8_t StepGripper, StepTurning, StepRotate;

  if(Serial.available()>0)
  {
    buff=Serial.read();
    Serial.print(buff);
    Serial.print(">>");
    switch(buff)
    {  
    //A and a: control Joint1
    
    case'A':
    StepJoint1=_DegJoint1+StepX;
    TempJoint1=__Joint1(StepJoint1);
    Serial.print("+Deg:");Serial.print(_DegJoint1);
    Serial.print(" S:");Serial.println(TempJoint1); break;
  
    case'a':
    StepJoint1=_DegJoint1-StepX;
    TempJoint1=__Joint1(StepJoint1);
    Serial.print("-Deg:");Serial.print(_DegJoint1);
    Serial.print(" S:");Serial.println(TempJoint1); break;
    
    //B and b: control Joint2

    case'B':
    StepJoint2=_DegJoint2+StepX;
    TempJoint2=__Joint2(StepJoint2);
    Serial.print("+Deg:");Serial.print(_DegJoint2);
    Serial.print(" S:");Serial.println(TempJoint2); break;
    
    case'b':
    StepJoint2=_DegJoint2-StepX;
    TempJoint2=__Joint2(StepJoint2);
    Serial.print("-Deg:");Serial.print(_DegJoint2);
    Serial.print(" S:");Serial.println(TempJoint2); break;

    //C and c: control Joint3
  
    case'c':
    StepJoint3=_DegJoint3+StepX;
    TempJoint3=__Joint3(StepJoint3);
    Serial.print("+Deg:");Serial.print(_DegJoint3);
    Serial.print(" S:");Serial.println(TempJoint3); break;
    
    case'C':
    StepJoint3=_DegJoint3-StepX;
    TempJoint3=__Joint3(StepJoint3);
    Serial.print("-Deg:");Serial.print(_DegJoint3);
    Serial.print(" S:");Serial.println(TempJoint3); break;

    //G and g: control Gripper

    case'G':
    StepGripper=_DegGripper+StepX;
    TempGripper=__Gripper(StepGripper);
    Serial.print("+Deg:");Serial.print(_DegGripper);
    Serial.print(" S:");Serial.println(TempGripper); break;
    
    case'g':
    StepGripper=_DegGripper-StepX;
    TempGripper=__Gripper(StepGripper);
    Serial.print("-Deg:");Serial.print(_DegGripper);
    Serial.print(" S:");Serial.println(TempGripper); break;

    //T and t: control Turning 

    case'T':
    StepTurning=_DegTurning+StepX;
    TempTurning=__Turning(StepTurning);
    Serial.print("+Deg:");Serial.print(_DegTurning);
    Serial.print(" S:");Serial.println(TempTurning); break;
    
    case't':
    StepTurning=_DegTurning-StepX;
    TempTurning=__Turning(StepTurning);
    Serial.print("-Deg:");Serial.print(_DegTurning);
    Serial.print(" S:");Serial.println(TempTurning); break;

    //R and r: control Rotate

    case'R':
    StepRotate=_DegRotate+StepX;
    TempRotate=__Rotate(StepRotate);
    Serial.print("+Deg:");Serial.print(_DegRotate);
    Serial.print(" S:");Serial.println(TempRotate); break;
    
    case'r':
    StepRotate=_DegRotate-StepX;
    TempRotate=__Rotate(StepRotate);
    Serial.print("-Deg:");Serial.print(_DegRotate);
    Serial.print(" S:");Serial.println(TempRotate); break;

    case'S':
    StepX++;
    if(StepX>10) StepX=10;
    break;

    case's':
    StepX--;
    if(StepX<1) StepX=1;
    break;
    
    default: break;
    }
  }
}
