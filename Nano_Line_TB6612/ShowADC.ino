void ShowADC(){
  ReadADC();
  Serial.println(String(L3)+"\t"+String(L2)+"\t"+String(L1)+"\t"+String(C)+"\t"+String(R1)+"\t"+String(R2)+"\t"+String(R3));
  delay(200);
}
