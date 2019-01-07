const int waterSensor = 0; //analog pin
const int flameSensor = 1; //analog pin

const int leftForward = 2;  //digital pin
const int leftBackward = 3; //digital pin
const int rightForward = 4; //digital pin
const int rightBackward = 5;  //digital pin

const int trigPin = 9;  //digital pin
const int echoPin = 10; //digital pin

const int waterLed = 13; //digital pin
const int flameLed = 11; //digital pin
 
void setup() 
{
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(flameSensor, INPUT);
  pinMode(waterSensor, INPUT);
  
  pinMode(flameLed, OUTPUT);
  pinMode(waterLed, OUTPUT);
}
 
void loop()
{
  long duration, distance;

  int water = analogRead(waterSensor);  
  int flame = analogRead(flameSensor);  

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
    delay(500);
    digitalWrite(leftForward , HIGH);
    delay(1000);
    
  }
  else if(distance>20)
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(rightForward , HIGH);
    delay(250);
  }
 
  if(flame<850)
  {
    digitalWrite(flameLed, HIGH);
  }
  else if(flame>=850)
  {
     digitalWrite(flameLed, LOW);
  }

  if(water>=100)
  {
    digitalWrite(waterLed, HIGH);
    delay(500);
  }
  
  else if(water<100)
  {
    digitalWrite(waterLed, LOW);
    delay(500);
  }
}
