void Ball() {    //ตามเก็บบอล
  Move(30,30,100);

  while ((pixy.updateBlocks() && pixy.sigSize[1]) || (pixy.updateBlocks() && pixy.sigSize[2]) || (pixy.updateBlocks() && pixy.sigSize[3])) {
    MotorStop(10);
    Find();
  }
  //popB();  //วางบอล ภายในจะเช็คสวิตช์ด้วย
}