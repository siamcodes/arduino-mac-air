void InitialSpeed(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  Error = 0 ;           //ให้ Error เป็น 0
  PreError = 0;
  Integral = 0;
  Ki = 0;
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 60)
  {
    Kp = 20;            //ทำใให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    Kd = 40;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม
    LeftSpeed = MotorSpeed-2;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 70)
  {
    Kp = 30;            //ทำใให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    Kd = 60;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 100)
  {
    Kp = 120;             //ทำใให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 160;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
}

void InitialSpeedB(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  ErrorB = 0 ;           //ให้ Error เป็น 0
  PreErrorB = 0;
  IntegralB = 0;
  KiB = 0;
  MaxSpeedB = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 50)
  {
    KpB = 50;            //ทำใให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    KdB = 80;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 70)
  {
    KpB = 50;            //ทำใให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้มาเพิ่ม
    KdB = 70;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 100)
  {
    KpB = 60;             //ทำใให้หุ่นยนต์ไม่หลุดเส้น
    KdB = 100;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
}
