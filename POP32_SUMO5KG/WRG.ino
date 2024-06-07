void WRG() {
  ConvertADC();
  if (BC != 0) { //PA7  ถ้าเจอขาว = 0
    Can();
  } else {
    Line();
    ConvertADC();
  }
}
