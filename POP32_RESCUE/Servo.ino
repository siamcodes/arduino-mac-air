void ServoGrip() { //กำหนดองศาการคีบ
  for (int pos = 90; pos >= 0; pos -= 1) {
    servo(1, pos);
    delay(5);
  }
}

void ServoPut() { //กำหนดองศาการปล่อย
  servo(1, 90);
}

void ServoGripUp() { //กำหนดองศาการยกขึ้น
  servo(2, 0);
}

void ServoGripDown() { //กำหนดองศาการยกลง
  servo(2, 90);
}


void Grip() { //คีบหน่วงเวลา
  AO();
  ServoGrip();
  delay(400);
}

void Put() { //ปล่อยหน่วงเวลา
  AO();
  ServoPut();
  delay(200);
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  AO();
  ServoGripUp();
  delay(500);
}


void GripDown() { //ยกแขนลงหน่วงเวลา
  AO();
  ServoGripDown();
  delay(500);
}
