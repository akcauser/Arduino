## HC-SR04 Ultrasonik Mesafe Sensörü

![HCSR-04](https://www.robotshop.com/media/catalog/product/cache/image/380x380/9df78eab33525d08d6e5fb8d27136e95/h/c/hc-sr04-ultrasonic-range-finder-2.png)

HC-SR04 ultrasonik sensörü bize 2cm ila 400 cm arasındaki kesintisiz uzaklığı bulmayı sağlar. Açı 15 derecenin altında iken bu ölçüm 3mm'lik doğruluğa ulaşabilir. 5V güç ile çalışır. Bu modül verici, alıcı ve kontrol devresinden oluşur. Basit çalışma prensibi:

![Çalışma Şekli](https://www.tutorialspoint.com/arduino/images/ultrasonic_sensor_radiations.jpg)

* Trigger giriş/çıkış pini en az 10us yüksek seviye sinyali için

* Modül otomatik olarak 40khz sinyal gönderir ve geri sinyalin dönmediği tespit edilir.

* Eğer sinyal geri dönmüşse, yüksek seviye yoluyla, yüksek çıkışlı giriş/çıkış süresi ultrasonik göndermeden geri dönüşe kadar geçen süredir.

Mesafe(cm) = cevap gelme süresi / 29 / 2

Ses saniyede 340m geçer. Bu da 1 santimetreyi 29 mikrosaniyede geçiyor demektir. Geçen süreyi 29'a bölersek gidip gelme süre olduğu için aradaki uzaklığın 2 katını bulmuş oluruz. Bu yüzden 2'ye bölerek aradaki uzaklığın kaç cm olduğunu buluruz.

Kablo bağlantıları şu şekilde:

* 5V Güç
* Trigger Girişi
* Echo çıkışı
* 0V Topraklama

Elektrik parametreleri

|Veri				 |Değer			   |
|:----------------|----------------:|
|Çalışma gerilimi |				DC 5V |
|Çalışma Akımı    |				15mA  |
|Çalışma Frekansı | 			40Hz  |
|Maksimum Uzaklık |				4m	   |
|Minimum uzaklık  | 			2cm   |
|Ölçüm açısı	     |				15°   |
|Trigger Giriş sinyali| 10us TTL atımı|
|Echo Çıkış Sinyali| Giriş sinyali aralık oranı|
|Boyutlar 		  |			45x20x15mm|



### Kodlar:
~~~c++
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
~~~
