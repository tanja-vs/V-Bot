const int leftWheel = 5;
const int rightWheel = 6;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  pinMode(leftWheel, OUTPUT);
  pinMode(rightWheel, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Serial.begin(9600);
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  if (distance <= 15)
  {
    digitalWrite(leftWheel, LOW);
    digitalWrite(rightWheel, LOW);
    delayMicroseconds(1000);
  }
  else if (distance > 15) 
  {
    digitalWrite(leftWheel, HIGH);
    digitalWrite(rightWheel, HIGH);
  }
}
 
