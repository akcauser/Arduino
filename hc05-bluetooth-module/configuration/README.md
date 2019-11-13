# HC05 Bluetooth Modülü

![hc05-module](https://github.com/akcauser/Arduino/blob/master/Components/hc05-bluetooth-module/configuration/hc05-module.png)


## Konfigürasyon

#### Modülü kullanmaya başlamadan önce konfigürasyon işlemini yapmamız gerekiyor.


### Devre Şeması

![configuration-circuit-scheme](https://github.com/akcauser/Arduino/blob/master/Components/hc05-bluetooth-module/configuration/configuration-circuit-scheme.png)

##### Şema ile ilgili Arduino ile bluetooth arasındaki iletişim arduino ve bluetooth üzerindeki Tx ve Rx pinlerinden yapılmaktadır. Ancak bu pinler aynı zamanda arduino ile bilgisayarımız arasındaki iletişim hattı için de kullanıldığı için arduinoya kod yüklemesi yaparken sürekli bluetooth modülünden gelen Tx ve Rx bağlantılarını  çıkarmak gerekmektedir. Bunun yerine Arduino içindeki SoftwareSerial.h kütüphanesini kullanarak arduinodaki istediğimiz dijital pinleri Tx ve Rx pini olarak seçebiliriz.


### Kodlar

~~~cpp
#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); // TX=10 ve RX=11
int state = 12;

void setup() {

	pinMode(state, OUTPUT);
	digitalWrite(state, HIGH);
	Serial.begin(9600);
	BT.begin(38400);
}

void loop() {
 
	if(BT.available())
	  Serial.write(BT.read());
	
	if(Serial.available())
	  BT.write(Serial.read());  

}
~~~

Konfigürasyon yaparken seri port haberleşme ekranında AT- komutlarını gönderiyoruz.

* <span style="color:red">AT+NAME? :</span> Bu komut ile modülün diğer cihazlarda görünen adını görüntüleyebiliriz. Standart olarak HC-05 gelecektir.

* <span style="color:red">AT+NAME=isim :</span> Bu komut ile modülün ismini değiştirebiliyoruz. yeni_isim yazan yere istediğiniz bir isim belirleyebilirsiniz.


* <span style="color:red">AT+PSWD? :</span> Bu komut ile modülün şifresini görüntüleyebiliriz. Standart şifre 1234.

* <span style="color:red">AT+PSWD=şifre :</span> Bu komut ile  modülün şifresini değiştirebiliyoruz. şifre yazan yere istediğiniz bir şifre belirleyebilirsiniz.

* <span style="color:red">AT+ROLE? :</span> Bu komut ile  modülün kullanıldığı modu görüntüleyebiliriz. 
	* Slave: 0
	* Master: 1

* <span style="color:red">AT+ROLE=1 :</span> Bu komut ile modülün rolunu değiştiriyoeuz.
	* AT+ROLE=1 - MASTER
	* AT+ROLE=0 - SLAVE

* <span style="color:red">AT+VERSION? :</span> Modülün bluetooth versiyonunu öğrenebiliriz.

* <span style="color:red">AT+ORGL :</span> Fabrika ayarlarına geri döndürme komutu.

* <span style="color:red">AT+ADDR? :</span> Bluetooth'un MAC adresini öğreniriz.

* <span style="color:red">AT+UART? :</span> Baunt rate ayarının kaç olduğunu görüntüleriz.

* <span style="color:red">AT+UART=9600 :</span> Baunt rate ayarını değiştiririz.

* <span style="color:red">AT+BIND=mac_adres :</span> Cihazın yalnızca tek bir cihazla eşleşmesini istiyorsak bu komutta mac adresi yazan yere o cihazın MAC adresini yazabiliriz. Sonra:
	* <span style="color:red">AT+CMODE=0</span> komutunu vermemiz gerekiyor.




	
	
  
	
