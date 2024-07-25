void ReadSensor() {  //ค่าดิบ
  for (int _sensor = 0; _sensor < NUM_SENSORS; _sensor++) {
    //adc.begin(sck, mosi, miso, ssf);
    //adc.begin(25, 26, 27, 24);
    F[_sensor] = (F_PIN[_sensor]);
  }
}

void readCalibrate() { //ค่าที่ Calibrate แล้ว
  ReadSensor();
  for (int i = 0; i < NUM_SENSORS; i++) {
    unsigned int calmin, calmax;
    long x = 0;
    calmin = MinValueF[i];
    calmax = MaxValueF[i];
    x = map(F[i], calmin, calmax, 1000, 0);   //ถ้าไม่เกาะเส้นให้แก้ 0, 1000 หรือ 1000, 0
    if (x < 0) x = 0;
    if (x > 1000) x = 1000;
    F[i] = x;
  }
}

void CalibrateSensor(int pauseTime, int samples) {
  for (int i = 0; i < NUM_SENSORS; i++) {
    MinValueF[i] = 1023;
    MaxValueF[i] = 0;
  }
  for (int startSamp = 0; startSamp <= samples; startSamp++) {
    ReadSensor();
    for (int i = 0; i < NUM_SENSORS; i++) {
      MinValueF[i] = (F[i] <= MinValueF[i] ? F[i] : MinValueF[i]);
      MaxValueF[i] = (F[i] >= MaxValueF[i] ? F[i] : MaxValueF[i]);
    }
    delay(pauseTime);
  }
}

void ShowCalibrate() { // Calibrate ค่าแสง
  Serial.println("Press OK to Start Calibrate Sensor");
  
  Serial.println("Calibrating...");

  CalibrateSensor(20, 250);
  //beep();
  Serial.println("Finish");
  Serial.println("  ");

  Serial.print("int MinValue[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MinValueF[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");
    REFmin[i] = MinValueF[i];
  }

  Serial.print("int MaxValue[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(MaxValueF[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");
    REFmax[i] = MaxValueF[i];
  }
  Serial.print("int REF[NUM_SENSORS] = {");
  for (int i = 0; i < NUM_SENSORS; i++) {
    REF[i] = (REFmin[i] + REFmax[i]) / 2;
    Serial.print(REF[i]);
    if (i < NUM_SENSORS - 1) Serial.print(",");
    else Serial.println("};");

  }
  while (1);
}

void AutoRef() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    REF[i] = (MinValueF[i] + MaxValueF[i]) / 2;
  }
}

void SerialCalibrate() {
  while (1) {
    readCalibrate();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);
  }
}

void SerialF() {
  while (1) {
    ReadSensor();
    for (int _serialF = 0; _serialF < NUM_SENSORS; _serialF++) {
      Serial.print(F[_serialF]);
      Serial.print("\t");
    }
    Serial.println("");
    delay(50);

  }
}

void SerialPosition() {
  while (1) {
    int Pos = readPosition(250, 50);
    int Error_F = Pos - 3500;
    Serial.print("Pos = ");
    Serial.println(Pos);
    Serial.print("                  Error = ");
    Serial.println(Error_F);
  }
}