void CN1()     //สนามที่บ้าน
{
  Forward(SlowSpeed, 100);       //เดินจากจุดเริ่มต้น 200
  TracNormalJC(Speed, 200);
  TurnRight();                   //เลี้ยว
  TracNormalJC(Speed, 200);
  UTurn();                   //เลี้ยว
  TracNormalJC(Speed, 200);
  TurnLeft();                   //เลี้ยว
  TracNormalTime(Speed, 500); //แทรกหน่วงเวลา
}
