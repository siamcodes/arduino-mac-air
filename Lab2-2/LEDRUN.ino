void ledrun(){
  for(int i=0; i<= 3 ; i++ ){
    digitalWrite(LED[i], HIGH);
    delay(500);
    digitalWrite(LED[i], LOW);
    delay(500);
  }
  //เมื่อออกจาก loop ให้ Buzzer ดัง 1 ครั้ง
  
}
