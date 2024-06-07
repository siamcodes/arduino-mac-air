void ShowADC(){
  ReadADC();
  oled.clear();
  oled.text(2,0,"L = %d",L);
  oled.text(3,0,"C = %d",C);
  oled.text(4,0,"R = %d",R);
  oled.show();
}
