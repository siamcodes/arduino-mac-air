void ConvertADC() //เปลี่ยนจาก analog เป็็น digital (สีดำ=0 สีขาว=1)
{
  ReadADC();  //อ่านค่าสี
  if (L < Ref) L = 0; else L = 1;
  if (C < Ref) C = 0; else C = 1;
  if (R < Ref) R = 0; else R = 1;
}
