void wheel(int s1, int s2, int s3) {
  motor(1, s1);
  motor(2, s2);
  motor(3, s3);
}

void Forward(int w, int Time) { //Forward
  wheel(w, -w, w - w); //Example (25,-25,0)
  delay(Time);
  ao();
}

void Backward(int w, int Time) { //Backward
  wheel(-w, w, w - w); //Example (-25,25,0)
  delay(Time);
  ao();
}

void Right(int w, int Time) { //ไปทางด้านขวา
  wheel(-w, -w, w * 2); //Example (-25,-25,50)
  delay(Time);
  ao();
}

void Left(int w, int Time) { //ไปทางด้านซ้าย
  wheel(w, w, -w * 2); //Example (25,25,-50)
  delay(Time);
  ao();
}

void UturnLeft(int w, int Time) { //หมุนซ้าย
  wheel(w, w, w); //Example (50, 50, 50)
  delay(Time);
  ao();
}

void UturnRight(int w, int Time) { //หมุนซ้าย
  wheel(-w, -w, -w); //Example (-50, -50, -50)
  delay(Time);
  ao();
}

void FrontLeft(int w, int Time) { //ทะแยงซ้ายไปข้างหน้า
  // float v1 = w * cos(30) - (-w) * sin(30);
  // float v2 = -(w) * cos(30) - (-w) * sin(30);
  // wheel(v1, -v2, -w); //Example (68, -18, -50)
  wheel(68, -18, -50);
  delay(Time);
  ao();
}

void FrontRight(int w, int Time) { //ทะแยงขวาไปข้างหน้า
  //float v1 =  (w) * cos(30) - (w) * sin(30) ;
  //float v2 = -(w) * cos(30) - (w) * sin(30);
  //wheel(v1, -v2, w); //Example (18, -68, 50)
  wheel(18, -68, 50);
  delay(Time);
  ao();
}
