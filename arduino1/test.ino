
void loop() {
int y = analogRead(ry);
int x = analogRead(rx);  
int forward = map(y, 0, 1023, -100, 100);
int turn = map(x, 0, 1023, -100, 100);

int left = forward + turn;
int right = forward - turn;
//send left and right values from remote to car using bluetooth
//this to go into the car
int powerL = (abs(left), 0, 100, 126, 255);
int powerR = (abs(right), 0, 100, 126, 255);

if (left>=0) {
  digitalWrite(left1, HIGH);
  digitalWrite(left2, LOW);
  }
else {
  digitalWrite(left1, LOW);
  digitalWrite(left2, HIGH);
  }

if (right>=0){
  digitalWrite(right1, HIGH);
  digitalWrite(right2, LOW);
  }
else {
  digitalWrite(right1, LOW);
  digitalWrite(right2, HIGH);
  }

analogWrite(pwmLeft, powerL);
analogWrite(pwmRight, powerR);
}
