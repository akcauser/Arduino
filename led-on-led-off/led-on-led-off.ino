#include <SoftwareSerial.h>
SoftwareSerial BT(6, 7); 

int led = 11;
char a; 

void setup()  
{
  pinMode(led, OUTPUT);
  BT.begin(9600); 
}

void loop() 
{ 
  //herhangi bir veri geldiği zamanlarda
  if (BT.available())
  {
    a = BT.read();
    if (a=='1')
    {
      digitalWrite(led, HIGH);
      BT.println(" LED on");
    }
    else if (a=='2')
    {
      digitalWrite(led, LOW);
      BT.println(" LED off");
    }
    else
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED off");
    }   
  }
}
