void CalError() {   //กำรคำนวณ Error
  ConvertADC();     //เปลี่ยนจาก analog เป็็น digital (สีดำ=0 สีขาว=1)
  if ( (L2 == 1) && (L1 == 1) && (C == 1)  && (R1 == 1) && (R2 == 0) ) Error = 4;
  else if ( (L2 == 1) && (L1 == 1) && (C == 1)  && (R1 == 0) && (R2 == 0) ) Error = 3;
  else if ( (L2 == 1) && (L1 == 1) && (C == 1)  && (R1 == 0) && (R2 == 1) ) Error = 2;
  else if ( (L2 == 1) && (L1 == 1) && (C == 0)  && (R1 == 0) && (R2 == 1)) Error = 1;
  else if ( (L2 == 1) && (L1 == 1) && (C == 0)  && (R1 == 1) && (R2 == 1) ) Error = 0;
  else if ( (L2 == 1) && (L1 == 0) && (C == 0)  && (R1 == 1) && (R2 == 1) ) Error = -1;
  else if ( (L2 == 1) && (L1 == 0) && (C == 1)  && (R1 == 1) && (R2 == 1) ) Error = -2;
  else if ( (L2 == 0) && (L1 == 0) && (C == 1)  && (R1 == 1) && (R2 == 1) ) Error = -3;
  else if ( (L2 == 0) && (L1 == 1) && (C == 1)  && (R1 == 1) && (R2 == 1) ) Error = -4;
  // else if ( (L2 == 1) && (L1 == 1)  && (R1 == 1) && (R2 == 1)) Error = 99;              //สิ้นสุดทาง
  else if ( (L2 == 0) && (L1 == 0) && (C == 0)  && (R1 == 0) && (R2 == 0) ) Error = 100;  //แยก + T
  else if ( (L2 == 0) && (L1 == 0) && (C == 0)) Error = 101;    //แยกซ้าย
  else if ( (C == 0) && (R1 == 0) && (R2 == 0) ) Error = 102;   //แยกขวา
}

void CalErrorBack() {
  ConvertADC();
  if ((BL == 1) && (BC == 1)  && (BR == 0)) ErrorB = 2;
  else if ((BL == 1) && (BC == 0)  && (BR == 0)) ErrorB = 1;
  else if ((BL == 1) && (BC == 0)  && (BR == 1)) ErrorB = 0;
  else if ((BL == 0) && (BC == 0)  && (BR == 1)) ErrorB = -1;
  else if ((BL == 0) && (BC == 1)  && (BR == 1)) ErrorB = -2;
  // else if ((BL == 1)&& (BC == 1)  && (BR == 1)) ErrorB = 99;              //สิ้นสุดทาง
  else if ((BL == 0) && (BC == 0)  && (BR == 0)) ErrorB = 100; //แยก + T
  else if ((BL == 0) && (BC == 0)) ErrorB = 101;   //แยกซ้าย
  else if ((BC == 0)  && (BR == 0)) ErrorB = 102;   //แยกขวา
}
