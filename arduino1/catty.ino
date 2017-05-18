int m1a = 255, m2a = 255, m3a = 255, m4a = 255;

void motorWrite()
{
  analogWrite(m1, m1a);
  analogWrite(m2, m2a);
  analogWrite(m3, m3a);
  analogWrite(m4, m4a);
}

void setup() {
  Serial.begin(9600);
  motorWrite();
}

void loop() {
  //readAccelerometer
  if(accx > 1)
  {
    m2a--;
    m3a--;
    motorWrite();
    delay(100);
  }
  else if(accx < -1)
  {
    m1a--;
    m4a--;
    motorWrite();
    delay(100);
  }
  Serial.println();
  Serial.println(m1a);
  Serial.println(m2a);
  Serial.println(m3a);
  Serial.println(m4a);
}
