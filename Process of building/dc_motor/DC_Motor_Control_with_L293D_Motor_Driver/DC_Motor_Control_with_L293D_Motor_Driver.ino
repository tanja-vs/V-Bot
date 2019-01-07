const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;
const int trigPin = 9;
const int echoPin = 10;
const int LED = 13;
 
void setup() 
{
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(echoPin, INPUT);
 
}
 
void loop()
{
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  delay(10);
 
  if((distance<=20)) 
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(rightForward , LOW);
    digitalWrite(LED , HIGH);
    delay(500);
    digitalWrite(leftForward , HIGH);
    delay(1000);
    
  }
  else if(distance>20)
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(LED , LOW);
    delay(250);
   }
}
