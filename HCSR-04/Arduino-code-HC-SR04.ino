const int trigPin = 7; //Trigger pin
const int echoPin = 6; // Echo Pin 

void setup() {
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long sure, mesafe;
   
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(2);
   digitalWrite(trigPin, LOW);
   
   sure = pulseIn(echoPin, HIGH);
   mesafe = microsecondsToCentimeters(sure);
   Serial.print(mesafe);
   Serial.println("cm");

   delay(100);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
