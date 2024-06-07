void BallPosition() {
  while(1){
    if (pixy.updateBlocks()) {
      int x = pixy.sigInfo[1][0].x;
      int y = pixy.sigInfo[1][0].y;
      oled.text(1,0,"x_axis : %d",x);
      oled.text(2,0,"y_axis : %d",y);
      oled.show();
      oled.clear();
    }
    oled.clear();
  }
}
