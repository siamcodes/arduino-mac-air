void linefollow()
{
  int error = (analog(2) - analog(4));

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;

  if (lsp > 100) {
    lsp = 100;
  }
  if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 100) {
    rsp = 100;
  }
  if (rsp < 0) {
    rsp = 0;
  }

  motor(1, lsp);
  motor(2, rsp);
}
