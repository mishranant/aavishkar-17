#define ra1 43
#define ra2 45

#define la1 47
#define la2 49
#define rx A0
#define ry A1
int pwm1=8, pwm2=9;
int forward=0, turn=0;
int left =0, right=0;
int powl=0, powr=0;

void setup() {
  pinMode(la1,OUTPUT);
  pinMode(la2,OUTPUT);
  pinMode(ra1,OUTPUT);
  pinMode(ra2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);

  pinMode(rx,INPUT);
  pinMode(ry,INPUT);

  Serial.begin(9600);

}

void loop() {
  
  /* this goes into the remote*/
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
  BTsend(parking_switch, forward, turn);
  /* forward and turn are transmitted to the car
   *  the code from here is put into the car
   */
  Steer(froward, turn);
  
}
void Steer(int forward, int turn)
{
  if (forward>=0){
  left = forward + turn;
  left = constrain(left, -100, 100);
  right = forward - turn;
  right = constrain(right, -100, 100);
  }
  else{
   left =  forward - turn;
  left = constrain(left, -100, 100);
  right = forward + turn;
  right = constrain(right, -100, 100);
  
  }

  if(left>=0)powl = map(left, 0, 100, 0, 255);
  else powl = map(left, -100, 0, 255, 0);
  analogWrite(pwm1, powl);
  if(left>=0){
  digitalWrite(la1, LOW);
  digitalWrite(la2, HIGH);
  }
  else{
  digitalWrite(la1, HIGH);
  digitalWrite(la2, LOW);
  }
  if(right>=0)powr = map(right, 0, 100, 0, 255);
  else powr = map(right, -100, 0, 255, 0);
  analogWrite(pwm2, powr);
  if(right>=0){
  digitalWrite(ra1, LOW);
  digitalWrite(ra2, HIGH);
  }
  else{
  digitalWrite(ra1, HIGH);
  digitalWrite(ra2, LOW); 
  }
  Serial.print("f: ");
  Serial.print(forward);
  Serial.print(" t: ");
  Serial.print(turn);
  Serial.print("  l: ");
  Serial.print(left);
  Serial.print(" r: ");
  Serial.println(right);
}
