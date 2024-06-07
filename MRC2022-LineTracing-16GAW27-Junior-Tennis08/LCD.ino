void ShowSonar()
{
  glcdClear();
  glcd(0,0,"Distance=%d",Sonar());
}
void Show(int Number)
{
  glcdClear();
  glcd(0,0,"Number=%d",Number);
}
