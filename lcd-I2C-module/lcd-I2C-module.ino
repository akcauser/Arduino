
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
