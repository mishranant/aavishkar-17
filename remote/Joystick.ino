#define rx A0
#define ry A1
#define left1 A2
#define left2 A3
#define right1 A4
#define right2 A5
//int pwmleft = ;
//int pwnright = ;
void setup() {
  // put your setup code here, to run once:
  pinMode(rx, INPUT);
  pinMode(ry, INPUT);
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right1, OUTPUT);
 // pinMode(pwmleft, OUTPUT);
 // pinMode(pwmright, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int y = analogRead(ry);
int x = analogRead(rx);  
int forward;
int turn;
/*Serial.print("for");
Serial.println(forward);
Serial.print("turn");
Serial.println(turn);
*/
if (x<=500) turn = map(x, 4, 500, -100, 0);
else if (x>=520) turn = map(x, 525, 1020, 0, 100);
else turn = 0;
if (y<=500) forward = map(y, 4, 500, 100, 0);
else if (y>=520) forward = map(y, 530, 1023, 0, -100);
else int forward = 0;
int left = forward + turn;
int right = forward - turn;
if (left >100) left =100;
if (right>100) right =100;

//int powerL = map(left, 0, 100, 126, 255);
//int powerR = map(right, 0, 100, 126, 255);
Serial.print("forward: ");
Serial.print(forward);
Serial.print(" turn: ");
Serial.println(turn);
/*
if (left>=0) {
  analogWrite(left1, map(left, 0, 100, 126, 255));
  analogWrite(left2, 0);
  }
else {
  analogWrite(left2, map(-left, 0, 100, 126, 255));
  analogWrite(left1, 0);
  }

if (right>=0){
  analogWrite(right1, map(right, 0, 100, 126, 255));
  analogWrite(right2, 0);
  }
else {
  analogWrite(right1, map(-right, 0, 100, 126, 255));
  analogWrite(right2, 0);
  }
//delay(500);
//analogWrite(pwmLeft, powerL);
//analogWrite(pwmRight, powerR);*/
}
