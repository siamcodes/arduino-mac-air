int A[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int PWMA = 11;
int MA1 = 9;
int MA2 = 10;
int PWMB = 3;
int MB1 = 6;
int MB2 = 5;
int STBY = 8;
int Speed, SlowSpeed, ACCSpeed;


void setup() {
  Speed = 250;
  Serial.begin(9600);
  pinMode(PWMA, OUTPUT);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(STBY, OUTPUT);
  Forward(Speed, 1000);
  MotorStop();
}

void loop() {
  ShowADC();
  
  //  Forward();
  //  delay(2000);
  //  MotorStop();
  //  delay(1000);
  //  backward();
  //  delay(2000);
  //  MotorStop();
  //  delay(1000);
}
