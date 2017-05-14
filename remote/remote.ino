#include <GString.h>
#include <String.h>
#define rx A0
#define ry A1
#define buttonPin 2
int forward=0, turn=0;
int buttonprev = 1, buttoncurr=1, parkingstate =0;
char data[11];
void setup() {
  pinMode(rx,INPUT);
  pinMode(ry,INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  //pinMode(42, OUTPUT);
  //digitalWrite(42, LOW);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  
  GString g(data);
  
  Serial.begin(38400);
}

void loop() {GString g(data);
String inString = ""; 
  //data[0]='\0';
  int x = analogRead(rx);
  int y = analogRead(ry);

  if (x<=500) {
    turn = map(x, 4, 505, -100, 0);
    turn = constrain(turn, -100, 0);
  }
  else if (x>=520){
    turn = map(x, 525, 1020, 0, 100);
    turn = constrain(turn, 0, 100);
  }
  else turn = 0;
  
  if (y<=500){
    forward = map(y, 4, 505, 100, 0);
    forward = constrain(forward, 0, 100);
  }
  else if (y>=520){
    forward = map(y, 525, 1020, 0, -100);
    forward = constrain(forward, -100, 0);
  }
  else forward = 0;
  buttonprev = buttoncurr;
  buttoncurr = digitalRead(buttonPin);
  if(buttonprev==1 && buttoncurr ==0 )
  {
    if (parkingstate == 1) parkingstate =0;
    else if (parkingstate == 0) parkingstate =1;
  }
  sprintf(data, "%d%c%3d%c%3d", parkingstate,forward>=0? '0':'1',abs(forward),turn>=0? '0':'1',abs(turn));
  for(int i=0; i<9;i++) if(data[i]==32) data[i]='0';
  data[9]='\n';data[10]=0;
  (Serial.available() > 0)? Serial.write(data): Serial.println("not connected");
  delay(10);
}
