void calibrate()
{
  for ( int i = 0; i <= 6; i++)
  {
    minValues[i] = analog(i);
    maxValues[i] = analog(i);
  }

  for (int i = 0; i < 3000; i++)
  {
    motor(1, 20);
    motor(2, -20);
    
    for ( int i = 0; i <= 6; i++)
    {
      if (analog(i) < minValues[i])
      {
        minValues[i] = analog(i);
      }
      if (analog(i) > maxValues[i])
      {
        maxValues[i] = analog(i);
      }
    }
  }

  for ( int i = 0; i <= 6; i++)
  {
    threshold[i] = (minValues[i] + maxValues[i]) / 2;
    oled.text(i, 0, "th%d = %d", i, threshold[i]);
  }
  oled.show();

  motor(1, 0);
  motor(2, 0);
}
