char Read_sw_OK()  {
  if (analog(13)<=5) return(1);     //press sw OK
  //else if(digitalRead(18)==0) {digital_sw = 1; return(1);}  //press digital sw 
  else return(0);
}
void sw_ok_unpress()  {
  while(Read_sw_OK()) {}
}
