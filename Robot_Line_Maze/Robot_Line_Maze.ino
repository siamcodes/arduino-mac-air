boolean forward_flg = false;
boolean forward_black_flg = false;
boolean backward_flg = false;
boolean turnleft_flg = false;
boolean turnright_flg = false;

//int encoderL, encoderR;
int IN1 = 5, IN2 = 6;             //ขาสั่งงานมอเตอร์ล้อขวา 
int IN3 = 9, IN4 =10;             //ขาสั่งงานมอเตอร์ล้อซ้าย
int sensor_L = A0, sensor_R = A5; //ขาเซ็นเซอร์ตรวจจับเส้น
int switch_start = 12;

int speed_L = 135, speed_R = 150; //ความเร็วของมอเตอร์ทั้งสองข้าง กำหนดค่าได้ตั้งแต่ 0-255
int speedTurn_L = speed_L-30, speedTurn_R = speed_R-30;
int speed_L_max = 255, speed_R_max = 255;    //ความเร็วสูงสุด
int value_sensor_L = 0, value_sensor_R = 0;  //ตัวแปลเก็บค่าเซ็นเซอร์ตรวจจับเส้น
int encoderL = 0, encoderR = 0; //ตัวแปลเก็บค่าเซ็นเซอร์นับรอบ
int distance = 850;             //ตั้งค่าระยะทางต่อ1ช่อง ที่นับรอบจากเอ็นโค้ดเดอร์
int distance_turn = 270;        //ตั้งค่าระยะหมุนตัว 90 องศา
int delay_Brake = 100;         //หน่วงเวลาหยุด
int work = 0;                   //ตัวแปรตั้งลำดับการสั่งงานของหุ่นยนต์

void stopL();
void stopR();
void breakLR();
void forward();
void forward_black();
void backward();
void turnL();
void turnR();
void tL();
void tR();

void INT_EN_L() {
  if(digitalRead(7) == HIGH){
    encoderL += 1;
  }else {
    encoderL -= 1;
  }
}

void INT_EN_R() {
  if(digitalRead(4) == HIGH){
    encoderR -= 1;
  }else {
    encoderR += 1;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(sensor_L, INPUT);
  pinMode(sensor_R, INPUT);
  pinMode(switch_start, INPUT);

  attachInterrupt(1, INT_EN_L, RISING);//ประกาศการอินเตอร์รัพท์นับรอบมอเตอร์ซ้าย
  attachInterrupt(0, INT_EN_R, RISING);//ประกาศการอินเตอร์รัพท์นับรอบมอเตอร์ขวา
  while(digitalRead(switch_start) != 0){;}//รอการกดปุ่มเริ่มการทำงาน
  delay(500);
//  forward(); delay(1000); breakLR(); //เอาไว้ทดสอบปรับจูนความเร็วมอเตอร์กับเอ็นโค้ดเดอร์
}

void loop() {
  Serial.print("enL : ");Serial.print(encoderL);Serial.print('\t');
  Serial.print("enR : ");Serial.print(encoderR);Serial.println();

  if(forward_flg == true) {
   
   if(encoderL > encoderR+5) { stopL(); }
   else if(encoderR > encoderL+5) { stopR(); }
   else { forward(); }
   
   if((encoderL >= distance)||(encoderR >= distance)||(digitalRead(sensor_L)==1)||(digitalRead(sensor_R)==1)) {
     backward(); delay(100);
     breakLR();
     delay(delay_Brake);
     encoderL = 0;  encoderR = 0;
     forward_flg = false;
     work += 1;
   }
 }

 if(forward_black_flg == true) {
   
   if(encoderL > encoderR+5) { stopL(); }
   else if(encoderR > encoderL+5) { stopR(); }
   else { forward_black(); }
   
   if((encoderL >= distance)||(encoderR >= distance)) {
     backward(); delay(100);
     breakLR();
     delay(delay_Brake);
     encoderL = 0;  encoderR = 0;
     forward_black_flg = false;
     work += 1;
   }
 }

 if(backward_flg == true) {
   if(encoderL > encoderR-5) { stopL(); }
   else if(encoderR > encoderL-5) { stopR(); }
   else { backward(); }
   
   if((encoderL >= -100)||(encoderR >= -100)) {
//   if((digitalRead(sensor_L)==1)||(digitalRead(sensor_R)==1)) {
     breakLR();
     delay(delay_Brake);
     encoderL = 0;  encoderR = 0;
     backward_flg = false;
     work += 1;
   }
 }

 if(turnleft_flg == true) {
   if(encoderL > encoderR+5) { stopL(); }
   else if(encoderR > encoderL+5) { stopR(); }
   else { turnL(); }
   
   if((encoderL >= distance_turn)||(encoderR >= distance_turn)) {
     brakeL(); delay(100);
     breakLR();
     delay(delay_Brake);
     encoderL = 0;  encoderR = 0;
     turnleft_flg = false;
     work += 1;
//     forward();
   }
 }

 if(turnright_flg == true) {
   if(encoderL > encoderR+5) { stopL(); }
   else if(encoderR > encoderL+5) { stopR(); }
   else { turnR(); }
   
   if((encoderL >= distance_turn)||(encoderR >= distance_turn)) {
     brakeR(); delay(100);
     breakLR();
     delay(delay_Brake);
     encoderL = 0;  encoderR = 0;
     turnright_flg = false;
     work += 1;
//     forward();
   }
 }
///////////////////////การสั่งงานแต่ละบล็อกว่าให้หุ่นยนต์ทำอะไร//////////////////////////
  if(work == 0){
    forward();
  }
  else if(work == 1){
    turnR();
  }
  else if(work == 2){
    forward();
  }
  else if(work == 3){
    turnR();
  }
  else if(work == 4){
    forward();
  }
  else if(work == 5){
    turnL();
  }
  else if(work == 6){
    forward_black();
  }
  else if(work == 7){
    forward();
  }
  else if(work == 8){
    turnL();
  }
  else if(work == 9){
    forward();
  }
  else if(work == 10){
    turnL();
  }
  else if(work == 11){
    forward();
  }
  else if(work == 12){
    turnL();
  }
  else if(work == 13){
    forward_black();
  }
  else if(work == 14){
    turnR();
  }
  else if(work == 15){
    forward_black();
  }
  else if(work == 16){
    turnR();
  }
  else if(work == 17){
    forward();
  }
  else if(work == 18){
    turnL();
  }
  else if(work == 19){
    forward();
  }
  else if(work == 20){
    turnL();
  }
  else if(work == 21){
    forward();
  }
///////////////////////////////////////////////////////////////////////////////
}
