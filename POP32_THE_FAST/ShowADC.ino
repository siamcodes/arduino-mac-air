void ShowADC() {
  sw_ok_unpress();
  sw_ok_press();
  StartTimer();
  beep(1);
  sw_ok_unpress();
  if (ReadTimer() > 3000) SetSpeed();
  else {
    ReadADC();
    RefL1 = L1;
    RefL2 = L2;
    RefL3 = L3;
    RefC = C;
    RefR1 = R1;
    RefR2 = R2;
    RefR3 = R3;
    oled.clear();
    oled.text(0, 0, "L3 = %d", L3);
    oled.text(1, 0, "L2 = %d", L2);
    oled.text(2, 0, "L1 = %d", L1);
    oled.text(3, 0, "C = %d", C);
    oled.text(4, 0, "R1 = %d", R1);
    oled.text(5, 0, "R2 = %d", R2);
    oled.text(6, 0, "R3 = %d", R3);
    oled.show();


    sw_ok_unpress();
    sw_ok_press();
    beep(2);
    ReadADC();

    oled.text(0, 9, "L3 = %d", L3);
    oled.text(1, 9, "L2 = %d", L2);
    oled.text(2, 9, "L1 = %d", L1);
    oled.text(3, 9, "C = %d", C);
    oled.text(4, 9, "R1 = %d", R1);
    oled.text(5, 9, "R2 = %d", R2);
    oled.text(6, 9, "R3 = %d", R3);

    
 
    oled.text(5, 0, "Average");
    sw_ok_unpress();
    sw_ok_press();
    beep(3);
    RefL1 = (RefL1 + L1) / 2;
    RefR1 = (RefR1 + R1) / 2;
    oled.text(6, 0, "L1= %d", RefL1);
    oled.text(7, 0, "R1= %d", RefR1);
    sw_ok_unpress();
    sw_ok_press();
    beep(2);
    ShowSonar();
    sw_ok_unpress();
  }
}
