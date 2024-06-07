#include <POP32.h>

int P, D, I, previousError, PIDvalue, error;
int lsp, rsp;
int lfspeed = 50;

float Kp = 10;
float Kd = 0;
float Ki = 0 ;

int minValues[7], maxValues[7], threshold[7];

void setup()
{
 beep(1); 
 sw_ok_press();
 calibrate();
 beep(2);
}

void loop()
{
  sw_ok_press();
  while (1)
  {
    if (analog(1) > threshold[1] && analog(5) < threshold[5] )
    {
      lsp = 0; rsp = lfspeed;
      motor(1, 0);
      motor(2, lfspeed);
    }
    else if (analog(5) > threshold[5] && analog(1) < threshold[1])
    { lsp = lfspeed; rsp = 0;
      motor(1, lfspeed);
      motor(2, 0);
    }
    else if (analog(3) > threshold[3]) //Sensor Center
    {
      Kp = 0.0006 * (1000 - analog(3));
      Kd = 10 * Kp;
      //Ki = 0.0001;
      linefollow();
    }
  }
}
