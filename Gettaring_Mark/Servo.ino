//////////////////////////////////
//คีบ-ปล่อย ใช้Servo 1
/*void ServoGrip() {  //กำหนดองศาการคีบ
  for (int pos = 90; pos >= 0; pos -= 1) { //90-0 องศา
    servo(1, pos); //1=Servo1, 90=องศาServo
    delay(3);
  }
}

void ServoPut() {   //กำหนดองศาการปล่อย  90 องศา
  for (int pos = 0; pos <= 90; pos += 1) { //0-90 องศา
    servo(1, pos);
    delay(3);
  }
}

void Grip() { //คีบหน่วงเวลา
  ao();
  ServoGrip();
  delay(200);  //200
}

void Put() { //ปล่อยหน่วงเวลา
  ao();
  ServoPut();
  delay(200);  //200
}

/////////////////////////////////
//ยกขึ้น-ลง ใช้Servo 2
void ServoGripDown() { //กำหนดองศาการยกลง
  for (int pos = 90; pos >= 0; pos -= 1) {
    Servo(2, pos);
    delay(3);
  }
}

void ServoGripUp() { //กำหนดองศาการยกขึ้น ถ้า 180 ยกเติมที่
  for (int pos = 0; pos <= 90; pos += 1) {
    servo(2, pos);
    delay(3);
  }
}

void GripUp() { //ยกแขนขึ้นหน่วงเวลา
  ao();
  ServoGripUp();
  delay(50);  //200
}

void GripDown() { //ยกแขนลงหน่วงเวลา
  ao();
  ServoGripDown();
  delay(50);  //200
}

/////////////////////////////////////
void GripCan() {
  GripDown();     //ยกแขนลง
  Grip();         //คีบ
  GripUp();       //ยกแขนขึ้น
}

void PutCan() {
  GripDown();     //ยกแขนลง
  Put();          //ปล่อย
  GripUp();       //ยกแขนขึ้น
}
*/

void servo(int ch, int degree) {
  if (ch == 1) {
    if (degree == -1) myservo[0].detach();
    else {
      if (!myservo[0].attached()) myservo[0].attach(9);
      myservo[0].write(degree);
    }
  }
  else if (ch == 2) {
    if (degree == -1) myservo[1].detach();
    else {
      if (!myservo[1].attached()) myservo[1].attach(10);
      myservo[1].write(degree);
    }
  }
  else if (ch == 3) {
    if (degree == -1) myservo[2].detach();
    else {
      if (!myservo[2].attached()) myservo[2].attach(11);
      myservo[2].write(degree);
    }
  }
}