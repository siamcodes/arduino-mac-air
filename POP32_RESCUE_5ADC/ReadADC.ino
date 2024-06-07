void ReadADC()  //อ่านค่าเซ็นเซอร์หน้า 7 ตัว
{
  L1 = analog(2);
  C = analog(1);
  R1 = analog(0);
}

void ReadADCBack()  //อ่านค่าเซ็นเซอร์หลัง 5 ตัว
{
  BL1 = analog(6);
  BR1 = analog(5);
}
