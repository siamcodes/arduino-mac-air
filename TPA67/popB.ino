void popB() {
  //if (SW_A()) {  //เมื่อกดปุ่ม SW_A 
  //Auto_zero();
  // }
  while (1) {
    getIMU();
    TrackNormal(20, 0.50, 0.05);  //เรียกใช้ วิ่งไปยัง ค่า Yaw ที่กำหนด
    if (in(4) == 0 && in(5) == 0) {
      ao(); bk(50); delay(400);
      MotorStop(200);
      sr(50); delay(700);
      MotorStop(200);
      while (1) {
        bk(50);
        delay(1);
        if (in(6) == 0 && in(7) == 0) {
          MotorStop(10);  //ห
          sv2();  //วางบอล
          status = 4;
          break;
        }
      }
    }
    else if (in(4) == 0) {
    bk(40);  delay(100);
    MotorStop(100);
    while (1) {
      Move(60,20, 1);
      if (in(4) == 0 && in(5) == 0){ 
        MotorStop(10);
        break; 
      } 
    }
    //ao();
  } 
  else if (in(5) == 0) {
     bk(40); delay(100);
     MotorStop(100);
    while (1) {
      Move(20,60, 1);  
      if (in(4) == 0 && in(5) == 0){ 
        MotorStop(10); 
        break; 
      } 
    }
    //ao();
  }
  //else{
  //   Move(20,20,200);
  //   sl(20); delay(50);
  //}
}

//while (1) MotorStop(10); //หยุดตลอดไป เอาใว้ตรวจสอบ 
//เรียกใช้คำสั่งถัดไป ให้คอมเมนต์บรทัด while
  
}