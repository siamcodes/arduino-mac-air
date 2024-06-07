void Show3Sonar() //แสดงค่า 3 Sonar
{
  Read3Sonar();
  glcdClear();  //เคลียร์หน้าจอ
  glcdFillScreen(GLCD_BLUE);  //กำหนดสีพื้นหลัง
  glcdMode(3);  //กำหนดโหมดหน้าจอ
  setTextColor(GLCD_RED); //กำหนดสีตัวอักษร
  setTextSize(2); //กำหนดขนาดตัวอักษร
  glcd(0,0,"SonarF=%d",SonarF);
  glcd(1,0,"SonarR1=%d",SonarR1);
  glcd(2,0,"SonarR2=%d",SonarR2);
}
