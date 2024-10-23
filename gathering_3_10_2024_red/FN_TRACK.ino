void tn(float speed, float kp, float kd, int Sensor) {  // tracknormal
  error = ReadLine(Sensor) - sentor;
  powermotor = (kp * error) + (kd * (error - lasterror));
  lasterror = error;
  leftmotor = speed + powermotor;
  rightmotor = speed - powermotor;
  if (leftmotor > 100) leftmotor = 100;
  if (leftmotor < -100) leftmotor = -100;
  if (rightmotor > 100) rightmotor = 100;
  if (rightmotor < -100) rightmotor = -100;
  motor(leftmotor, rightmotor);
}
void tlr(float speed, float kp, float kd, int Sensor) {
  if (Sensor == FRONTSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (F[0] < 200 and F[7] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (F[0] > 250 or F[7] > 250) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  } else if (Sensor == BACKSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (B[0] < 200 and B[7] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (B[0] > 250 or B[7] > 250) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  }
}
void t(float speed, float kp, float kd, int Sensor) {
  if (Sensor == FRONTSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (F[0] < 200 and F[7] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (F[0] > 250 and F[7] > 250) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  } else if (Sensor == BACKSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (B[0] < 200 and B[7] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (B[0] > 250 and B[7] > 250) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  }
}

void tr(float speed, float kp, float kd, int Sensor) {
  if (Sensor == FRONTSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (F[6] < 200 and F[7] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (F[6] > 200 and F[7] > 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  } else if (Sensor == BACKSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (B[6] < 200 and B[7] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (B[6] > 200 and B[7] > 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  }
}

void tl(float speed, float kp, float kd, int Sensor) {
  if (Sensor == FRONTSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (F[0] < 200 and F[1] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (F[0] > 200 and F[1] > 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  } else if (Sensor == BACKSENSOR) {
    while (true) {
      ReadLine(Sensor);
      if (B[0] < 200 and B[1] < 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
    while (true) {
      ReadLine(Sensor);
      if (B[0] > 200 and B[1] > 200) {
        break;
      } else {
        tn(speed, kp, kd, Sensor);
      }
    }
  }
}

void rlfollow() {
  Move(-20, -70, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] < 300)  {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] > 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[3] && F[4]  && F[5]< 300) {
      break;
    }
  }
}

void r_lstop() {
  Move(0, -70, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[6] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[6] > 300) {
      break;
    }
  }
  stop(5);
}
void l_rstop() {
  Move(-67, 0, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[1] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[1] > 300) {
      break;
    }
  }
  stop(5);
}

void l() {
  Move(-50, 50, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[0] < 200) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[0] > 200) {
      break;
    }
  }
  stop(5);
}
void lll() {
  Move(-60, 60, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[3] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[3] > 300) {
      break;
    }
  }
  stop(5);
}

void r() {
  Move(60, -60, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] > 300) {
      break;
    }
  }
  stop(5);
}
void ll() {
  Move(-50, 50, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[2] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[2] > 300) {
      break;
    }
  }
}

void rr(){
  Move(50, -50, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[5] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[5] > 300) {
      break;
    }
  }
}
void rrr(){
  Move(50, -50, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[4] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[4] > 300) {
      break;
    }
  }
}

void rdrop() {
  Move(60, -60, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[0] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[0] > 300) {
      break;
    }
  }
}
void rrdrop() {
  Move(50, -50, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[1] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[1] > 300) {
      break;
    }
  }
}
void lldrop() {
  Move(-50, 50, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] > 300) {
      break;
    }
  }
}

void ldrop() {
  Move(-60, 60, 0);
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] < 300) {
      break;
    }
  }
  ReadLine(FRONTSENSOR);
  while (true) {
    ReadLine(FRONTSENSOR);
    if (F[7] > 300) {
      break;
    }
  }
  
}
void tt(float speed, float kp, float kd, long Timer, int Sensor) {
  if (Sensor == BACKSENSOR) {
    speed = speed * -1;
  }
  unsigned long lasttime = millis();
  while (millis() - lasttime <= Timer) {
    tn(speed, kp, kd, Sensor);
  }
}

void tc(int speed, float kp, float kd, int count, int Sensor) {
  if (Sensor == BACKSENSOR) {
    speed = speed * -1;
  }
  for (int i = 0; i < count; i++) {
    t(speed, kp, kd, Sensor);
  }
}

void tcl(int speed, float kp, float kd, int count, int Sensor) {
  if (Sensor == BACKSENSOR) {
    speed = speed * -1;
  }
  for (int i = 0; i < count; i++) {
    tl(speed, kp, kd, Sensor);
  }
}

void tcr(int speed, float kp, float kd, int count, int Sensor) {
  if (Sensor == BACKSENSOR) {
    speed = speed * -1;
  }
  for (int i = 0; i < count; i++) {
    tr(speed, kp, kd, Sensor);
  }
}

void RK() {
  servo(1, closeL);
  servo(2, closeR);
  servo(3, up);
}

void ml(int spl, int spr, int a, int line, int sensor) {
  if (sensor == FRONTSENSOR) {
    Move(spl, spr, 0);
    for (int i = 0; i < line; i++) {
      Move(spl, spr, 100);
      ReadLine(FRONTSENSOR);
      while (F[a] < 200) {
        ReadLine(FRONTSENSOR);
        Move(spl, spr, 0);
      }
    }
  }
  else if (sensor == BACKSENSOR) {
    Move(spl, spr, 0);
    for (int i = 0; i < line; i++) {
      Move(-spl, -spr, 100);
      ReadLine(BACKSENSOR);
      while (B[a] < 250) {
        ReadLine(BACKSENSOR);
        Move(-spl, -spr, 0);
      }
    }
  }
}