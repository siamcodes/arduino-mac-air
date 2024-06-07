void Can() {
  ConvertADC();
  if (FL == 0 || FR == 0 ) {
    MotorStop(10);
    Backward(100, 100, 500);
    MotorStop(10);
    UTurn(100, 100, 200);
    MotorStop(10);
  } else {
    Forward(60, 60, 1);
//    if (C == 0) MotorStop(10);  //Forward(250, 200, 1);
//    else if (L == 0) TurnLeft(250, 200, 1);
//    else if (R == 0) TurnRight(250, 200, 1);
//    else if (C == 0 && L == 0) TurnLeft(200, 150, 1);
//    else if (C == 0 && R == 0) TurnRight(200, 150, 1);
  }
}
