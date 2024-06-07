void CalError() {   //กำรคำนวณ Error
  ConvertADC();    //เปลี่ยนจาก analog เป็น digital (สีดำ=0 สีขาว=1)
  if ((L1 == 1) && (C == 1) && (R1 == 0)) Error = 2;
  else if ((L1 == 1) && (C == 0) && (R1 == 0)) Error = 1;
  else if ((L1 == 1) && (C == 0) && (R1 == 1)) Error = 0;
  else if ((L1 == 0) && (C == 0) && (R1 == 1)) Error = -1;
  else if ((L1 == 0) && (C == 1) && (R1 == 1)) Error = -2;
  else if ((L1 == 1) && (C == 1) && (R1 == 1)) Error = 99;   //สิ้นสุดทาง
  else if ((L1 == 0) && (C == 0) && (R1 == 0)) Error = 100;     //แยก + T
  else if ((L1 == 0) && (C == 0)) Error = 101;    //แยกซ้าย
  else if ((R1 == 0) &&  (C == 0)) Error = 102;    //แยกขวา
}
