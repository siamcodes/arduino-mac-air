void ShowADC() {
  ReadADC();     //อ่านค่าเซนนเซอร์
  glcdClear();
  glcdMode(3);    //โหมดหน้าจอ 270 องศา
  setTextSize(1); //ขนาดตัวอักษร
  glcd(1, 0, "FL = %d", FL);
  glcd(2, 0, "FR = %d", FR);
  glcd(3, 0, "BL = %d", BL);
  glcd(4, 0, "BR = %d", BR);
}
