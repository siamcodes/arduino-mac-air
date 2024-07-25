#include <Adafruit_MCP3008.h>
Adafruit_MCP3008 adc;  

#include <Servo.h>
Servo myservo[3];
#define dir1A 2  
#define dir2A 3  
#define pwmA 5   
#define dir1B 4  
#define dir2B 7  
#define pwmB 6   
#define FRONTSENSOR 999
#define BACKSENSOR 998
#define L 997
#define R 996
#define N 995
#define LR 994
#define LS 993
#define RS 992
#define LP 991
#define RP 990
#define S 989
#define SS 988
#define PS 987
#define Rs 986
#define Ls 985

#define openL180 0
#define openR180 180
#define openL 70
#define openR 100
#define closeL 105
#define closeR 70
#define up 90
#define down 5
#define medium 35
#define openL0 200
#define open180 90
#define openL0 120
#define openR0 70

#define numsensor 8
int last_value = 0;
int MaxF[numsensor] = {870,	874,	790,	799,	800,	748,	864,	586};  //MexF-100
int MinF[numsensor] = { 310,	320,	248,	232,	255,	242,	295,	217};  //MinF+100
int MaxB[numsensor] = { 787,	836,	689,	655,	825,	588,	698,	623};  //MexB-100
int MinB[numsensor] = {212,	195,	140,	142,	209,	136,	167,	151 };  //MinB-100

int Boxtime[10] = { 0, 140, 300, 480, 650, 2000 };
unsigned long F[numsensor];
unsigned long B[numsensor];
float leftmotor, rightmotor, powermotor, error, lasterror;
int BG = 0;
int sentor = 0;
void setup() {
  Serial.begin(9600);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(pwmB, OUTPUT);

   //view(BACKSENSOR);  //อ่านค่าเซนเซอร์
  // viewRead();
  //  viewReadLine(FRONTSENSOR);
  // ReadLine(FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  servo(3, up);
  sentor = 3350;
  while (analogRead(A6) > 500)
    ;
  delay(200);
  BG=0;
  
cube1();
 cube2();
cube3();
cube4();
//cube5();
//cube6();

// tlr(40, 0.01, 0.1, FRONTSENSOR);
//tt(40, 0.016, 0.18, 30, FRONTSENSOR);
motor(0,0);

}

void loop() {
  Serial.println(digitalRead(8));
}
void stop(int Timer) {
  Move(0, 0, Timer);
}
void Move(int spl, int spr, int Timer) {
  motor(spl, spr);
  delay(Timer);
}
void motor(int motorl, int motorr) {
  motorl = (motorl * 255) / 100;
  motorr = (motorr * 255) / 100;
  if (motorl == 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, 0);
  } else if (motorl > 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, motorl);
  } else if (motorl < 0) {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, -motorl);
  }
  if (motorr == 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, 0);
  } else if (motorr > 0) {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, motorr);
  } else if (motorr < 0) {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, -motorr);
  }
}

void view(int Sensor) {
  while (true) {
    if (Sensor == FRONTSENSOR) {
      adc.begin(A0, A2, A1, 8);
      adc.begin(A0, A2, A1, A3);
    } else if (Sensor == BACKSENSOR) {
      adc.begin(A0, A2, A1, A3);
      adc.begin(A0, A2, A1, 8);
    }
    for (int i = 0; i < 8; i++) {
      Serial.print(adc.readADC(i));
      Serial.print(",\t");
    }
    Serial.println("");
  }
}
void Read(int Sensor) {
  int x = 0;
  if (Sensor == FRONTSENSOR) {
    adc.begin(A0, A2, A1, 8);
    adc.begin(A0, A2, A1, A3);
    for (int i = 0; i < numsensor; i++) {
      x = map(adc.readADC(i), MinF[i], MaxF[i], 800, 0);
      if (x >= 800) x = 800;
      if (x <= 0) x = 0;
      F[i] = x;
    }
  } else if (Sensor == BACKSENSOR) {
    adc.begin(A0, A2, A1, A3);
    adc.begin(A0, A2, A1, 8);
    for (int i = 0; i < numsensor; i++) {
      x = map(adc.readADC(i), MinB[i], MaxB[i], 800, 0);
      if (x >= 800) x = 800;
      if (x <= 0) x = 0;
      B[i] = x;
    }
  }
}
void viewRead(int Sensor) {
  while (true) {
    Read(Sensor);
    for (int i = 0; i < 8; i++) {
      Serial.print(F[i]);
      Serial.print(",\t");
    }
    Serial.println("");
  }
}

