void ShowADC() {
 // ConvertADC();
  ReadADC();
  Serial.println(String(L) + "\t" + String(C) + "\t" + String(R) + "\t" + String(FL) + "\t"+ String(FR));
  delay(300);
}
