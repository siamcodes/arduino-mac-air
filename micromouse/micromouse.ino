#include <AFMotor.h>
float dir = 0.0, error = 0.0, no_wall = 40;
int sl = 0, sr = 0, spd_l = 200, spd_r = 250, sl_c = 0, sr_c = 0;
enum Wallcolor {white, red, green, blue, orange};
enum direct {forw, left, right, retn, right2, left2};
enum command {fow, lef, rgt, rtn, none, rtn2};
enum ck_sen {clr, ct_sen, sd_data, ct_rtn, ct_fw};
int en1 = 21, en2 = 20; //180//180
int n = 0, clr_n = 0, start2 = 0;
char p1 = ' ', p = ' ';
char test[128];
int n_reval = 0, kk = 0;
unsigned de = 0;
unsigned int ti, ti_pre = 0;
int mode1 = 0, mode = 0, mode2 = 0 , mode3 = 0 , n_sf = 0;
char p3;
String data;
String sm[3];
int sen[3], sd[3];
int nn = 0;
int Scut = 0;
ck_sen ck_sn;
direct dirt;
command cmd;
AF_DCMotor m1(1);
AF_DCMotor m2(2);

void setup() {
  pinMode(en1, INPUT);
  pinMode(en2, INPUT);
  pinMode(32, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(en1), en_l, RISING );
  attachInterrupt(digitalPinToInterrupt(en2), en_r, RISING );

  Serial.begin(9600);
  Serial1.begin(9600); // For uno
  Serial2.begin(9600); //For Bluetooth

  m1.setSpeed(199);
  m2.setSpeed(245);
  mode = 0; clr_en();
  m_stp();
  delay(2000); p1 = ' '; p = ' '; cmd = none; ck_sn = clr;
  digitalWrite(32, HIGH);
  delay(20);
  digitalWrite(32, LOW); //m_for();
  // Serial2.println("R");

}

