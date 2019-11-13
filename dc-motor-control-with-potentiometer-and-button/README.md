# Potansiyometre ve Button ile DC Motor Kontrolü 

### Devre Şeması

![circuit-scheme](https://github.com/akcauser/Arduino/blob/master/Arduino-egap-calismalar/dc-motor-control-with-potentiometer-and-button/l298n-potentiometer-buton-scheme.png)

### Kullanılan Malzemeler
* Arduino UNO
* 9V pil
* DC Motor
* L298n motor sürücü
* Potansiyometer
* Buton
* 220ohm direnç
* Birkaç tane kablo

### Açıklama 

* Hazırladığımız devrede bulunan motorun yönü buton yardımı ile kontrol ediyoruz.
	* Butona bastığımızda motor ileri yönde hareket ediyor
	* Basmadığımız zamanlarda geri yönde hareket ediyor
* Motorun hızını ise potansiyometre ile kontrol ediyoruz.
	* Potansiyometre tıpkı radyodaki ses açma kapama işlemi gibi motorda hızlı ya da yavaş sürme işlemi yapmak için kullanıyoruz.


### Kodlar 

Kodlarda açıklama satırları ile neler yaptığımı açıkladım.

~~~c++
//enable pinini Arduino üzerindeki PWM sintali verebilen çıkışlara bağlıyorum
int hiz = 10;
//IN1 ve IN2 pinlerini dijital çıkış alabileceğim herhangi iki pine bağlıyorum.
int ileri= 9;
int geri= 8;

//Potansiyometreden 0-1023 arasında değer okuması yapacağım için ANALOG giriş pinlerine bağlıyorum
int pot = A0;
//Potansiyometreden gelen değeri bu değişkende tutuyorum
int deger = 0;
//Potansyiometreden gelen değeri map ettikten sonra bu değişkene atama yapıyorum
int mappedValue = 0;

//Butondan dijital yani 0-1 değerleri okuyacağım için dijital pinlerden birine bağlıyorum.
int button = 7;
//Butondan gelen değeri bu değişkene atama yapıyorum
bool isClick = true;


void setup() {


	Serial.begin(9600);

	//motora yön değerlerini ve hız değerini göndereceğimiz pinler OUTPUT oldu.  
	pinMode(hiz,OUTPUT);
	pinMode(ileri,OUTPUT);
	pinMode(geri, OUTPUT);

	// potansiyometre ve butondan değer okuması yapacağımız için INPUT oldu.
	pinMode(pot, INPUT);
	pinMode(button, INPUT);

}


void loop() {

	//deger değişkenine potansiyometreden gel değeri okudum  
	deger = analogRead(pot);

	//deger değişkeninin değer aralığını map fonksiyonu ile 0-255 aralığına çevirdim.
	mappedValue = map(deger, 0, 1023, 0, 255);

	//butondan gelen değeri isClick değişkenine atama yaptım.
	isClick = digitalRead(button);

	  //Eğer isClick 1 ise motorun dönme yönü ileri doğru olsun, değilse geri doğru olsun.
	  if(isClick == 1){
	      digitalWrite(ileri, HIGH);
	      digitalWrite(geri, LOW);
	  }else{
	      digitalWrite(ileri, LOW);
	      digitalWrite(geri, HIGH);
	  }

	//potansiyometre aldığımız değeri 0-255 arasına çevirmiştik.
	//Bu değeri hiz pini ile motora gönderiyorum.
	//analogWrite kullanma sebebi ise bu değeri 0-255 yani analog değerler olması
	analogWrite(hiz, mappedValue);



}
~~~

	

