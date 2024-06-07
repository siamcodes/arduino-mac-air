void ServoGrip() { //กำหนดองศาการคีบ
  for(int pos = 46; pos >= 6; pos -= 1) {
    servo(6, pos);
    delay(20);
  }
}

void ServoGripFast() { //กำหนดองศาการคีบ
  for(int pos = 46; pos >= 6; pos -= 1) {
    servo(6, pos);
    delay(1);
  }
}

void ServoPut() { //กำหนดองศาการปล่อย
  for(int pos = 6; pos <= 80; pos += 1) {
    servo(6, pos);
    delay(1);
  }
}

void ServoPutWide() { //กำหนดองศาการปล่อย
  for(int pos = 6; pos <= 100; pos += 1) {
    servo(6, pos);
    delay(1);
  }
}

void ServoGripUp() { //กำหนดองศาการยกขึ้น
  for(int pos = 0; pos <= 179; pos += 1) {
    servo(5, pos);
    delay(7);
  }
}

void ServoGripUpFrom45() { //กำหนดองศาการยกขึ้น
  for(int pos = 45; pos <= 179; pos += 1) {
    servo(5, pos);
    delay(7);
  }
}

void ServoGripDown() { //กำหนดองศาการยกลง
  for(int pos = 179; pos >= 0; pos -= 1) {
    servo(5, pos);
    delay(1);
  }
}

void ServoGripDown90() { //กำหนดองศาการยกลง
  for(int pos = 179; pos >= 90; pos -= 1) {
    servo(5, pos);
    delay(1);
  }
}

void ServoGripDown180() { //กำหนดองศาการยกลง
  for(int pos = 90; pos >= 0; pos -= 1) {
    servo(5, pos);
    delay(1);
  }
}

void ServoGripDown45() { //กำหนดองศาการยกลง 45 องศา
  for(int pos = 179; pos >= 45; pos -= 1) {
    servo(5, pos);
    delay(1);
  }
}

void Grip() { //คีบหน่วงเวลา
  ao();
  ServoGrip();
  delay(50);
}

void GripFast() { //คีบหน่วงเวลา
  ao();
  ServoGripFast();
  delay(50);
}

void Put() { //ปล่อยหน่วงเวลา
  ao();
  ServoPut();
  delay(50);
}

void PutWide() { //ปล่อยหน่วงเวลา
  ao();
  ServoPutWide();
  delay(50);
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  ao();
  ServoGripUp();
  delay(50);
}

void GripUpFrom45() { //ยกแขนขึ้นหน่วงเวลา
  ao();
  ServoGripUpFrom45();
  delay(50);
}

void GripDown() { //ยกแขนลงหน่วงเวลา
  ao();
  ServoGripDown();
  delay(50);
}

void GripDown45() { //ยกแขนลงหน่วงเวลา 45 องศา
  ao();
  ServoGripDown45();
  delay(50);
}

void GripDown90() { //ยกแขนลงหน่วงเวลา 45 องศา
  ao();
  ServoGripDown90();
  delay(50);
}

void GripDown180() { //ยกแขนลงหน่วงเวลา 45 องศา
  ao();
  ServoGripDown180();
  delay(50);
}

void GripCan(){
  //Put();
  GripDown90();         //ยกแขนลง
  PutWide();
  GripDown180();
  GripFast();           //คีบ
  Backward(30,250);
  GripUp();       //ยกแขนขึ้น
}

void GripCan2(){
  //Put();
  GripDown45();         //ยกแขนลง
  PutWide();
  Grip();
  GripUpFrom45();       //ยกแขนขึ้น
}

void PutCan(){
  GripDown();     //ยกแขนลง
  Put();          //ปล่อย
  GripUp();    //ยกแขนขึ้น
}
