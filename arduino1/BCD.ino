unsigned long currentMillis = 0, prevMillis = 0, deltaTime = 0;

const int frontThreshold = 10, frontMax = 30;
const int backThreshold = 3, backMax = 10;
const int sideThreshold = 5, sideMax = 15;

int sonar1 = 0, sonar1Prev = 0, sonar2 = 0, sonar2Prev = 0, sonar3 = 0, sonar3Prev = 0, sonar4 = 0, sonar4Prev = 0, sonar5 = 0, sonar5Prev = 0, sonar6 = 0, sonar6Prev = 0, sonar7 = 0, sonar7Prev = 0, sonar8 = 0, sonar8Prev = 0;

bool parking = false, active = false, pf = 0, turning = false;

void setThreshold()
{
  //set global variables
  if(pf==1)pf = 0;
  else pf = 1;
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
      readSonar(2);
      readSonar(4);
      readSonar(6);
      readSonar(8);
      checkFront();
      checkBack();
      checkSideParking(); 
    }
    else
    {
      if(pf) setThreshold();
      readSonar(2);
      readSonar(4);
      readSonar(6);
      readSonar(8);
      checkFront();
      checkBack();
      checkSide();
      if(turning)
      {
        readSonar(1);
        readSonar(3);
        readSonar(5);
        readSonar(7);
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
      showAlert();
      ApplyBrakes();
    }
    else
    {
      if((sonar1Prev - sonar1)/deltaTime > 5)
      {
        showAlert();
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
      showAlert();
    }
    else
    {
      if((sonar6Prev - sonar6)/deltaTime > 5)
      {
        showAlert();
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
      showAlert();
    }
    else
    {
      if((dPrev - d)/deltaTime > 5)
      {
        showAlert();
      }
    }
  }
}

void checkLaneChange()
{
  if(sonar1 < insertValueHere || sonar3 < insertValueHere)
  {
    showAlert();
    Break();
  }
  else if((sonar1Prev - sonar1)/deltaTime > insertValueHere || (sonar3Prev - sonar3)/deltaTime > insertValueHere)
  {
    showAlert();
    Break();
  }
}

