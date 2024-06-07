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
  if (BL1 == 1 and BR1==1) Backward(MotorSpeed, 1);
  else if (BL2 == 0) tr(70);
  else if (BL1 == 0) tr(40);
  else if (BR2 == 0) tl(70);
  else if (BR1 == 0) tl(40);
}

void TracNormalBW(int MotorSpeed, int Time) {  //แทรกเส้นธรรมดาเจอแยกหยุด
  Backward(MotorSpeed, 1);
  ConvertADC();
  while (BL2 == 1 || BR2 == 1) {  //ยังไม่เจอแยก
    TracBW(MotorSpeed);
  }
  Backward(MotorSpeed, Time);  //เดินหน้าไปอีกนิดตาม Time
}
