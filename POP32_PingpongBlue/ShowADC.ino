void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  oled.clear();
  oled.text(0, 0, "L2 = %d", L2);
  oled.text(1, 0, "L1 = %d", L1);
  oled.text(2, 0, "C = %d", C);
  oled.text(3, 0, "R1 = %d", R1);
  oled.text(4, 0, "R2 = %d", R2);
  
  oled.text(0, 10, "BL2 = %d", BL2);
  oled.text(1, 10, "BL1 = %d", BL1);
  oled.text(3, 10, "BR1 = %d", BR1);
  oled.text(4, 10, "BR2 = %d", BR2);
  oled.show();
}
