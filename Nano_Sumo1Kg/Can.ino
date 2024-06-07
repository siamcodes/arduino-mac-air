void Can() {
  ConvertADC();
  if (FL == 0 || FR == 0 ) {
    digitalWrite(LED, LOW);
    MotorStop(10);
    Backward(140, 100, 200);
    MotorStop(10);
    UTurn(130, 130, 300);
    MotorStop(10);
    digitalWrite(LED, HIGH);
  } else {
    Forward(130, 90, 1);
    if (C == 0) MotorStop(1000);  //Forward(250, 200, 1);
    else if (L == 0) TurnLeft(250, 100, 1);
    else if (R == 0) TurnRight(250, 100, 1);
    else if (C == 0 && L == 0) TurnLeft(200, 150, 1);
    else if (C == 0 && R == 0) TurnRight(200, 150, 1);
  }
}
