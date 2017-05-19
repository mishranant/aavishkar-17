#include "config.h"
#include "sms.h"
#include "alcohol.h"
#include "gyro.h"
#include "seven.h"
#include "gear.h"
#include "bcd.h"
#include "functions.h"
#include "move.h"

  void setup() 
  {
    setupSonar();
    setupMove();
    setupGyro();
    setupSeven();
    setupAlcohol();
    setupGSM();
    setupBeep();
  }
  
  void loop() 
  {
      /*updateGyro();
      if(alcohol())
      {
          beep(1);
      }
      else
      {*/
          if(!BCDloop())
          {
              Serial.println("collision is imminent");
          }
          else
          {
            movementProcess();
          }
     // }*/
  }
