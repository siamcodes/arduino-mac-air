#include <MCP3XXX.h>
MCP3008 adc;  

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
#define Ro 986
#define Lo 985
#define RR 984
#define LL 983
#define LLS 982
#define RRS 981


#define openL180 0
#define openR180 180
#define openL 70
#define openR 100
#define openLup 100
#define openRup 75
#define closeL 120
#define closeR 60
#define up 90
#define up70 105
#define down 175
#define medium 145
#define openL0 160  //  200 
#define open180 90
//#define openL0 120
#define openR0 70

#define openLN 85
#define openRN 90

#define numsensor 8
int last_value = 0;
int MaxF[numsensor] = {736,	745,	772,	741,	767,	708,	725,	670	};  //MexF-100
int MinF[numsensor] = { 198,	45,	189,	59,	216,	162,	135,	67	};  //MinF+100
int MaxB[numsensor] = { 772,	772,	754,	735,	632,	836,	828,	781};  //MexB-100
int MinB[numsensor] = {	242,	119,	268,	52,	41,	333,	206,	242,	};  //MinB-100

int Boxtime[10] = { 0, 100, 250, 480, 650, 2000 };
int Boxtime2[10] = { 0, 180, 280, 340, 650, 2000 };   // 140
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

  //view(FRONTSENSOR);  //อ่านค่าเซนเซอร์
 //view(BACKSENSOR);  
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
  BG =0;


// kl(70); 

//cube1();
//  cube2();
//  cube3();
//   cube4();
//  cube5();


//tn(0, 0.01, 0.1, FRONTSENSOR);
//tr(60, 0.003, 0.2,  FRONTSENSOR);
//tn(0, 0.015, 0.15, FRONTSENSOR);



run(1, 1, LR, FRONTSENSOR, L);
//run(1, 1, R, FRONTSENSOR, R);
 servo(1, openL);
  servo(2, openR);
  stop(100);
     servo(3, down);
    stop(300);
tr(60, 0.013, 0.2,  FRONTSENSOR);
 servo(1, closeL);
   servo(2, closeR);
   stop(100);
r();
 
                
 
    run(1, 1, L, FRONTSENSOR,N);
     drop(LS,210);

tr(60, 0.013, 0.2,  FRONTSENSOR);
     r();
 servo(1, openL);
  servo(2, openR);
  stop(100);
     servo(3, down);
    stop(300);
tr(60, 0.013, 0.2,  FRONTSENSOR);
 servo(1, closeL);
   servo(2, closeR);
   stop(100);
r();
tr(60, 0.013, 0.2,  FRONTSENSOR);
servo(3, up70);
tl(40, 0.01, 0.2,  FRONTSENSOR);
servo(1, openLup);
  servo(2, openRup);
  stop(300);
  run(2, 1, L, BACKSENSOR,R);
run(1, 2, LR, FRONTSENSOR, N);
//   //   drop(L,200); 
//   //Move(90,100,1000);
motor(0,0);

}

