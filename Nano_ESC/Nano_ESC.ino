/*
 * ESC Contribution Calculation (ROV Platform)
 * LovecodingBlogger
 * http://lovecodingblogger.blogspot.com
 */

#include <Servo.h> 
Servo esc; // Object from class

void setup() {
 
  esc.attach(6); //Set I/O PWM 
  esc.writeMicroseconds(2000); //Set max pulse-width
  esc.writeMicroseconds(1000); //Set min pulse-width
  
}//end setup fuc

void loop() {
  
  for(int i = 1000; i <= 2000; i++)
  {
    esc.writeMicroseconds(i);
    delay(10);
  }
  for(int i = 2000; i >= 1000; i--)
  {
    esc.writeMicroseconds(i);
    delay(10);
  }
  delay(1000);
  
}//end loop fuc
