


int led  = 5;
int ledc = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(ledc, INPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  if (digitalRead(ledc) == HIGH){
    Serial.println("Led yandı");  
  }
  delay(1000);
  digitalWrite(led, LOW);
  if (digitalRead(ledc) == LOW){
    Serial.println("Led söndü");  
  }
  delay(1000);
}
