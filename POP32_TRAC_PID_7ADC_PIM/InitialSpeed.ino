void InitialSpeed(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  Error = 0 ; //ให้ Error เป็น 0
  PreError = 0;
  Integral = 0;
  Ki = 0;
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 50)
  {
    Kp = 20;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 2000;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู 
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 70)
  {
    Kp = 25;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 400;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู  
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 100)
  {
    Kp = 25;                //ทำให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 600;                //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
}

void InitialSpeed2(int MotorSpeed) { //กำหนดความเร็วให้หุ่นยนต์ หลายๆ สเต็ป
  Error = 0 ; //ให้ Error เป็น 0
  PreError = 0;
  Integral = 0;
  Ki = 0;
  MaxSpeed = MotorSpeed;  //ให้ MaxSpeed เท่ากับค่า MotorSpeed ที่กำหนด

  if (MotorSpeed <= 50)
  {
    Kp = 50;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 1000;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู 
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 70)
  {
    Kp = 20;            //ทำให้หุ่นยนต์ไม่หลุดเส้น ทางโค้งอาจหลุดเส้น ก็ให้เพิ่ม
    Kd = 1500;            //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆอาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู  
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
  else if (MotorSpeed <= 100)
  {
    Kp = 20;                //ทำให้หุ่นยนต์ไม่หลุดเส้น
    Kd = 1500;                //ค่าที่ให้หุ่นยนต์ไม่สาย เยอะยิ่งดีไม่ส่าย  เยอะมากๆ อาจให้สบัดแรงเกิน ถ้าน้อยจะเลื้อยเป็นงู ก็เพิ่ม   
    LeftSpeed = MotorSpeed;
    RightSpeed = MotorSpeed;
  }
}
