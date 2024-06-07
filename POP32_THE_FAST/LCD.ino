void ShowSonar()
{
  oled.clear();
  oled.text(0,0,"Distance=%d",Sonar());
  oled.show();
}
void Show(int Number)
{
  oled.clear();
  oled.text(0,0,"Number=%d",Number);
  oled.show();
}
