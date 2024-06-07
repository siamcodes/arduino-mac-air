void box() {
  int Status = 0;
  while (Status == 0) {
    ReadADC();
    WallDecision();
    ForwardBalance();
    ConvertADC();
    if (Wall == 0) {
      MotorStop();
      Backward(40, 200);
      GripCan2();
      Status = 1;
    }
    else
    {
      MotorStop();
      Backward(40, 600);
      Left();
      Status = 0;
    }
  }
  MotorStop();
  beep();
}

void AvoidOthers() {
  if (greenfound == true) {
    if (pixy.updateBlocks() && pixy.sigSize[2]) {
      if (pixy.sigInfo[2][0].x > 150) {
        Left();
        CheckWallBalanceRight();
      }
      else if (pixy.sigInfo[2][0].x < 150) {
        Right();
        CheckWallBalanceRight();
      }
    }
  }
  else if (greenfound == true) {
    if (pixy.updateBlocks() && pixy.sigSize[3]) {
      if (pixy.sigInfo[3][0].x > 150) {
        Left();
        CheckWallBalanceRight();
      }
      else if (pixy.sigInfo[3][0].x < 150) {
        Right();
        CheckWallBalanceRight();
      }
    }
  }
  else if (bluefound == true) {
    if (pixy.updateBlocks() && pixy.sigSize[3]) {
      if (pixy.sigInfo[3][0].x > 150) {
        Left();
        CheckWallBalanceRight();
      }
      else if (pixy.sigInfo[3][0].x < 150) {
        Right();
        CheckWallBalanceRight();
      }
    }
  }
}
