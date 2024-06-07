void ConvertADC() //เปลี่ยนจาก analog เป็น digital (สีขาว=0 สีดำ=1)
{
  ReadADC();      //อ่านค่าสี
  if (FL < RefFL) FL = 0; else FL = 1;
  if (FR < RefFR) FR = 0; else FR = 1;
}
