void ShowLCD(){
  oled.clear();  //เคลียร์หน้าจอ
  oled.text(0,0, "Line Tracing PID 4 Sensor"); //แสดงข้อความแถว คอลัมน์
  oled.text(1,0,"Design by Somkiat");
  oled.show();
}
