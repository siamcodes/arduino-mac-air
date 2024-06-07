void ConvertADC()
{
  ReadADC();  //อ่านค่าสี
  if (L3 < RefL3) L3 = 0; else L3 = 1;
  if (L2 < RefL2) L2 = 0; else L2 = 1;
  if (L1 < RefL1) L1 = 0; else L1 = 1;
  if (C < RefC) C = 0; else C = 1;
  if (R1 < RefR1) R1 = 0; else R1 = 1;
  if (R2 < RefR2) R2 = 0; else R2 = 1;
  if (R3 < RefR3) R3 = 0; else R3 = 1;
}

void CalError() {
  ConvertADC();

  ConvertADC();    //เปลี่ยนจาก analog เป็น digital (สีดำ=0 สีขาว=1)
  if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 0)) Error = 6;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 0) && (R3 == 0)) Error = 5;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 0) && (R3 == 1)) Error = 4;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 0) && (R2 == 0) && (R3 == 1)) Error = 3;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 0) && (R2 == 1) && (R3 == 1)) Error = 2;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 0) && (R1 == 0) && (R2 == 1) && (R3 == 1)) Error = 1;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 0) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = 0;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 0) && (C == 0) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = -1;
  else if ((L3 == 1) && (L2 == 1) && (L1 == 0) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = -2;
  else if ((L3 == 1) && (L2 == 0) && (L1 == 0) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = -3;
  else if ((L3 == 1) && (L2 == 0) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = -4;
  else if ((L3 == 0) && (L2 == 0) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = -5;
  else if ((L3 == 0) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = -6;
  //else if ((L3 == 1) && (L2 == 1) && (L1 == 1) && (C == 1) && (R1 == 1) && (R2 == 1) && (R3 == 1)) Error = 99;   //สิ้นสุดทาง
  else if ((L3 == 0) && (L2 == 0) && (L1 == 0) && (C == 0) && (R1 == 0) && (R2 == 0) && (R3 == 0)) Error = 100;     //แยก + T
  else if ((L3 == 0) && (L2 == 0) && (L1 == 0) && (C == 0)) Error = 101;    //แยกซ้าย
  else if ((R1 == 0) && (R2 == 0) && (R3 == 0) && (C == 0)) Error = 102;    //แยกขวา

}

void TracPID()  {
  int Output, LeftSpeed, RightSpeed;
  Output = (Kp * Error) + (Ki * SumError) + (Kd * (Error - PreError));
  LeftSpeed = LeftBaseSpeed + Output;
  RightSpeed = RightBaseSpeed - Output;
  if (LeftSpeed > MaxSpeed) LeftSpeed = MaxSpeed;
  else if (LeftSpeed < -MaxSpeed) LeftSpeed = -MaxSpeed;
  //else if(LeftSpeed<0) LeftSpeed = 0;//new pid

  if (RightSpeed > MaxSpeed) RightSpeed = MaxSpeed;
  else if (RightSpeed < -MaxSpeed) RightSpeed = -MaxSpeed;
  //else if(RightSpeed<0) RightSpeed = 0;//new pid
  motor(1, LeftSpeed);
  motor(2, RightSpeed);
  PreError = Error;
  SumError += Error;
}
