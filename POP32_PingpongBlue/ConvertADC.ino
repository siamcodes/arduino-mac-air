void ConvertADC()   //เปลี่ยนจาก analog เป็น digital (สีเขียว=1 สีขาว=0) LED สีน้ำเงิน
{
  ReadADC();  //อ่านค่าสี
  if (L2 > RefL2) L2 = 0; else L2 = 1;
  if (L1 > RefL1) L1 = 0; else L1 = 1;
  if (C > RefC) C = 0; else C = 1;
  if (R1 > RefR1) R1 = 0; else R1 = 1;
  if (R2 > RefR2) R2 = 0; else R2 = 1;

  if (BL2 > RefBL2) BL2 = 0; else BL2 = 1;
  if (BL1 > RefBL1) BL1 = 0; else BL1 = 1;
  if (BR1 > RefBR1) BR1 = 0; else BR1 = 1;
  if (BR2 > RefBR2) BR2 = 0; else BR2 = 1;  
}
