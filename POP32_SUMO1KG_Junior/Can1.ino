void Can1() {
  ConvertADC();
  if (C == 0) MotorStop();
  else if (L1 == 0 ) tl(80);
  else if (R1 == 0) tr(80);
  //else Forward(Speed, 1);
}
