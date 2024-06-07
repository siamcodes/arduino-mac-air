void ConvertADC() //เปลี่ยนจาก analog เป็น digital (สีดำ=1 สีขาว=0)
{
  ReadADC();  //อ่านค่าสี
  if (L1 < RefL1) L1 = 0; else L1 = 1;
  if (C < RefC) C = 0; else C = 1;
  if (R1 < RefR1) R1 = 0; else R1 = 1;
  if (BC < RefBC) BC = 0; else BC = 1; 
}
