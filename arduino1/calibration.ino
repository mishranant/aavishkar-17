int m11 = 26;
int m12 = 28;
int m13 = 3;

int m21 = 22;
int m22 = 24;
int m23 = 4;

int m31 = 48;
int m32 = 50;
int m33 = 6;

int m41 = 46;
int m42 = 44;
int m43 = 5;

int motor1 = 255;
int motor2 = 255;
int motor3 = 255;
int motor4 = 255;

void setup() 
{
  pinMode(m11 , OUTPUT);
  pinMode(m12 , OUTPUT);
  pinMode(m13 , OUTPUT);
  pinMode(m21 , OUTPUT);
  pinMode(m22 , OUTPUT);
  pinMode(m23 , OUTPUT);
  pinMode(m31 , OUTPUT);
  pinMode(m32 , OUTPUT);
  pinMode(m33 , OUTPUT);
  pinMode(m41 , OUTPUT);
  pinMode(m42 , OUTPUT);
  pinMode(m43 , OUTPUT);
}

void loop() 
{
  digitalWrite(m11 , HIGH);
  digitalWrite(m12 , LOW);
  analogWrite(m13 , motor1);

  digitalWrite(m21 , HIGH);
  digitalWrite(m22 , LOW);
  analogWrite(m23 , motor2);

  digitalWrite(m31 , HIGH);
  digitalWrite(m32 , LOW);
  analogWrite(m33 , motor3);

  digitalWrite(m41 , HIGH);
  digitalWrite(m42 , LOW);
  analogWrite(m43 , motor4);
}
