# L298N ile DC Motor Sürme

#### Devre şeması

![circuit-scheme](https://github.com/akcauser/Arduino/blob/master/Components/motor-driving-with-L298N/l298n-motor-drive-scheme.png)

##### Öncelikle devreyi tanıtalım.
* Kullandığımız malzemeler:
	1. DC Motor
	2. 9V pil
	3. L298N motor sürücü
	4. Arduino UNO
	5. Birkaç tane kablo

1. Motor sürücümüze 12V girişinde 9V pilin artı(+) ucuna bağlantı yapıyoruz.
2. Pilin ve Motor sürücünün eksi(-) girişini ise Arduino'nun GND pinine bağlıyoruz. Her ikisi de aynı topraklamaya bağlanması gerekmektedir.
3. Motor sürücünün Output A bölümüne DC Motor bağlıyoruz.
4. Motor sürücüde bulunan in1 ve in2 çıkışlarını Arduino da bulunan 8 ve 9 dijital çıkış pinlerine bağlıyoruz	
	* Bu pinleri kullanarak motorun dönme yönünü belirleyeceğiz.
5. Motor sürücünün EnableA girişini Arduino'nun PWM çıkış pinlerinde 10 numaralı pine bağlıyoruz.
	* Sebebi analog çıkış yapacak olmamızdır.
	* Motora 0-255 arasında değerler göndereceğiz. 

	

* Kodlarda açıklama satırları ile hangi satırda ne işlem yapıldığını anlattım. Ama şu kısmı açıklayayım;

~~~c++
analogWrite(enA, 100);
~~~

Burada 0-255 arasında değer gönderebiliriz. Mesela 100 değerini gönderdiğimizde 9V luk bir pil için ;
	
	9x(100/255) = 3.52V'luk gerilim göndermiş oluyoruz.

Tam güç verirsek;
	
	9x(255/255) = 9V 'luk gerilim ile tam hızda çalıştırmış oluyoruz. 

Bu şekilde motorun hızını kontrol edebiliyoruz.

* Motor yönünü kontrol ederken;

~~~c++
digitalWrite(in2, HIGH); // ileri aktif
digitalWrite(in1, LOW);  // geri pasif
~~~

şeklinde yani aktif ettiğimiz yönde hareket etmesini sağlıyoruz. 

Eğer her ikisini de aktif edersek motor nötr yani hareket olmayacaktır.
Aynı şekilde her ikisini de pasif edersek de böyle bir sonuç alırız.

#### Kodlar  

~~~c++
// Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int in1 = 9;     // ileri sürme
const int in2 = 8;     // geri sürme
const int enA = 10;    // enable pini analog çıkış için PWM(10) pinine bağlandı.

void setup() {
  // put your setup code here, to run once:

//Tüm pinlerden güç çıkışı olacağı için OUTPUT olarak ayarladık.
pinMode(in1, OUTPUT);  
pinMode(in2, OUTPUT);
pinMode(enA, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(in2, HIGH); // ileri aktif
digitalWrite(in1, LOW);  // geri pasif
analogWrite(enA, 100);  // hız 100 / 255 oranında olacak şekilde gönderiliyor. 


}
~~~


