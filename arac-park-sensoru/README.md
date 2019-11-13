# ARAÇ PARK SENSÖRÜ

## Devre Şeması
![HCSR-04 ve Buzzer devre şeması](https://github.com/akcauser/Arduino/blob/master/Arduino-egap-calismalar/arac-park-sensoru/hc-sr04_devre_semasi.png?raw=true)

#### Pin tanımlamalarını yaptık
~~~c++
int trig=7;
int echo=6;
int buzzer = 5;
~~~

#### Değişken tanımlamalarını yaptık
~~~c++
long sure;
long mesafe;
~~~

#### "void setup()" içerisinde; 
* Pinleri INPUT yada OUTPUT olarak kullanacağımızı belirliyoruz
* Ayrıca Serial Port ile veri alışverişini başlatıyoruz. 
* Aktarım hızı 9600 baud seçiyoruz.
~~~c++
void setup() {

    Serial.begin(9600);
  
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(buzzer, OUTPUT);  
}
~~~


#### Void loop içerisinde;

* Hoparlörü kapatıyoruz ve 5 mikrosaniye bekliyoruz.
* Hoparlörü açıyoruz.
* 5 microsaniye boyunca hoparlör açık kalıyor.
* Ardından hoparlörü tekrar kapatıyoruz.
~~~c++
void loop() {
    digitalWrite(trig, LOW);
    delayMicroseconds(5);
    digitalWrite(trig, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig, LOW);
~~~

* 'sure' değişkenine mikrofona dalga gelene kadar mikrosaniye cinsinden geçen süreyi atama yapıyoruz.
* pulseIn() metodunun hangi parametreler aldığını ve geri döndürdüğü değerleri alttaki linkten görebilirsiniz.
* [pulseIn() metodu](https://www.arduino.cc/en/Reference.PulseIn)

~~~c++
    sure = pulseIn(echo, HIGH);
~~~

* mesafe değişkenine atama yaparken kullandığımız formül şu şekilde;
* Ses 29 mikrosaniyede 1cm gidebiliyor. Yani geçen süreyi 29'a böldüğümüzde gidiş-geliş uzaklığını bulmuş oluyoruz. Sonra 2'ye bölerek sadece gidiş uzaklığını bulmuş oluyoruz.

~~~c++
    mesafe = (sure / 29) / 2 ; 
~~~

* HC-SR04 Ultrasonik mesafe sensörünün çalışma kapasitesi 2cm-400cm arasında. Bu yüzden bu değer aralığının dışındaki değerleri yazdırmak istemiyoruz.
* Bir kontrol yapısı kuruyoruz. 
~~~c++
    if(mesafe>400 || mesafe<2){
      
        Serial.println("Aralık Dışı Değer");
      
    }else{
      
        Serial.print(mesafe);  
        Serial.println("cm");
    }
~~~



* Burada yaptığımız ise çalışmamızı araç park sensörüne çevirmek.
* mesafe 15cm 'den büyükse 300 milisaniye aralıklarla buzzer'ın sesini açıp kapatıyoruz
* mesafe 15cm'den büyük değil ama 10 cm'den büyükse 200 milisaniye aralıklarla buzzer'ın sesini açıp kapatıyoruz
* mesafe 10cm'den büyük değil ama 5 cm'den büyükse 100 milisaniye aralıklarla buzzer'ın sesini açıp kapatıyoruz
* mesafe 5cm'den küçükse 50 milisaniye aralıklarla buzzer'ın sesini açıp kapatıyoruz --> else bloğu
~~~c++
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
~~~
    
## Kodların tamamını da burada paylaşıyorum. İyi çalışmalar dilerim.



~~~c++
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


    
  
}

~~~

