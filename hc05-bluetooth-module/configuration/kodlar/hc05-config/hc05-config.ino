#include <SoftwareSerial.h>


SoftwareSerial BT(10,11); // TX ve RX 
int state = 12;

void setup() {
  // put your setup code here, to run once:

pinMode(state, OUTPUT);
digitalWrite(state, HIGH);
Serial.begin(9600);
BT.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:

if(BT.available())
  Serial.write(BT.read());

if(Serial.available())
  BT.write(Serial.read());  

}
