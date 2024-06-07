void Can1Normal() //นำคำสั่งต่างๆมาใส่เพื่อในการทำภารกิจ
{
  Forward(Speed, 100);          //เดินจากจุดเริ่มต้น 100
  TracNormalJC(Speed, 55);      //แทรกเดินเตรีียมเลี้ยว
  TurnRight();                   //เลี้ยว
  TracNormalTime(ACCSpeed, 2000);
  TracNormalJC(Speed, 55);      //แทรกเดินเตรีียมเลี้ยว
  TurnRight();                   //เลี้ยว
  TracNormalJC(Speed, 55);      //แทรกเดินเตรีียมเลี้ยว
  UTurnSlow();                   //เลี้ยว
  TracNormalJC(Speed, 55);
  TurnLeft();
  TracNormalJC(Speed, 55);
  TurnLeft();
  TracNormalTime(Speed, 2000); //แทรกหน่วงเวลา
}
