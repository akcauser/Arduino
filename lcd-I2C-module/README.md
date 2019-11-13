## I2C Modülü kullanımı

2x16 LCD ekranın 16 farklı pini bulunmaktadır. Bu durum bu komponenti kullanmayı haylice zorlaştırıyor. I2C modülü burada devreye giriyor ve 16 pini 4 pine çevirerek LCD'yi kullanmayı kolaylaştırıyor

![i2c modül resmi](https://www.14core.com/wp-content/uploads/2015/09/I2C-LCD-Module-Board-Arduino-AVR-PIC.jpg)

I2C modülünde 6 pin bulunur. 

* GND topraklama pini. Arduinodaki toprak hattına bağlanır
* VCC 5V güç pini.
* SDA Arduino UNO'daki A4 pini.
* SCL Arduino UNO'daki A5 pini.
* Diğer 2 pin arkaplan ışığının bağlantısıdır.

Ayrıca modülde lcd'nin kontrast ayarını yapmak için bir de potansiyometre bulunur.

Modülde SDA(Serial Data Line) ve SCL(Serial Clock Line) hatları vardır. 
> * SDA cihazlar arasındaki veri aktarımının sağlandığı hattır. Çift yönlü veri aktarımı olur. Hatta aktarılan verilerin senkronizasyonu SCL hattı ile sağlanır.
> * SCL hattında Arduino tarafından üretilen saat sinyali bulunur. SDA hattındaki haberleşme bu sinyale göre düzenlenir.

[I2C HABERLEŞME PROTOKOLÜ](http://ramazansural.blogspot.com/2010/11/i2c-haberlesme-protokolu.html) Linkte SDA ve SCL ile ilgili ayrıntılı bir yazı var. İlgilenenler bakabilir.



SDA ve SCL pinleri Arduino modellerine göre değişebilmektedir. Alttaki linkte Wire kütüphanesi bulunmaktadır. Diğer Arduino modellerinde hangi pinlerin bu çıkışlara karşılık geldiğini öğrenebilirsiniz.

[Arduino Wire Library](https://www.arduino.cc/en/reference/wire)

[LiquidCrystal Kütüphanesi indir](https://github.com/akcauser/ArduinoComponents/raw/master/lcd-I2C-module/library/LiquidCrystal_I2C.zip)

Kodlarda açıklama satırlarına yer verdim.Yine dosya içinde bulabilirsiniz. 

~~~c++
//Arduino wire kütüphanesini ekliyoruz.
#include <Wire.h> 
//Liquid Crystal kütüphanesini ekliyoruz.
#include <LiquidCrystal_I2C.h>

// LCD adreslemesini 0X3f olarak ayarladık
// 16 sütun 2 satır olduğunu belirttik.
LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setup()
{
  lcd.begin(); // lcd yi başlatma
  lcd.home(); // imlec başlangıç konumuna gelir
  lcd.backlight();  // arka plan ışığını açma
  lcd.clear();  // lcd yi temizleme
  lcd.print("s"); // ekrana birşey yazdırma
  lcd.setCursor(1, 1); // imleci konumlandırma (sütun, satır)
  lcd.print("merhaba"); 
  lcd.cursor(); // imleci gösterme işlemi yapar
  lcd.blink(); // imleç yanıp sönme işlemini yapar
}

void loop()
{

  
}
~~~




