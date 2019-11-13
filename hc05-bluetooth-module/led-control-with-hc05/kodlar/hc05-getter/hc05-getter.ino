#include <SoftwareSerial.h>
SoftwareSerial BluetoothSerial(10, 11); // TX=10 | RX=11

int led = 4;
int butonDurum;
 
void setup()
{
  pinMode(led,OUTPUT);
  BluetoothSerial.begin(9600);  
}
 
void loop()
{  
  if (BluetoothSerial.available()>0)
  {
      butonDurum=BluetoothSerial.read();
      digitalWrite(led,butonDurum); 
  } 
}
