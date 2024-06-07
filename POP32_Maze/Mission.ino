void mission(){
  forward(SlowSpeed, 1);
  ReadADC();
  if(L < 15 && R < 15 && C > 5){
    forward(Speed, 1);
  }else if(C < 15 && R < 15 && L > 15){
    left();
    forward(Speed, 1);
  }else if(C < 15 && L < 15 && R > 15){
    right();
    forward(Speed, 1);
  }else{
    MotorStop();
  }
}