void loop()
{
  //Serial.println(test);

  if (sen[0] <= 13 )
  {
    if ((sen[0] > 0 && sen[0] < 8) && (sen[2] < 38 && sen[2] > 16))
    {
      dirt = right;
    }
    else if ((sen[0] > 0 && sen[0] <= 13) && sen[2] > 38)
    {
      dirt = forw;
    }
    else if ((sen[0] > 0 && sen[0] < 8) && sen[2] < 16 && sen[2] > 9)
    {
      dirt = right2;
    }
    else
    {
      dirt = forw;
    }
  }
  else if (sen[0] > 16)
  {
    if ((sen[2] > 0 && sen[2] < 8 ) && (sen[0] < 38 && sen[0] > 16))
    {

      dirt = left;
    }
    else if ((sen[2] > 0 && sen[2] < 8 ) && sen[0] > 38)
    {
      dirt = forw;
    }
    else if ((sen[2] > 0 && sen[2] < 8 ) && sen[0] < 16 && sen[0] > 9)
    {
      dirt = left2;
    }
    else
    {
      dirt = forw;
    }
  }
  ////////////////////////////

  if (ck_sn == ct_sen)
  { if (sd[0] == 1 && sd[1] == 1 && sd[2] == 1)
    {
      digitalWrite(32, HIGH);
      delay(50);
      digitalWrite(32, LOW);
    }
    else
    {
      digitalWrite(32, LOW); delay(50);
    }/*
    Serial.print(sd[0]); Serial.print(","); Serial.print(sd[1]); Serial.print(","); Serial.print(sd[2]);
    Serial.print(","); Serial.println(white);*/
    de++;
    if (de > 28)
    {
      de = 0;
      ck_sn = sd_data;
    }
  }
  else if (ck_sn == sd_data)
  { de++; delay(50);

    if (de > 15)
    { de = 0;
      clr_en();
      if (sen[1] < 14)
      {
        ck_sn = ct_rtn; de = 0;
      }
      else if (sen[1] < 37 && sen[1] > 20)
      {
        ck_sn = ct_fw; de = 0;
      }
      else
      {
        Serial2.print(sd[0]); Serial2.print(","); Serial2.print(sd[1]); Serial2.print(","); Serial2.print(sd[2]);
        Serial2.print(","); Serial2.println(white);
        digitalWrite(32, HIGH);
        delay(50);
        digitalWrite(32, LOW);
        clr_en(); ck_sn = clr;
        de = 0;

      }
    }
  }
  else if (ck_sn == ct_rtn)
  { // Serial2.println(sen[1]);
    m_re(); de = 0;
    if (sl > 12 && sr > 12)
    { Serial.print("yyy  "); Serial.println(ck_sn);
      de = 0;

      m_stp();
      delay(800);
      clr_en(); ck_sn = ct_sen;
    }

  }
  else if (ck_sn == ct_fw)
  {
    m_for();
    de = 0;
    if (sl > 12 && sr > 12)
    { Serial.print("yyy  "); Serial.println(ck_sn);
      de = 0;

      m_stp();
      delay(800);
      clr_en(); ck_sn = ct_sen;
    }
  }


  if (p1 == '0' || cmd == fow )//
  { m_for();  ck_spd(); de++;
    /*  sprintf(test, " S1 =%d  S2=%d   spd_l %d   spd_r %d  %s|", sen[0], sen[2], spd_l, spd_r, dirt);
      Serial2.println(test);*/
    // Serial2.print(test); Serial2.print(" error" ); Serial2.print(error); Serial2.print(" dir "); Serial2.println(dir);

    if (sl > 116 && sr > 116 )
    {
      m_stp();


      clr_en(); p1 = ' '; de = 0;
      cmd = none;
      ck_sn = ct_sen;
    }
    ck_local();
  }
  else if (p1 == '2' || cmd == rgt) //2
  { m_rr();
    if (sl >= 73)
    {
      n = 1;
      m_stp();

      delay(800);
      //   Serial2.println(sl);
      //delay(1200);
      if (sl > 80 && sl <= 100)
      {
        mode2 = 1;
        n_sf = sl - 80;
      }
      else if ( sl <= 75 && sl > 63)
      {
        n_sf = 78 - sl;
        mode2 = 2;
      }
      else
      { mode2 = 0; clr_en();
        m_stp();
        delay(800);
      }

      clr_en();

      if (mode2 != 0)
      {
        while (1)
        {
          if (mode2 == 1)
          {
            m_rr_re();
            if (sl >= n_sf)
            {
              m_stp();
              delay(800);
              break;
            }
          }
          else if (mode2 == 2)
          {
            m_rr();
            if (sl >= n_sf)
            {
              m_stp();
              delay(800);
              break;
            }

          }
        }
        p1 = ' ';
        mode2 = 0;
      }

      if (mode2 == 0)
      {
        cmd = none; p1 = ' '; Serial2.println("R"); Serial.println("R"); digitalWrite(32, HIGH);
        delay(50);
        digitalWrite(32, LOW);
        clr_en();

        ck_local();

      }
    }

  }
  else if (p1 == '1' || cmd == lef)
  {
    m_ll();
    if (sr >= 70)
    {
      n = 1;
      m_stp();

      delay(800);
      // Serial2.println(sr);
      if (sr > 82 && sr <= 100)
      {
        mode3 = 1;
        n_sf = sr - 82;
      }
      else if ( sr >= 64 && sr < 70)
      {
        n_sf = 70 - sr;
        mode3 = 2;
      }
      else
      {
        mode3 = 0; clr_en();
        m_stp();
        delay(800);
      }

      clr_en();


      if (mode3 != 0)
      {
        while (1)
        {
          if (mode3 == 1)
          {
            m_ll_re();
            if (sr >= n_sf)
            {
              m_stp();
              delay(800);
              break;
            }
          }
          else if (mode3 == 2)
          {
            m_ll();
            if (sr >= n_sf)
            {
              m_stp();
              delay(800);
              break;
            }

          }
        }
        mode3 = 0; clr_en(); p1 = ' ';
      }
      if (mode3 == 0)
      {
        cmd = none; Serial2.println("R"); Serial.println("R"); digitalWrite(32, HIGH);
        delay(50);
        digitalWrite(32, LOW);
        clr_en(); p1 = ' '; //spd_l = 165; spd_r = 230;
        n_reval = 1;
        ck_local();
      }
    }
  }
  else if (p1 == '3' || cmd == rtn)
  {
    m_r();// return
    if (sl > 68)
    {
      m1.setSpeed(0);
    }
    if (sr > 72)
    {
      m2.setSpeed(0);
    }
    if (sl > 70 && sr > 71)
    {
      m_stp();
      delay(800);


      if (sr > 90)
      { n_sf = sr - 84; clr_en();
        m_ll();
        while (sr < n_sf)
        {
          m_ll();
        } m_stp(); delay(500);
      }
      // Serial2.print(sl); Serial.print(" "); Serial2.println(sr);
      Serial2.println("R"); Serial.println("R"); digitalWrite(32, HIGH);
      delay(50);
      digitalWrite(32, LOW);
      cmd = none; clr_en(); p1 = ' ';
      //  spd_l = 214; spd_r = 230;
      n_reval = 1; ck_local();
    }
  }
  else if ( cmd == rtn2)
  {
    m_l();// return
    if (sl > 68)
    {
      m1.setSpeed(0);
    }
    if (sr > 72)
    {
      m2.setSpeed(0);
    }
    if (sl > 66 && sr > 69)
    {
      m_stp();
      delay(800);


      if (sl > 90)
      { n_sf = sl - 84;
        clr_en();
        while (sl < n_sf)
        { //Serial2.println("ee");
          m_rr();
        } m_stp(); delay(500);
      }
      // Serial2.print(sl); Serial.print(" "); Serial2.println(sr);
      Serial2.println("R"); Serial.println("R"); digitalWrite(32, HIGH);
      delay(50);
      digitalWrite(32, LOW);
      cmd = none; clr_en(); p1 = ' ';
      spd_l = 220; spd_r = 230; n_reval = 1;
    }
  }
  else if (p1 == '5' )
  {
    m_re(); Serial.println(sen[1]);
    if (sl > 15 && sr > 15)
    {
      m_stp();
      delay(800);
      clr_en(); p1 = ' ';
    }
  }




}

