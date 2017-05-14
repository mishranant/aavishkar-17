const int buzzer = 9; //buzzer to arduino pin 9

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {
    // put your main code here, to run repeatedly:
 
    int a;
    a=3;
    beep(a);
}

void beep(int a)
{
  //int a;
  int i;
  //a=2;

 if(a==1)
 {
    for(i=0;i<5;i++)
    {
        tone(buzzer, 1000); 
        delay(100);        
         noTone(buzzer);
         delay(100);
      }
  }
  else if(a==2)
  {
    for(i=0;i<5;i++){
    tone(buzzer, 1500); 
        delay(250);        
         noTone(buzzer);
         delay(250);
    }
    }
    else if(a==3)
    {
       for(i=0;i<5;i++)
       {
    tone(buzzer, 400); 
        delay(500);        
         noTone(buzzer);
         delay(500);
    }
    }
  
  }

      


