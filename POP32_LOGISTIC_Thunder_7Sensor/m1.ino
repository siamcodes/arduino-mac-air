void m1()
{
  // FF(50, 0.11, 0.05, 'p', 10, 50, -10);
  // FFtimer(40, 0.11, 0.05, 1000, 50, -10);
  // FF(50, 0.05, 3.05, 's', 200, 100, -10);
  
     FF(50, 0.05, 0.01, 'p', 20, 100, -10);
     SpinR();
     FF(100, 0.05, 3.05, 'p', 20, 100, -10);
     SpinL();
     FF(50,0.05,3.05,'p',100,100,-10);
      SpinL();
     FF(100,0.05,3.05,'p',100,100,-10);
     SpinL();
     SpinL();
     SpinL();
     FF(100,0.05,3.05,'p',20,100,-10);
     
 
}
