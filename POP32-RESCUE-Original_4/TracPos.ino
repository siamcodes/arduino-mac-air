void Walkout() {
  Backward(60,300);
  Right();
  ForwardBalance();
  Backward(30,200);
  UTL();
  while (wayout == false) {  
    Forward(20,1000);
    while (pixy.updateBlocks() && pixy.sigSize[4]) {
      int x = pixy.sigInfo[4][0].x;
      head_error = head_sp2 - x;
      hI = hI + head_error;
      hI = constrain(hI, -SlowerSpeed, SlowerSpeed);
      hD = head_error - hPrevError;
      head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
      int leftSpeed = constrain(-head_spd, -Speed, Speed);
      int rightSpeed = constrain(head_spd, -Speed, Speed);
      motor(1, leftSpeed); motor(2, rightSpeed);
      hPrevError = head_error;
      if (abs(head_error) < h_gapWalk) {
        int y = pixy.sigInfo[4][0].y;
        dis_error = dis_sp2 - y;
        dI = dI + dis_error;
        dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
        dD = dis_error - dPrevError;
        dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
        int leftSpeed = constrain(dis_spd, -Speed, Speed);
        int rightSpeed = constrain(dis_spd, -Speed, Speed);
        motor(1, leftSpeed); motor(2, rightSpeed);
        dPrevError = dis_error;
        if (abs(head_error) < h_gapWalk && abs(dis_error) < d_gapWalk) {
          beep();
          tl(25);
          delay(200);
          fd(50);
          delay(4000);
          wayout = !wayout;
        }
      }
    }
  }
}

void Walkback() {
  bk(30);
  delay(1000);
  sl(30);
  delay(1500);
}

void AvoidRed() {
  while (pixy.updateBlocks() && pixy.sigSize[4]) {
    pixy.setLamp(0,0);
    pixy.setCameraBrightness(140);
    //int x = pixy.sigInfo[4][0].x;
    int y = pixy.sigInfo[4][0].y;
    if (y <= 50) {
      ao();
      beep();
      delay(200);
      sr(40);
      delay(300);
      ConvertADC();
      while (pixy.updateBlocks() && pixy.sigSize[4]) {
        ConvertADC();
      }
      MotorStop();
      /*
        int x = pixy.sigInfo[4][0].x;
        int y = pixy.sigInfo[4][0].x;
        head_error = head_sp - x;
        dis_error = dis_sp - y;
        hI = hI + head_error;
        dI = dI + dis_error;
        hI = constrain(hI, -SlowerSpeed, SlowerSpeed);
        dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
        hD = head_error - hPrevError;
        dD = dis_error - dPrevError;
        head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
        dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
        int leftSpeed = constrain(dis_spd - head_spd, -SlowerSpeed, SlowerSpeed);
        int rightSpeed = constrain(dis_spd + head_spd, -SlowerSpeed, SlowerSpeed);
        motor(1, leftSpeed); motor(2, rightSpeed);
        hPrevError = head_error;
        dPrevError = dis_error;*/
    }
  }
}

void TracPosGreen() {
  while (greenfound == false) {
    pixy.setLamp(2,2);
    pixy.setCameraBrightness(100);
    fd2(40, TracposSpeed);
    //AvoidRed();
    TracposSpeed += 1;
    if (TracposSpeed > Count) {
      Count = Count + 1;
      if(Count > 30){
        Count = 23;
      }
      TracposSpeed = 0;
      TourTime = 50;
      ReadADC();
      CheckWallBalance();
    }
    SwIn();
    while (pixy.updateBlocks() && pixy.sigSize[1] && greenfound == false) {
      int x = pixy.sigInfo[1][0].x;
      int y = pixy.sigInfo[1][0].y;
      head_error = head_sp - x;
      hI = hI + head_error;
      hI = constrain(hI, -SlowerSpeed, SlowerSpeed);
      hD = head_error - hPrevError;
      head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
      dis_error = dis_sp - y;
      dI = dI + dis_error;
      dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
      dD = dis_error - dPrevError;
      dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
      int leftSpeed = constrain(dis_spd - head_spd, -SlowerSpeed, SlowerSpeed);
      int rightSpeed = constrain(dis_spd + head_spd, -SlowerSpeed, SlowerSpeed);
      motor(1, leftSpeed); motor(2, rightSpeed);
      dPrevError = dis_error;
      hPrevError = head_error;
      if ((abs(head_error) < h_gapfinal) && (abs(dis_error) < d_gapfinal)) {
        motor(1, 0);
        motor(2, 0);
        beep();
        //delay(30);
        GripCan();
        delay(500);
        greenfound = !greenfound;
        WallDecide();
      }
    }
    delay(TourTime);
    TourTime = TourTime + 5;
  }
}

