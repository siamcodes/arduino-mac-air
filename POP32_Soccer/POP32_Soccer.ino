#include <POP32.h>
int Speed, SlowSpeed, ACCSpeed;
void setup() {
  Speed = 50;
}
void loop() {
  waitSW_A_bmp();
  Can();
}
