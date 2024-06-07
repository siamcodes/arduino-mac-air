void Read2Analog() {
  L1 = analog(2); 
  R1 = analog(3);
}

int Sonar()
{
  int Sonar;
   
  //Sonar = (analog(0)/10); //ZX-sonor
  Sonar = analog(0);   //infared
  if(Sonar==0) Sonar = 1;
  Sonar = 3000/Sonar;
  return(Sonar);
}
