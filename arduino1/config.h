/**
 * Pin definitions
 */

 //MOTORS motor 1 : front ; 2 : back
  int leftMotor11 = 0;
  int leftMotor11 = 0;
  
  int leftMotor21 = 0;
  int leftMotor22 = 0;
  
  int rightMotor11 = 0;
  int rightMotor12 = 0;
  
  int rightMotor21 = 0;
  int rightMotor22 = 0;

 //MOTOR calibration
  int leftMotor1Value = 0;
  int leftMotor2Value = 0;
  int rightMotor1Value = 0;
  int rightMotor2Value = 0;

typedef struct sonar{
  const int trigpin, echopin;
  float distmax;
}sonar;
sonar sonars[8];

sonars[0].trigpin = 9;
sonars[0].echopin = 10;
sonars[0].distmax = 30.0;

sonars[1].trigpin = 9;
sonars[1].echopin = 10;
sonars[1].distmax = 30.0;

sonars[2].trigpin = 9;
sonars[2].echopin = 10;
sonars[2].distmax = 30.0;

sonars[3].trigpin = 9;
sonars[3].echopin = 10;
sonars[3].distmax = 30.0;

sonars[4].trigpin = 9;
sonars[4].echopin = 10;
sonars[4].distmax = 30.0;

sonars[5].trigpin = 9;
sonars[5].echopin = 10;
sonars[5].distmax = 30.0;

sonars[6].trigpin = 9;
sonars[6].echopin = 10;
sonars[6].distmax = 30.0;

sonars[7].trigpin = 9;
sonars[7].echopin = 10;
sonars[7].distmax = 30.0;


  
