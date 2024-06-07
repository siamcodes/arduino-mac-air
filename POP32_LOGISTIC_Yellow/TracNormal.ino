void Trac(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if ( C == 0 ) Forward(MotorSpeed, 1);
  if (L2 == 0) tl(70);
  if (L1 == 0) tl(45);
  if (R2 == 0) tl(70);
  if (R1 == 0) tr(45);
}

void TracNormalJC(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Forward(MotorSpeed, 1);
  ConvertADC();
  while (L2 == 1 || R2 == 1) {  //ยังไม่เจอแยก
    Trac(MotorSpeed);
  }
  Forward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}

          
void TracBW(int MotorSpeed) { //เดินตามเส้นธรรมดา
  ConvertADC();
  if (BC == 0) Backward(MotorSpeed, 1);
  else if (BL == 0) tr(30);
  else if (BR == 0) tl(30);
}

void TracNormalBW(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Backward(MotorSpeed, 1);
  ConvertADC();
  while (BL == 1 || BR == 1) {  //ยังไม่เจอแยก
    TracBW(MotorSpeed);
  }
  Backward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}
