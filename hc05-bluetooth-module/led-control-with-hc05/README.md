## HC05 Bluetooth Modülü İle İki Arduino Arasında Veri Alışverişi

* 2 farklı Arduino var. 
	* 1.sine buton bağlıyoruz.
	* 2.sine led bağlıyoruz
* Arduinolar arasında buetooth bağlantısı yapıyoruz. Butona bastığımızda led yanıyor. Temel olarak çalışmamızın açıklamasını yaptım. Şimdi devre şemalarını inceleyelim.

### Gönderici Devre Şeması 

![sender-circuit-scheme](https://github.com/akcauser/Arduino/blob/master/Components/hc05-bluetooth-module/led-control-with-hc05/verici-devre.png)

### Alıcı Devre Şeması

![getter-circuit-scheme](https://github.com/akcauser/Arduino/blob/master/Components/hc05-bluetooth-module/led-control-with-hc05/alıcı-devre.png)


Şimdi Arduinolarımıza yükleyeceğimiz kodlara bir gözatalım.

### Gönderici Arduino Kodları

~~~cpp
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // TX=10 | RX=11

int buton = 3;
int butonDurum = 0;
 
void setup()
{
  pinMode(buton,INPUT);
  BTSerial.begin(9600); //HC05 haberleşmesi başlatılıyor  
}
 
void loop()
{  
  butonDurum = digitalRead(buton); 
  BTSerial.write(butonDurum); //butondan gelen değer gönderiliyor
}
~~~

### Alıcı Arduino Kodları

~~~cpp
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // TX=10 | RX=11

int led = 4;
int butonDurum;
 
void setup()
{
  pinMode(led,OUTPUT);
  BTSerial.begin(9600); //HC05 haberleşmesi başlatılıyor  
}
 
void loop()
{  
  if (BTSerial.available()>0)
  {
      butonDurum=BTSerial.read(); //bluetooth'dan gelen değer okunuyor
      digitalWrite(led,butonDurum); 
  } 
}
~~~










