void ShowADC(){
  ReadADC();
  Serial.println(String(A[0])+"\t"+String(A[1])+"\t"+String(A[2])+"\t"+String(A[3])+"\t"+String(A[4])+"\t"+String(A[5])+"\t"+String(A[6])+"\t"+String(A[7]));
  delay(200);
}
