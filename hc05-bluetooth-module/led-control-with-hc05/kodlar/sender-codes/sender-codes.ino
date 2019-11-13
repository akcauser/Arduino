#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // TX=10 | RX=11

int buton = 3;
int butonDurum = 0;
 
void setup()
{
  pinMode(buton,INPUT);
  BTSerial.begin(9600);  
}
 
void loop()
{  
  butonDurum=digitalRead(buton);
  BTSerial.write(butonDurum);
}
