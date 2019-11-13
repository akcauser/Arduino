// Motor sürücümüze bağladığımız pinleri tanımlıyoruz
const int in1 = 8;     // ileri sürme
const int in2 = 9;     // geri sürme
const int enA = 10;    // enable pini ile 0-255 arasında analog değer veriyoruz

const int in3 = 11;     // ileri sürme
const int in4 = 12;     // geri sürme
const int enB = 7;  

void setup() {
  // put your setup code here, to run once:

//Tüm pinlerden güç çıkışı olacağı için OUTPUT olarak ayarladık.
pinMode(in1, OUTPUT);  
pinMode(in2, OUTPUT);
pinMode(enA, OUTPUT);
pinMode(in3, OUTPUT);  
pinMode(in4, OUTPUT);
pinMode(enB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(in2, HIGH); // ileri aktif
digitalWrite(in1, LOW);  // geri pasif
analogWrite(enA, 100);  // hız 100 / 255 oranında 


digitalWrite(in3, HIGH); // ileri aktif
digitalWrite(in4, LOW);  // geri pasif
analogWrite(enB, 100);  // hız 100 / 255 oranında 

}
