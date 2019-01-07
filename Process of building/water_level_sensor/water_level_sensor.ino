int h20 = 0;
int led = 2;

void setup() {

  pinMode(h20, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);


}


void loop() {

 int i = analogRead(h20);

 Serial.println(i);

 if(i>200)
 {
    digitalWrite(led, HIGH);
 }
 else
 {
    digitalWrite(led, LOW);
 }

 delay(500);

}



