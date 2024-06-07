void ReadADC() {
  L3 = analog(6);
  L2 = analog(5);
  L1 = analog(4);
  C = analog(3);
  R1 = analog(2);
  R2 = analog(1);
  R3 = analog(0);

}

int Sonar()
{
  int Sonar;

  //Sonar = (analog(0)/10); //ZX-sonor
  Sonar = analog(8);   //infared
  if (Sonar == 0) Sonar = 1;
  Sonar = 3000 / Sonar;
  return (Sonar);
}