void TracPosBlue() {
  while (bluefound == false) {
    pixy.setLamp(5,5);
    pixy.setCameraBrightness(104);
    fd2(TracposSpeed, 40);
    //AvoidRed();
    TracposSpeed += 1;
    if (TracposSpeed > Count) {
      Count = Count + 1;
      if(Count > 30){
        Count = 23;
      }
      TracposSpeed = 0;
      TourTime = 50;
      ReadADC();
      CheckWallBalance();
    }
    SwInInverted();
    while (pixy.updateBlocks() && pixy.sigSize[2] && bluefound == false) {
      int x = pixy.sigInfo[2][0].x;
      head_error = head_sp - x;
      hI = hI + head_error;
      hI = constrain(hI, -SlowerSpeed, SlowerSpeed);
      hD = head_error - hPrevError;
      head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
      int leftSpeed = constrain(-head_spd, -SlowerSpeed, SlowerSpeed);
      int rightSpeed = constrain(head_spd, -SlowerSpeed, SlowerSpeed);
      motor(1, leftSpeed); motor(2, rightSpeed);
      hPrevError = head_error;
      if ((abs(head_error) < h_gap)) {
        int y = pixy.sigInfo[2][0].y;
        dis_error = dis_sp - y;
        dI = dI + dis_error;
        dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
        dD = dis_error - dPrevError;
        dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
        int leftSpeed = constrain(dis_spd, -SlowerSpeed, SlowerSpeed);
        int rightSpeed = constrain(dis_spd, -SlowerSpeed, SlowerSpeed);
        motor(1, leftSpeed); motor(2, rightSpeed);
        dPrevError = dis_error;
        if ((abs(head_error) < h_gapfinal) && (abs(dis_error) < d_gapfinal)) {
          motor(1, 0);
          motor(2, 0);
          beep();
          //delay(30);
          GripCan();
          delay(500);
          bluefound = !bluefound;
          WallDecide();
        }
      }
    }
    delay(TourTime);
    TourTime = TourTime + 5;
  }
}

void TracPosYellow() {
  while (yellowfound == false) {
    pixy.setLamp(5,5);
    pixy.setCameraBrightness(50);
    fd2(TracposSpeed, 40);
    //AvoidRed();
    TracposSpeed += 1;
    if (TracposSpeed > Count) {
      Count = Count + 1;
      if(Count > 30){
        Count = 23;
      }
      TracposSpeed = 0;
      TourTime = 50;
      ReadADC();
      CheckWallBalance();
    }
    SwInInverted();
    while (pixy.updateBlocks() && pixy.sigSize[3] && yellowfound == false) {
      int x = pixy.sigInfo[3][0].x;
      head_error = head_sp - x;
      hI = hI + head_error;
      hI = constrain(hI, -SlowerSpeed, SlowerSpeed);
      hD = head_error - hPrevError;
      head_spd = (head_Kp * head_error) + (hI * head_Ki) + (hD * head_Kd) ;
      int leftSpeed = constrain(-head_spd, -SlowerSpeed, SlowerSpeed);
      int rightSpeed = constrain(head_spd, -SlowerSpeed, SlowerSpeed);
      motor(1, leftSpeed); motor(2, rightSpeed);
      hPrevError = head_error;
      if ((abs(head_error) < h_gap)) {
        int y = pixy.sigInfo[3][0].y;
        dis_error = dis_sp - y;
        dI = dI + dis_error;
        dI = constrain(dI, -SlowerSpeed, SlowerSpeed);
        dD = dis_error - dPrevError;
        dis_spd = (dis_Kp * dis_error) + (dI * dis_Ki) + (dD * dis_Kd);
        int leftSpeed = constrain(dis_spd, -SlowerSpeed, SlowerSpeed);
        int rightSpeed = constrain(dis_spd, -SlowerSpeed, SlowerSpeed);
        motor(1, leftSpeed); motor(2, rightSpeed);
        dPrevError = dis_error;
        if ((abs(head_error) < h_gapfinal) && (abs(dis_error) < d_gapfinal)) {
          motor(1, 0);
          motor(2, 0);
          beep();
          //delay(30);
          GripCan();
          delay(500);
          yellowfound = !yellowfound;
          WallDecide();
        }
      }
    }
    delay(TourTime);
    TourTime = TourTime + 5;
  }
}
