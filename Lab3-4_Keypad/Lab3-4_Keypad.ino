#include <Keypad.h> //เรียกใช้งานไลบรารี่ Keypad
const byte ROWS = 4; //ก าหนดแถว Rows 4 แถว
const byte COLS = 3; //ก าหนดแถว Column 3 แถว
char hexakey[ROWS][COLS] = {{'1', '2', '3'},
                            {'4', '5', '6',},
                            {'7', '8', '9',},
                            {'*', '0', '#',}
                           };
//เป็นการก าหนด Char เก็บค่าอักษรดังกล่าวจะเรียงตามรูปแบบของสวิตช์ 4 x 3 เรียงจากบนลงล่างเมื่อกดสวิตช์แถว 1 หลัก 1 จะส่งอักษร 1 เข้ามา เมื่อกดสวิตช์แถว 4 หลัก 3 จะส่งอักษร #
byte rowPins[ROWS] = {0, 2, 14, 12};
//ประกาศขาใช้งาน 4 ขา โดยระบุขาใช้งานจากตัวแปร ROWS
byte colPins[COLS] = {16, 5, 4};
//ประกาศขาใช้งาน 3 ขา โดยระบุขาใช้งานจากตัวแปร COLS
Keypad customKeypad = Keypad(makeKeymap(hexakey), rowPins,
                             colPins, ROWS, COLS);
//ใส่ตัวแปรเพื่อท าให้ค่าพารามิเตอร์ที่จ าเป็นกับไลบรารี่ทั้งหมดครบถ้วน
void setup() {
  Serial.begin(9600);
}
void loop() {
  char customKey = customKeypad.getKey();
  //รับค่าจาก Keypad เก็บไว้ใน customKey
  if (customKey) {
    Serial.println(customKey);
    //พิมพ์ค่าที่เก็บไว้ในตัวแปรผ่านจอมอนิเตอร์
  }
}