int ReadLine(int Sensor) {
  unsigned long avg = 0;
  unsigned long sum = 0;
  int on_line = 0;
  Read(Sensor);
  if (Sensor == FRONTSENSOR) {
    for (int i = 0; i < numsensor; i++) {
      if (BG == 1) F[i] = 800 - F[i];
      if (F[i] > 200) on_line = 1;
      if (F[i] > 50) {
        avg = avg + (F[i] * (i * 1000));
        sum = sum + F[i];
      }
    }
    if (on_line == 0) {
      if (last_value > 3500) return 7000;
      else return 0;
    } else {
      last_value = avg / sum;
    }
    return last_value;
  } else if (Sensor == BACKSENSOR) {
    for (int i = 0; i < numsensor; i++) {
      if (B[i] > 200) on_line = 1;
      if (B[i] > 50) {
        avg = avg + (B[i] * (i * 1000));
        sum = sum + B[i];
      }
    }
    if (on_line == 0) {
      if (last_value > 3500) return 7000;
      else return 0;
    } else {
      last_value = avg / sum;
    }
    return last_value;
  }
}
void viewReadLine(int Sensor) {
  while (true) {
    if (Sensor == FRONTSENSOR) {
      for (int i = 0; i < 8; i++) {
        Serial.print(F[i]);
        Serial.print(",\t");
      }
      Serial.println(ReadLine(FRONTSENSOR));
    } else if (Sensor == BACKSENSOR) {
      for (int i = 0; i < 8; i++) {
        Serial.print(B[i]);
        Serial.print(",\t");
      }
      Serial.println(ReadLine(BACKSENSOR));
    }
  }
}

void k(int timer) {
  stop(timer);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  tt(30, 0.01, 0.1, 100, FRONTSENSOR);
  tlr(60, 0.01, 0.1, FRONTSENSOR);
  // stop(200);
  Move(30, 30, 0);
  servo(1, closeL);
  servo(2, closeR);
  stop(150);
}

void k2(int timer) {
  stop(timer);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  tt(30, 0.01, 0.1, 100, FRONTSENSOR);
  t(30, 0.01, 0.1, FRONTSENSOR);
  // stop(200);
  Move(30, 30, 0);
  servo(1, closeL);
  servo(2, closeR);
  stop(150);
}


void kt(int timer, int ttimer) {
  stop(timer);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  // servo(1, closeL);
  // servo(2, closeR);
  tt(30, 0.01, 0.1, ttimer, FRONTSENSOR);
  // stop(80);
  servo(1, closeL);
  servo(2, closeR);
  stop(150);
}

void drop(int a, int b) {
  if (a == L) {
    stop(50);
    servo(3, down);
    Move(-55, 50, 80);
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    Move(50, -50, 80);
  } else if (a == R) {
    stop(50);
    servo(3, down);
    Move(50, -50, 120);
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    Move(-50, 50, 120);
  } else if (a == LS) {
    Move(-50, 50, 120);
    servo(3, down);
    Move(30, 30, b);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    rr();
    //Move(50, -50, 70);
  } else if (a == RS) {
    Move(50, -50, 120);
    servo(3, down);
    Move(30, 30, b);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    ll();
    //Move(-50, 50, 90);

  } else if (a == LP) {
    stop(50);
    servo(3, down);
  
    Move(-50, 50, 120);
    stop(50);
    Move(-20, -20, 150);
    servo(1, openL180);
    stop(50);
    //Move(16, -16, 350);
    rr();
    Move(20, 20, b);
    stop(50);
    Move(-20, -20, b);
    stop(50);
    servo(3, up);
    stop(100);
    servo(1, closeL);
    servo(2, closeR);

  } else if (a == RP) {                                  
    stop(50);
    servo(3, down);
    Move(50, -50, 120);
    stop(50);
    Move(-20, -20, 150);
    servo(2, openR180);
    stop(50);
    ll();
    // Move(-20, 20, 300);
    
    Move(20, 20, b);
    stop(50);
    Move(-20, -20, b);
    stop(50);
    servo(3, up);
    stop(100);
    servo(1, closeL);
    servo(2, closeR);
  } else if (a == S) {
    servo(3, down);
    Move(30, 30, b);
    stop(100);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
  } else if (a == SS) {
    Move(30, 30, b);
    servo(3, down);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
  } else if (a == B) {
    Move(30, 30, b);
    servo(3, down);
    stop(50);
    servo(3, medium);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    Move(-30, -30, b);
  } else if (a == PS) {
    servo(3, down);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    Move(20, 20, b);
    stop(50);
    Move(-20, -20, b);
    stop(50);
    servo(3, up);
    stop(100);
    servo(1, closeL);
    servo(2, closeR);
  } else if (a == Rs) {
    servo(3, down);
    stop(100);
    Move(50, -50, 60);
    Move(30, 30, b);
    stop(50);
    servo(1, openL0);
    servo(2, openR0);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    Move(-50, 50, 80);
  } else if (a == Ls) {
    servo(3, down);
    stop(100);
    Move(-50, 50, 100);
    Move(30, 30, b);
    stop(50);
    servo(1, openL0);
    servo(2, openR0);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    Move(50, -50, 80);
  }
}

void ku(int timestop, int timer) {
  stop(timer);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  tt(30, 0.01, 0.1, timer, FRONTSENSOR);
  stop(150);
  servo(1, closeL);
  servo(2, closeR);
  stop(150);
  servo(3, up);
  stop(150);
}