void m_for()
{
  m1.run(FORWARD);
  m2.run(FORWARD);
}
void m_re()
{ m1.setSpeed(199);
  m2.setSpeed(245);
  m1.run(BACKWARD);
  m2.run(BACKWARD);
}
void m_rr()
{
  m1.setSpeed(199);
  m2.setSpeed(245);
  m1.run(FORWARD);
  m2.run(RELEASE);

}
void m_rr_re()
{

  m1.run(BACKWARD);
  m2.run(RELEASE);

}
void m_r()
{
  m1.setSpeed(240);
  m2.setSpeed(255);
  m1.run(FORWARD);
  m2.run(BACKWARD);

}
void m_l()
{
  m1.setSpeed(230);
  m2.setSpeed(255);
  m2.run(FORWARD);
  m1.run(BACKWARD);

}
void m_ll()
{
  m1.setSpeed(199);
  m2.setSpeed(245);
  m2.run(FORWARD);
  m1.run(RELEASE);

}
void m_ll_re()
{

  m2.run(BACKWARD);
  m1.run(RELEASE);

}
void m_stp()
{
  m1.run(RELEASE);
  m2.run(RELEASE);
}
void en_l()
{
  sl++; sl_c++;
}
void en_r()
{ sr++; sr_c++;
}
void clr_en()
{
  sl = 0; sr = 0;
}
void clr_en_spd()
{
  sl_c = 0; sr_c = 0;
}
void ck_local()
{

  if (sen[0] > 0 && sen[0] < 8)
  {
    spd_l = 230; spd_r = 200;
  }
  else if (sen[2] > 0 && sen[2] < 8)
  {
    spd_l = 175; spd_r = 255;
  }
  else
  {
    spd_l = 193; spd_r = 245;
  }
}
void ck_spd()
{
  ti = millis() - ti_pre;
  if (ti >= 100)
  { ti_pre = millis();
    if (dirt == forw)
    { /*
        spd_l = 199;
        spd_r = 245;*/
      //  Serial.print("fowww  ");
      //Serial.println(test);
      //spd_r = 245;
      if (n_reval == 0)
      { spd_r = 245;
        spd_l = 194;
      }
      else if (n_reval >= 3)
      {
        n_reval = 0;
      }
      else
      {
        n_reval++;
      }
      if (sl_c > 12)
      {
        spd_l -= 4;
      }
      else if (sl_c < 10)
      {
        spd_l += 4;
      }
      limit_spd();
    }
    else if (dirt == right)
    { //Serial.print("rigt  ");
      n_reval = 0;
      spd_l += 6;
      spd_r = 210;
      limit_spd();
    }
    else if (dirt == right2)
    {
      n_reval = 0;
      spd_l += 3;
      spd_r = 228;
      limit_spd();
    }
    else if (dirt == left)
    { //Serial.print("left  ");
      n_reval = 0;
      spd_l = 170;
      spd_r += 6;
      limit_spd();
    }
    else if (dirt == left2)
    { //Serial.print("left  ");
      n_reval = 0;
      spd_l = 185;
      spd_r += 3;
      limit_spd();
    }

    m1.setSpeed(spd_l);
    m2.setSpeed(spd_r);
    clr_en_spd();
  }

}
void limit_spd()
{
  if (spd_l > 255)
  {
    spd_l = 255;
  }
  else if (spd_l < 140)
  {
    spd_l = 140;
  }
  if (spd_r > 255)
  {
    spd_r = 255;
  }
  else if (spd_r < 200)
  {
    spd_r = 200;
  }
}
void serialEvent2()
{
  while (Serial2.available())
  {
    p1 = Serial2.read();
  }
  if (p1 == 'S')
  {
    Serial.println("CMP!! ");
    Serial2.print("1,0,1,"); Serial2.println(white);
    p1 = ' ';
  }
  if (p1 == '3')
  {
    p1 = ' ';
    if (sen[0] > sen[2])
    {
      //  Serial2.println("111");
      cmd = rtn;
    }
    else
    { //Serial2.println("222");
      cmd = rtn2;
    }
  }
  digitalWrite(32, HIGH);
  delay(300);
  digitalWrite(32, LOW);

}
void serialEvent1()
{
  while (Serial1.available())
  { p = Serial1.read();

    if (p == ']')
    {
      Scut = 1;
    } else
    {
      data += p;
    }
  }

  if (Scut == 1)
  {

    Strcut();
    Scut = 2;
    con_step();
    Scut = 0; data = "";

  }

}
void Strcut()
{
  while (1)
  { int check = data.indexOf(',');


    if (check != -1)
    {

      sm[nn] = data.substring(0, check);
      data = data.substring(check + 1, data.length());

      nn++;
    }
    else
    {

      sm[nn] = data;
      mode = 1;
      nn = 0;

      break;
    }
  }
}
void con_step()
{

  sen[0] = sm[0].toInt();
  sen[1] = sm[1].toInt();
  sen[2] = sm[2].toInt();
  if (sen[0] > 45)
  {
    sd[0] = 0;
  }
  else
  {
    sd[0] = 1;
  }
  if (sen[1] > 37)
  {
    sd[1] = 0;
  }
  else
  {
    sd[1] = 1;
  }
  if (sen[2] >= 45)
  {
    sd[2] = 0;
  }
  else
  {
    sd[2] = 1;
  }
}
void serialEvent()
{
  while (Serial.available())
  {
    p = Serial.read();
  }
  if (p == '0')
  {
    //p1 = '0';
    p = ' ';
    cmd = fow;
  }
  if (p == '1')
  {
    //p1 = '1';
    p = ' ';
    cmd = lef;
  }
  if (p == '2')
  {
    //p1 = '2';
    p = ' ';
    cmd = rgt;
  }
  if (p == '3')
  {
    //  p1 = '3';
    p = ' ';
    cmd = rtn;
  }
  if (p == '4')
  {
    cmd = rtn2;
  }
  if (p == '5')
  {
    p = ' ';
    p1 = '5';
  }
}
