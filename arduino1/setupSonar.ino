
#ifndef SONAR
#define SONAR
typedef struct sonar{
  const int trigpin, echopin;
  float distmax;
}sonar;
#endif

void setupSonars() {
  for(int i=0; i<8; i++){
    pinMode(sonars[i].trigpin, OUTPUT);
    pinMode(sonars[i].echopin, INPUT);
    }
}

float readSonar(sonar sonar_id)
{
  digitalWrite(sonar_id.trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(sonar_id.trigpin, HIGH);//triggering the sonar to emit an ultrasonic wave
  delayMicroseconds(5);
  digitalWrite(sonar_id.trigpin, LOW);//it is actually triggered at this instant
  
  duration = pulseIn(sonar_id.echoPin, HIGH ,((sonar_id.distmax+13)*2.0)/.034 );//time taken by reflected wave to be detected
  if (duration == 0) return -1.0;//object was out of range
  else {
    return (duration*0.034)/2.0;
  }
}

