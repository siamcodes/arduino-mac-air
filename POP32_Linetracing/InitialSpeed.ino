void InitialSpeed(int MotorSpeed) {
  Error = 0 ; //ให้ Error เป็น 0
  PreError = 0;
  Integral = 0;
  Ki = 0;
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed < 50) {
    Kp = 10;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 20;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู
    LeftSpeed = MotorSpeed - 0;
    RightSpeed = MotorSpeed - 0;
  }
  else if (MotorSpeed <= 70) {
    Kp = 20;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 40;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู
    LeftSpeed = MotorSpeed - 0;
    RightSpeed = MotorSpeed - 0;
  }
  else if (MotorSpeed <= 100) {
    Kp = 40;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 60;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู
    LeftSpeed = MotorSpeed - 0;
    RightSpeed = MotorSpeed - 0;
  }
}
