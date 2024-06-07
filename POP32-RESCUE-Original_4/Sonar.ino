void CheckWallBalance() {
  ReadADC();
  if (Dist >= 84) {
    ReadADC();
    MotorStop();
    delay(200);
    Backward(40, 500);
    sl(30);
    while (Dist >= 84) {
      ReadADC();
    }
  }
}

void CheckWallBalanceRight() {
  ReadADC();
  if (Dist >= 84) {
    ReadADC();
    MotorStop();
    delay(200);
    Backward(40, 500);
    sr(30);
    while (Dist >= 84) {
      ReadADC();
    }
  }
}

void WallDecide() {
  ReadADC();
  if (Dist <= 40) {
    ReadADC();
    Backward(30, 300);
    Left();
  }
  else if(Dist > 40){
    ReadADC();
    Backward(30, 300);
    Right();
  }
}

void WallDecision() {
  ReadADC();
  if (Dist > 80) {
    ReadADC();
    Backward(30, 300);
    Left();
  }
  ReadADC();
}

void WallDecisionRight() {
  ReadADC();
  if (Dist >= 84) {
    ReadADC();
    Backward(30, 300);
    Right();
  }
}
