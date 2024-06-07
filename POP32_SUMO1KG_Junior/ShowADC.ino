void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  oled.clear();
  oled.text(0, 0, "L1 = %d", L1);
  oled.text(1, 0, "C = %d", C);
  oled.text(2, 0, "R1 = %d", R1);
  oled.text(3, 0, "BC = %d", BC);
  oled.show();
}
