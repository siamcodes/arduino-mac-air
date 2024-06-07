void CalError() //คำนวณ error
{
  ConvertADC();
  if ((L1 == 1) && (C == 1) && (R1 == 0)) Error = -1;
  else if ((L1 == 1) && (C == 0) && (R1 == 0)) Error = -2;
  else if ((L1 == 1) && (C == 0) && (R1 == 1)) Error = 0;
  else if ((L1 == 0) && (C == 1) && (R1 == 1)) Error = 1;
  else if ((L1 == 0) && (C == 0) && (R1 == 1)) Error = 2;
  
  else if ((L1 == 0) && (C == 0) && (R1 == 0)) Error = 100;
  else if ((L1 == 1) && (C == 1) && (R1 == 1)) Error = 101;
}