void loop() {
  //Serial.println(digitalRead(8));
  //tn(0, 0.015, 0.15, FRONTSENSOR);

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
      adc.begin( A3, A2, A1 ,A0); //cs,mo,mi,clk
      adc.begin(8, A2, A1 ,A0);
    } else if (Sensor == BACKSENSOR) {
     adc.begin( 8, A2, A1 ,A0); //cs,mo,mi,clk
      adc.begin(A3, A2, A1 ,A0);
    }
    for (int i = 0; i < 8; i++) {
      Serial.print(adc.analogRead(i));
      Serial.print(",\t");
    }
    Serial.println("");
  }
}
void Read(int Sensor) {
  int x = 0;
  if (Sensor == FRONTSENSOR) {
     adc.begin( A3, A2, A1 ,A0); //cs,mo,mi,clk
      adc.begin(8, A2, A1 ,A0);
    for (int i = 0; i < numsensor; i++) {
      x = map(adc.analogRead(i), MinF[i], MaxF[i], 0, 800);
      if (x >= 800) x = 800;
      if (x <= 0) x = 0;
      F[i] = x;
    }
  } else if (Sensor == BACKSENSOR) {
    adc.begin( 8, A2, A1 ,A0); //cs,mo,mi,clk
    adc.begin(A3, A2, A1 ,A0);
    for (int i = 0; i < numsensor; i++) {
      x = map(adc.analogRead(i), MinB[i], MaxB[i], 0, 800);
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


void kt(int ttimer) {
  stop(50);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  // servo(1, closeL);
  // servo(2, closeR);
  tt(40, 0.018, 0.18, ttimer, FRONTSENSOR);          //606
  
  // stop(80);
  servo(1, closeL);
  servo(2, closeR);
  stop(150);
}
void kr(int timer){
  tt(40, 0.018, 0.18, 130, FRONTSENSOR);
  r_lstop();            //  T
  servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
  stop(200);
  tt(50, 0.018, 0.18, timer, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  stop(100);
  Move(-40, -40, timer);
  //l();
}
void kl(int timer){
  tt(40, 0.018, 0.18, 120, FRONTSENSOR);  // 160
  l_rstop();            //  T
  servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
  stop(200);   
  tt(40, 0.018, 0.18, timer, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  stop(100);
  Move(-40, -40, timer);
  //l();
}
void shoot_rbig(int timer_F , int timer_in) {
  servo(3, up);  
  stop(100);

  //     ml(60, 62, 7, 1, FRONTSENSOR);
  //     tr(50, 0.015, 0.15, FRONTSENSOR);
  //     tl(50, 0.015, 0.15, FRONTSENSOR);
  //     tlr(50, 0.01, 0.1, FRONTSENSOR);
  //     tt(50, 0.016, 0.18, 30, FRONTSENSOR);
  //     tt(40, 0.018, 0.18, 000, FRONTSENSOR);      
                
  //  servo(1, closeL);
  //  servo(2, closeR);
  //  stop(100);
  
  
  
  
  //tt(40, 0.018, 0.18, 250, FRONTSENSOR);  //  160
  tl(-30, 0.018, 0.18,BACKSENSOR);
  //Move(50,50,100);
  //rlfollow();    
  // servo(3, down);
  // stop(150);
  r_lstop();
  tt(40, 0.025, 0.22, timer_in, FRONTSENSOR);
  Move(-60,-60,180);
  servo(1, openL180);
  servo(2, openR180);
  stop(50);
  Move(100,100,180);
  Move(-60,-62,180);
  stop(100);
  servo(3, up);
  stop(100);
  servo(1, closeL);
  servo(2, closeR);    
}
void shoot_r(int timer) {
  tt(40, 0.018, 0.18, 180, FRONTSENSOR);  //  160
  r_lstop();    
  servo(3, down);
  stop(150);
  tt(40, 0.025, 0.22, timer, FRONTSENSOR);
  Move(-60,-62,timer);
  //Move(-60,-60,200);
  servo(1, openL180);
  servo(2, openR180);
  stop(50);
  Move(100,100,180);
  Move(-60,-60,180);
  stop(100);
  servo(3, up);
  stop(100);
  servo(1, closeL);
  servo(2, closeR);    

}
void shoot_l(int timer) {
  tt(40, 0.018, 0.18, 160, FRONTSENSOR);
  l_rstop();    
  servo(3, down);
  stop(150);
  tt(40, 0.025, 0.22, timer, FRONTSENSOR);
  Move(-60,-62,timer);
  //Move(-60,-60,200);
  servo(1, openL180);
  servo(2, openR180);
  stop(50);
  Move(100,100,180);
  Move(-60,-60,180);
  stop(100);
  servo(3, up);
  stop(100);
  servo(1, closeL);
  servo(2, closeR);
}
void shoot_t(int timer) {
  stop(50);   
  servo(3, down);
  tt(40, 0.023, 0.22, 150, FRONTSENSOR);
  tt(60, 0.023, 0.22, 300, BACKSENSOR);
  //Move(-60,-62,260);
  
  servo(1, openL180);
  servo(2, openR180);
  stop(50);
  Move(100,100,210);
  //Move(-60,-60,180);
  tt(60, 0.025, 0.22, 180, BACKSENSOR);
  stop(100);
  servo(3, up);
  stop(100);
  servo(1, closeL);
  servo(2, closeR);

}
void drop(int a, int b) {
  if (a == L) {
    stop(50);
    servo(3, down);
    // Move(-50, 50, 80);
    ldrop();
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    rr();
    //Move(50, -50, 80);
  } else if (a == LL) {
    stop(50);
    servo(3, down);
    // Move(-50, 50, 80);
    lldrop();
    Move(-50, 50, 50);
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    rr();
    // Move(50, -50, 80);
  } else if (a == R) {
    stop(50);
    servo(3, down);
    // Move(50, -50, 80);
    rdrop();
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    ll();
    //Move(-50, 50, 120);
  } else if (a == RR) {
    stop(50);
    servo(3, down);
    rrdrop();
    Move(50, -50, 50);
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    ll();
    //Move(-50, 50, 120);
  } else if (a == LS) {
    stop(50);
    servo(3, down);
    lldrop();
    Move(50, 50, b);
    stop(50);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-50, -50, b);
    rr();
  } else if (a == LLS) {
    stop(50);
    servo(3, down);
    lldrop();
    Move(60, 60, b);
    stop(100);
    servo(3, up);
    stop(50);
    Move(-60, -60, b);
    rr();
  } else if (a == RS) {
    stop(50);
    servo(3, down);
  rdrop();
    Move(50, 50, b);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-50, -50, b);
  ll();
  } 
  else if (a == RRS) {
    stop(50);
    servo(3, down);
    // Move(50, -50, 80);
  rrdrop();
    Move(60, 60, b);
    stop(100);
    //servo(1, openL);
    //servo(2, openR);
    //stop(50);
    servo(3, up);
    stop(50);
    Move(-60, -60, b);
  ll();
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
  } else if (a == Ro) {
    servo(3, down);
    stop(100);
    Move(50, -50, 80);
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
    stop(50);
    servo(3, up);
    stop(50);
    Move(-30, -30, b);
    Move(-50, 50, 80);
  } else if (a == Lo) {
    servo(3, down);
    stop(100);
    Move(-50, 50, 80);
    Move(30, 30, b);
    stop(50);
    servo(1, openL);
    servo(2, openR);
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
  tt(50, 0.01, 0.1, timer, FRONTSENSOR);
  stop(150);
  servo(1, closeL);
  servo(2, closeR);
  stop(150);
  servo(3, up);
  stop(150);
}