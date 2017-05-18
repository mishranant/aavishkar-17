unsigned long currentMillis = 0, prevMillis = 0, deltaTime = 0;
const int buzzer = 9; //buzzer to arduino pin 9
float duration, distMax;
//Change pins
int sonarPins[8][2] = 
{
  {5, 6},
  {9, 10},
  {9, 10},
  {9, 10},
  {9, 10},
  {9, 10},
  {9, 10},
  {9, 10}
};


// This is how close the car is allowed to get to the obstacle
const int frontThreshold = 10, frontMax = 30;
const int backThreshold = 3, backMax = 10;
const int sideThreshold = 5, sideMax = 15;

float sonar1 = 0, sonar1Prev = 0, sonar2 = 0, sonar2Prev = 0, sonar3 = 0, sonar3Prev = 0, sonar4 = 0, sonar4Prev = 0, sonar5 = 0, sonar5Prev = 0, sonar6 = 0, sonar6Prev = 0, sonar7 = 0, sonar7Prev = 0, sonar8 = 0, sonar8Prev = 0;

bool parking = false, active = false, pf = 0, turning = false;

void setThreshold()
{
  //set global threshold values
  if(pf==1)pf = 0;
  else pf = 1;
}

float readSonar(int i)
{
  digitalWrite(sonarPins[i-1][0], LOW);
  delayMicroseconds(2);
  digitalWrite(sonarPins[i-1][0], HIGH);//triggering the sonar to emit an ultrasonic wave
  delayMicroseconds(5);
  digitalWrite(sonarPins[i-1][0], LOW);//it is actually triggered at this instant
  
  duration = pulseIn(sonarPins[i-1][1], HIGH ,((distMax+13)*2.0)/.034 );//time taken by reflected wave to be detected
  if (duration == 0) return -1.0;//object was out of range
  else {
    return (duration*0.034)/2.0;
  }
}

void readSides()
{
  sonar2Prev = sonar2;
  sonar2 = readSonar(2);
  sonar4Prev = sonar4;
  sonar4 = readSonar(4);
  sonar6Prev = sonar6;
  sonar6 = readSonar(6);
  sonar8Prev = sonar8;
  sonar8 = readSonar(8);
}

void readCorners()
{
  sonar1Prev = sonar1;
  sonar1 = readSonar(1);
  sonar3Prev = sonar3;
  sonar3 = readSonar(3);
  sonar5Prev = sonar5;
  sonar5 = readSonar(5);
  sonar7Prev = sonar7;
  sonar7 = readSonar(7);
}

void BCDloop()
{
  if(active)
  {
    prevMillis = currentMillis;
    currentMillis = millis();
    deltaTime = currentMillis - prevMillis;
    if(parking)
    {
      if(!pf) setThreshold();
      readSides();
      checkFront();
      checkBack();
      //checkSideParking(); 
    }
    else
    {
      if(pf) setThreshold();
      readSides();
      checkFront();
      checkBack();
      checkSide(sonar4, sonar4Prev);
      checkSide(sonar7, sonar7Prev);
      if(turning)
      {
        sonar1 = readSonar(1);
        sonar3 = readSonar(3);
        sonar5 = readSonar(5);
        sonar7 = readSonar(7);
        checkLaneChange();
      }
    }
  }
}

void checkFront()
{
  if(sonar2 < frontMax)
  {
    if(sonar2 < frontThreshold)
    {
      beep(1);
      //ApplyBrakes();
    }
    else
    {
      if((sonar1Prev - sonar1)/deltaTime > 5)
      {
        beep(1);
      }
    }
  }
}

void checkBack()
{
  if(sonar6 < backMax)
  {
    if(sonar6 < backThreshold)
    {
      beep(1);
    }
    else
    {
      if((sonar6Prev - sonar6)/deltaTime > 5)
      {
        beep(1);
      }
    }
  }
}

void checkSide(int d, int dPrev)
{
  if(d < sideMax)
  {
    if(d < sideThreshold)
    {
      beep(1);
    }
    else
    {
      if((dPrev - d)/deltaTime > 5)
      {
        beep(1);
      }
    }
  }
}

void checkLaneChange()
{
  if(sonar1 < frontThreshold)
  {
    beep(1);
    //if(sonar1Prev > sonar1) Break();
  }
  else if(sonar1 < frontMax)
  {
    float rv = (sonar1Prev - sonar1)/deltaTime;
    if(rv > 30)
    {
      beep(1);
      //Break();
    }
    else if(rv > 20)
    {
      beep(1);
    }
  }
  if(sonar3 < frontThreshold)
  {
    beep(1);
    //if(sonar3Prev > sonar3) Break();
  }
  else if(sonar3 < frontMax)
  {
    float rv = (sonar1Prev - sonar3)/deltaTime;
    if(rv > 30)
    {
      beep(1);
      //Break();
    }
    else if(rv > 20)
    {
      beep(1);
    }
  }
  if(sonar7 < backThreshold)
  {
    beep(1);
    //Break();
  }
  else if(sonar7 < backMax)
  {
    float rv = (sonar7Prev - sonar7)/deltaTime;
    if(rv > 30)
    {
      beep(1);
    }
    else if(rv > 20)
    {
      beep(1);
    }
  }
  if(sonar5 < backThreshold)
  {
    beep(1);
    //Break();
  }
  else if(sonar5 < backMax)
  {
    float rv = (sonar5Prev - sonar5)/deltaTime;
    if(rv > 30)
    {
      beep(1);
    }
    else if(rv > 20)
    {
      beep(1);
    }
  }
}

void beep(int a)
{
  //int a;
  int i;
  //a=2;

 if(a==1)
 {
    for(i=0;i<1;i++)
    {
        tone(buzzer, 1000); 
        delay(20);        
         noTone(buzzer);
         delay(20);
      }
  }
  else if(a==2)
  {
    for(i=0;i<1;i++){
    tone(buzzer, 1500); 
        delay(50);        
         noTone(buzzer);
         delay(50);
    }
    }
    else if(a==3)
    {
       for(i=0;i<1;i++)
       {
    tone(buzzer, 400); 
        delay(75);        
         noTone(buzzer);
         delay(75);
    }
    }
  
  }
