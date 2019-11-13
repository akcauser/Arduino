int trig=7;
int echo=6;
long sure;
long mesafe;

int buzzer = 5;


void setup() {

  Serial.begin(9600);
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);  

}

void loop() {


  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  sure = pulseIn(echo, HIGH);

  mesafe = (sure / 29) / 2 ; 



    if (mesafe>400 || mesafe<2){
      
        Serial.println("Aralık Dışı Değer");
      
    }else{
      
        Serial.print(mesafe);  
        Serial.println("cm");
    }


    if(mesafe > 15){
      tone(buzzer, 100);
      delay(10);
      noTone(buzzer);
      delay(300);
    }else if(mesafe > 10){
      tone(buzzer, 100);
      delay(10);
      noTone(buzzer);
      delay(200);
    }else if(mesafe > 5){
      tone(buzzer, 100);
      delay(10);
      noTone(buzzer);
      delay(100);
    }else{
      tone(buzzer, 100);
      delay(10);
      noTone(buzzer);
      delay(50);
    }
  
}


