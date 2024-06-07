int ML1 = 5, ML2 = 6, MR1 = 9, MR2 = 10 ;
int L, C, R, FL, FR;
int RefL, RefC, RefR, RefFL, RefFR;
int Speed, ACCSpeed, SlowSpeed, TurnSpeed, LeftSpeed, RightSpeed; //ตัวแแปรความเร็วมอเตอร์
int Kp, Ki, Kd, Error, PreError, Integral, MaxSpeed; //ตัวแปรแกี่ยวกับ PID

void setup() {
  Serial.begin(9600);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);

  InitialADC();  //ใส่ค่าเฉลี่ยของเซนเซอร์

  // Forward(250, 250, 2000);
  // Backward(250, 250, 2000);
  // TurnLeft(100, 100, 500);
 // TurnRight(100, 100, 500);
 // MotorStop(1000);
  delay(3000);
}

void loop() {
  // ShowADC();
   Can();   //ภาระกิจ
}
