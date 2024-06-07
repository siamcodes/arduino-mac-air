void Can() {
  ConvertADC();
  if ( C == 0) MotorStop();
  else if (L1 == 0 ) TurnLeft();     //sl(100);
  else if (R1 == 0) TurnRight();     //sr(100);
  else   Forward(Speed, 3);
}
