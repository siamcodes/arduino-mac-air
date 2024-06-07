void stopL() {
  analogWrite(IN3, speed_L_max);
  analogWrite(IN4, speed_L_max);
}

void stopR() {
  analogWrite(IN1, speed_R);
  analogWrite(IN2, speed_R);
}

void breakLR() {
  analogWrite(IN3, speed_L_max);  analogWrite(IN1, speed_R_max);
  analogWrite(IN4, speed_L_max);  analogWrite(IN2, speed_R_max); 
//  delay(300); 
//  work += 1;
}

void forward() {
  analogWrite(IN3, speed_L);      analogWrite(IN1, speed_R);
  analogWrite(IN4, 0);            analogWrite(IN2, 0);  
  forward_flg = true;
}

void forward_black() {
  analogWrite(IN3, speed_L-20);      analogWrite(IN1, speed_R-20);
  analogWrite(IN4, 0);            analogWrite(IN2, 0);  
  forward_black_flg = true;
}

void backward() {
  analogWrite(IN3, 0);            analogWrite(IN1, 0);
  analogWrite(IN4, speed_L);      analogWrite(IN2, speed_R);
//  backward_flg = true;
}

void turnL() {
  analogWrite(IN3, 0);            analogWrite(IN1, speedTurn_R);
  analogWrite(IN4, speedTurn_L);      analogWrite(IN2, 0);
  turnleft_flg = true;
}

void turnR() {
  analogWrite(IN3, speedTurn_L);      analogWrite(IN1, 0);
  analogWrite(IN4, 0);            analogWrite(IN2, speedTurn_R);
  turnright_flg = true;
}

void brakeL() {
  analogWrite(IN3, speedTurn_L);      analogWrite(IN1, 0);
  analogWrite(IN4, 0);            analogWrite(IN2, speedTurn_R);
//  turnleft_flg = true;
}

void brakeR() {
  analogWrite(IN3, 0);            analogWrite(IN1, speedTurn_R);
  analogWrite(IN4, speedTurn_L);      analogWrite(IN2, 0);
//  turnleft_flg = true;
}

void tL() {
  analogWrite(IN3, speed_L_max);  analogWrite(IN1, speedTurn_R);
  analogWrite(IN4, speed_L_max);  analogWrite(IN2, 0);
  delay(50);
  analogWrite(IN3, speedTurn_L);      analogWrite(IN1, speedTurn_R);
  analogWrite(IN4, 0);            analogWrite(IN2, 0); 
}

void tR() {
  analogWrite(IN3, speedTurn_L);      analogWrite(IN1, speed_R_max);
  analogWrite(IN4, 0);            analogWrite(IN2, speed_R_max);
  delay(50);
  analogWrite(IN3, speedTurn_L);      analogWrite(IN1, speedTurn_R);
  analogWrite(IN4, 0);            analogWrite(IN2, 0); 
}
