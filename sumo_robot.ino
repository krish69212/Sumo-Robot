int rightLDRValue = 0;
int leftLDRValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(A2, LOW);
  digitalWrite(11, HIGH);
 digitalWrite(10, HIGH);
  //forwards
  
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(1000);
  
  
  // backwards
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(1000);
  
  // right
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(1000);
  
  // left
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(1000);
}


void loop()
{
  // read the value from the sensor
  rightLDRValue = analogRead(A0);
  leftLDRValue = analogRead(A5);
  digitalWrite(A2, HIGH);
  delayMicroseconds(10);
  digitalWrite(A2, LOW);
  long duration = pulseIn(A3, HIGH);
  
  int distance = duration / 58;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // print the sensor reading so you know its range
  Serial.println(rightLDRValue);
  Serial.println(leftLDRValue);
  // map the sensor reading to a range for the LED
  analogWrite(9, map(rightLDRValue, 0, 1023, 0, 255));
  if(rightLDRValue < 40) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  else if(leftLDRValue < 40) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  else {
    int turndistance = 50;
  	digitalWrite(A2, HIGH);
 	delayMicroseconds(10);
  	digitalWrite(A2, LOW);
  	long duration = pulseIn(A3, HIGH);
  
  	int distance = duration / 58;
  	Serial.print("Distance: ");
  	Serial.println(distance);
  
  	if (distance <= 70) {
    	digitalWrite(2, HIGH);
    	digitalWrite(3, LOW);
    	digitalWrite(4, HIGH);
    	digitalWrite(5, LOW);
    
  	}
    // Otherwise, move forward
  	else {
    // Set both motors to turn forward
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      delay(5);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
    	digitalWrite(2, HIGH);
    	digitalWrite(3, LOW);
    	digitalWrite(4, LOW);
    	digitalWrite(5, HIGH);
  	}

    

  
  }

  
