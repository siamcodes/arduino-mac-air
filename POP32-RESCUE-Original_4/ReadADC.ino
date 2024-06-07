/*Tip
    * ควรเสียบเซ็นเซอร์เริ่มที่ช่อง Analog 0 แล้วเรียงจากขวาไปซ้าย ตาม void ReadADC()
*/

void ReadADC() {
  L2 = analog(3);
  L1 = analog(2);
  R1 = analog(1);
  R2 = analog(0);
  
  Dist = analog(4)/41;
  Wall = analog(8);
}
