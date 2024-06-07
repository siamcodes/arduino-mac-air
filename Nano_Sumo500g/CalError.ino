void CalError() {   //กำรคำนวณ Error
  ConvertADC();    //เปลี่ยนจาก analog เป็น digital (สีดำ=0 สีขาว=1)
  if ((L == 1)  && (C == 1) && (R == 0)) Error = 2;
  else if ((L == 1)  && (C == 0) && (R == 0)) Error = 1;
  else if ((L == 1)  && (C == 0) && (R == 1)) Error = 0;
  else if ((L == 0)  && (C == 0) && (R == 1)) Error = -1;
  else if ((L == 0)  && (C == 1) && (R == 1)) Error = -2;
  //else if ((L == 1)  && (C == 1) && (R == 1)) Error = 99;   //สิ้นสุดทาง
  else if ((L == 0)  && (C == 0) && (R == 0)) Error = 100;     //แยก + T
  else if ((L == 0) && (C == 0)) Error = 101;    //แยกซ้าย
  else if ((R == 0) && (C == 0)) Error = 102;    //แยกขวา
}
