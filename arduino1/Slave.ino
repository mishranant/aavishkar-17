void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  analogWrite(A0, 0);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
float state = 0;
 if (Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.println(state);
    //analogWrite(A1, state);
 }

 else Serial.println("lai bus");
 //state=150.0;
if(state<=75.0){
    analogWrite(A1, 127.0 + (state*255.0)/150.0);
}

//Serial.write(0); // Sends '1' to the master to turn on LED
 delay(100);
}
