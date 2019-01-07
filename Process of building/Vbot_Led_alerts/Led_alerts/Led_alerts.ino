int distLed = 4;  //digital pin 4 for the LED alert for the ultrasonic sensor
int flameLed = 3;  //digital pin 3 for the LED alert for the flame sensor
int waterLed = 2; //digital pin 4 for the LED alert for the water level sensor
int motorPin = 7;

int trigPin = 9;
int echoPin = 10;
int flameSensor = 1; //analog pin 1 for the flame sensor
int waterSensor = 0; //analog pin 0 for the waterlevel sensor

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
  
  pinMode(distLed, OUTPUT);
  pinMode(flameLed, OUTPUT);
  pinMode(waterLed, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(flameSensor, INPUT);
  pinMode(waterSensor, INPUT);
}

void loop() {
  int x = analogRead(waterSensor);  //it will keep the value of the water level sensor
  int y = analogRead(flameSensor);  //it will keep the value of the flame sensor
  long duration, distance;

  if (Serial.available())
  {
    int speed = Serial.parseInt();
    
    if (speed >= 0 && speed <= 255)
    {
    analogWrite(motorPin, speed);
    }
  }
  
  digitalWrite(trigPin,HIGH);
  delay(500);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  delay(10);
  
  if(distance<=10)
  {
    digitalWrite(distLed, HIGH);
  }
  else if(distance>10)
  {
    digitalWrite(distLed, LOW);
  }

  if(y<850)
  {
    digitalWrite(flameLed, HIGH);
  }
  else if(y>=850)
  {
     digitalWrite(flameLed, LOW);
  }

  if(x>=100)
  {
    digitalWrite(waterLed, HIGH);
  }
  else if(x<100)
  {
    digitalWrite(waterLed, LOW);
  }

  //delay(500);
}
