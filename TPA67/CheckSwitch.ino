void checkSwitch(){
    if (in(4) == 0 && in(5) == 0) {
    bk(50); delay(400);
    ao();   delay(200);
    sr(50); delay(700);
    ao();   delay(200);
    // while (1) {
    //   bk(50); delay(1);
    //   if (in(6) == 0 && in(7) == 0) {
    //     sv2();
    //     break;
    //   }
    // }
  } else if (in(4) == 0) {
    bk(40);  delay(100);
    MotorStop(100);
    while (1) {
      fd2(60,20);
      if (in(4) == 0 && in(5) == 0){ 
        MotorStop(10);
        break; 
      } 
    }
    ao();
  } else if (in(5) == 0) {
     bk(40); delay(100);
     MotorStop(100);
    while (1) {
      fd2(20,60);  
      if (in(4) == 0 && in(5) == 0){ 
        MotorStop(10);
        break; 
      } 
    }
    ao();
  }else{
     Move(20,20,50);  //เดินวน ขวา
     sr(20); delay(50);
  }
}