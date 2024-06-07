void Read3Sonar() //อ่านค่า 3 Sonar
{
  SonarF = sonar(); //HC-SR04
  //SonarF = analog(4)/10; //ZX-Sonar
  SonarR1 = analog(3)/10; //ZX-Sonar
  SonarR2 = analog(2)/10; //ZX-Sonar
  delay(10);  //หน่วงเวลา 10 ms
}
