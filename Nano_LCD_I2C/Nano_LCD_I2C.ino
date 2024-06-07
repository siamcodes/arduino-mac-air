#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Module IIC/I2C Interface บางรุ่นอาจจะใช้ 0x3f
int one , two , five, ten ;
int s1 = 2;
int s2 = 3;
int s3 = 4;
int s4 = 5;


void setup() {
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  
  Serial.begin(9600);
  lcd.begin();
  //lcd.noBacklight();   // ปิด backlight
  lcd.backlight();       // เปิด backlight
  lcd.home();
  lcd.print("1   2   5   10");
  delay(10);

}

void loop() {
  analogWrite(9,150);

  if (digitalRead(s1) == 1) {
    one += 1;
    delay(100);
  }

  if (digitalRead(s2) == 1) {
    two += 1;
    delay(100);
  }

  if (digitalRead(s3) == 1) {
    five += 1;
    delay(100);
  }

  if (digitalRead(s4) == 1) {
    ten += 1;
    delay(100);
  }

  lcd.display();
  lcd.setCursor(0, 1);  //หลักที่ 0 บรรทัดที่ 1
  lcd.print(String(one));
  lcd.setCursor(4, 1);  //หลักที่ 4 บรรทัดที่ 1
  lcd.print(String(two));
  lcd.setCursor(8, 1); //หลักที่ 8 บรรทัดที่ 1
  lcd.print(String(five));
  lcd.setCursor(12, 1);  //หลักที่ 12 บรรทัดที่ 1
  lcd.print(String(ten));

}
