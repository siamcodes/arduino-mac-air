void Can() {
  ConvertADC();
  if ( C == 0)  Forward(100,3);
  else if (L2 == 0 ) TurnLeft();          //sl(100);
  else if (L1 == 0 )  TurnLeft1();          //sl(100);
  else if (R2 == 0) TurnRight();          //sr(100);
  else if (R1 == 0) TurnRight1();          //sr(100);
  else   Forward(Speed, 1);
}
