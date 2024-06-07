void WRG() {
  ConvertADC();
  if (BC != 0) { //PA7  ถ้าเจอขาว = 0
    //Forward(Speed, 3);
    //TracTime(Speed,3);
    Can();
  } else {
    Line();
    ConvertADC();
  }
}
