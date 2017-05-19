void brake()
{
  analogWrite( pwmlf , LOW );  
  analogWrite( pwmlb , LOW );  
  analogWrite( pwmrf , LOW );  
  analogWrite( pwmrb , LOW );  
}

