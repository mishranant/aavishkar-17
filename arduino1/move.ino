/**
 * Functions to make the car move 
 */

//**DONE
   void moveFront()
   {
    analogWrite( leftMotor11 , leftMotor1Value );
    analogWrite( leftMotor12 , 0 );
    
    analogWrite( leftMotor21 , leftMotor2Value );
    analogWrite( leftMotor22 , 0 );
    
    analogWrite( rightMotor11 , rightMotor1Value );
    analogWrite( rightMotor12 , 0 );
    
    analogWrite( rightMotor21 , rightMotor2Value );
    analogWrite( rightMotor22 , 0 );
    
   }
  
   void rightFront()
   {
    analogWrite( leftMotor11 , leftMotor1Value );
    analogWrite( leftMotor12 , 0 );
    
    analogWrite( leftMotor21 , leftMotor2Value );
    analogWrite( leftMotor22 , 0 );
    
    analogWrite( rightMotor11 , 0 );
    analogWrite( rightMotor12 , rightMotor1Value );
    
    analogWrite( rightMotor21 , 0 );
    analogWrite( rightMotor22 , rightMotor2Value );
    
   }
  
   void leftFront()
   {
    analogWrite( leftMotor11 , 0 );
    analogWrite( leftMotor12 , leftMotor1Value );
    
    analogWrite( leftMotor21 , 0 );
    analogWrite( leftMotor22 , leftMotor2Value );
    
    analogWrite( rightMotor11 , rightMotor1Value );
    analogWrite( rightMotor12 , 0 );
    
    analogWrite( rightMotor21 , rightMotor2Value );
    analogWrite( rightMotor22 , 0 );
    
   }
  
   void moveBack()
   {
    analogWrite( leftMotor11 , 0 );
    analogWrite( leftMotor12 , leftMotor1Value );
    
    analogWrite( leftMotor21 , 0 );
    analogWrite( leftMotor22 , leftMotor2Value );
    
    analogWrite( rightMotor11 , 0 );
    analogWrite( rightMotor12 , rightMotor1Value );
    
    analogWrite( rightMotor21 , 0 );
    analogWrite( rightMotor22 , rightMotor2Value );
    
   }
  
   void rightBack()
   {
    analogWrite( leftMotor11 , 0 );
    analogWrite( leftMotor12 , leftMotor1Value );
    
    analogWrite( leftMotor21 , 0 );
    analogWrite( leftMotor22 , leftMotor2Value );
    
    analogWrite( rightMotor11 , rightMotor1Value );
    analogWrite( rightMotor12 , 0 );
    
    analogWrite( rightMotor21 , rightMotor2Value );
    analogWrite( rightMotor22 , 0 );
    
   }
  
   void leftBack()
   {
    analogWrite( leftMotor11 , leftMotor1Value );
    analogWrite( leftMotor12 , 0 );
    
    analogWrite( leftMotor21 , leftMotor2Value );
    analogWrite( leftMotor22 , 0 );
    
    analogWrite( rightMotor11 , 0 );
    analogWrite( rightMotor12 , rightMotor1Value );
    
    analogWrite( rightMotor21 , 0 );
    analogWrite( rightMotor22 , rightMotor2Value );
    
   }

   void breaker()
   {
    
   }

 

