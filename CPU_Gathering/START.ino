//   run(1, 3, LR, FRONTSENSOR, L);
//   tt(70, 0.015, 0.15, 200, FRONTSENSOR);
//   kt(200,200);
//   tt(70, 0.015, 0.15, 150, BACKSENSOR);
//   l();
//   servo(1, openL);
//   servo(2, openR);
//   Move(30,50,300);
//   stop(100);
//   drop(RS, 250);
//   ml(40, 40, 7, 1, FRONTSENSOR);
//   Move(50, 50, 150);
//   l();
//   tt(50, 0.022, 0.22, 550, FRONTSENSOR);
//   servo(3, up);
//   stop(100);
//   tt(30, 0.022, 0.22, 600, FRONTSENSOR);
//   stop(250);
//   servo(3, medium);
//   stop(250);
//   servo(1, openL);
//   servo(2, openR);
//   stop(200);
//   servo(3, up);
// tr(50, 0.015, 0.15, FRONTSENSOR);
//   Move(50, 50, 40);
//   r();
//   Move(-30, -30, 80);
//   stop(100);
//   servo(3, medium);
//   stop(200);
//   servo(1, openL);
//   servo(2, openR);
//   stop(150);
// run(1, 2, R, FRONTSENSOR, N);
//   ml(40, 40, 0, 1, FRONTSENSOR);
//   kt(150, 250);
//   Move(50, -50, 135);

// run(1, 1, L, FRONTSENSOR, N);
//   Move(50,50,80);
//   l();
//   stop(100);
//   servo(1, openL180);
//   servo(2, openR180);
//   Move(-50,-50,120);
//   stop(150);
//   tt(100, 0.015, 0.15, 250, FRONTSENSOR);
//   Move(-50,-50,200);
//   r();

// servo(1, openL180);
// servo(2, openR180);
// servo(3,down);
// run(3, 1, R, FRONTSENSOR, L);
// tt(70, 0.015, 0.15, 80, FRONTSENSOR);
// kt(20,200);

// run(1, 1, L, FRONTSENSOR, N);
//   servo(1, openL);
//   servo(2, openR);
//   servo(3, down);
//   Move(50,50,400);
//   servo(1, closeL);
//   servo(2, closeR);
//   stop(100);
//   Move(-50,-50,400);

// sentor = 2000;
//   t(50, 0.015, 0.15, FRONTSENSOR);
//   Move(50,50,80);
//   l();
//   stop(100);
//   servo(1, openL);
//   servo(2, openR);
//   servo(3, down);
//   sentor = 3350;
//   stop(200);
//   servo(1, closeL);
//   servo(2, closeR);
//   stop(100);
//   servo(3,up);

// run(3, 2, R, FRONTSENSOR, N);
//   Move(50,50,50);
//   l();
//   stop(100);
//   Move(-50,-50,200);
//   servo(3,down);
//   stop(200);
//   servo(1, openL180);
//   servo(2, openR180);
//   stop(200);
//   tt(100, 0.015, 0.15, 250, FRONTSENSOR);
//   Move(-50,-50,250);
//   l();
void cube1() {
  run(1, 1, R, FRONTSENSOR, R);
  //servo(1, openL);
  //servo(2, openR);
  //servo(3, down);
  //tt(30, 0.015, 0.15, 400, FRONTSENSOR);
  //tt(40, 0.015, 0.15, 250, FRONTSENSOR);
  //servo(1, closeL);
  //servo(2, closeR);
  //run(1, 2, R, FRONTSENSOR, R);
  //run(2, 2, R, FRONTSENSOR, R);
  //run(4, 1, L, FRONTSENSOR, N);
  //drop(LS, 250);
}
/*
void cube2() {
  tr(-50, 0.015, 0.15, BACKSENSOR);
  l();
  run(1, 1, LR, FRONTSENSOR, R);
  run(1, 3, LR, FRONTSENSOR, L);
  tt(70, 0.015, 0.15, 150, FRONTSENSOR);
  k(5);
  run(1, 1, R, BACKSENSOR, L);
  run(1, 3, L, FRONTSENSOR, L);
  run(1, 2, LR, FRONTSENSOR, R);
  run(1, 1, R, FRONTSENSOR, N);
  drop(RS, 300);
}
void cube3() {
  tl(-50, 0.015, 0.15, BACKSENSOR);
  Move(-50, 50, 170);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  r();
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  tt(70, 0.015, 0.15, 100, FRONTSENSOR);
  k(5);
  Move(50,50,50);
  l();
  run(1, 1, R, FRONTSENSOR, R);
  run(1, 1, LR, FRONTSENSOR, R);
  run(1, 2, R, FRONTSENSOR, R);
  run(3, 1, L, FRONTSENSOR, L);
  run(1, 2, LR, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  l();
  run(1, 1, R, FRONTSENSOR, R);
  run(1, 1, L, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  r();
  t(50, 0.015, 0.15, FRONTSENSOR);
  drop(R,300);
}
void cube4() {
  servo(3,up);
  stop(100);
  Move(50,50,80);
  r();
  run(1, 1, L, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  r();
  run(1, 1, R, FRONTSENSOR, R);
  run(1, 1, L, FRONTSENSOR, L);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  tt(70, 0.015, 0.15, 200, FRONTSENSOR);
  k(5);
  run(1, 1, R, BACKSENSOR, L);
  run(1, 1, L, FRONTSENSOR, L);
  run(1, 2, L, FRONTSENSOR, N);
  Move(50,-50,170);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  r();
  run(1, 1, L, FRONTSENSOR, L);
  run(1, 2, LR, FRONTSENSOR, L);
  run(1, 1, L, FRONTSENSOR, N);
  drop(LP,150);
}
void cube5() {
  servo(3,up);
  Move(-50,-50,80);
  Move(50,-50,170);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  r();
  run(1, 1, L, FRONTSENSOR, L);
  run(1, 1, R, FRONTSENSOR, R);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  run(1, 1, LR, FRONTSENSOR, N);
  kt(5,250);
  Move(-50,-50,100);
  r();
  run(1, 2, R, FRONTSENSOR, R);
  run(3, 1, L, FRONTSENSOR, L);
  run(1, 2, LR, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  l();
  run(1, 1, R, FRONTSENSOR, R);
  run(1, 1, L, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  r();
  t(50, 0.015, 0.15, FRONTSENSOR);
  drop(RP,300);
}
void cube6() {
  servo(3,up);
  stop(100);
  Move(50,50,80);
  r();
  run(1, 1, L, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  l();
  tt(70, 0.015, 0.15, 200, FRONTSENSOR);
  Move(50,-50,180);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 100);
  l();
  run(1, 1, LR, FRONTSENSOR, L);
  run(1, 2, LR, FRONTSENSOR, N);
  servo(1, openL);
  servo(2, openR);
  servo(3, down);
  tt(40, 0.015, 0.15, 480, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  run(2, 2, R, BACKSENSOR, L);
  run(1, 3, L, FRONTSENSOR, L);
  run(1, 1, LR, FRONTSENSOR, R);
  run(1, 1, R, FRONTSENSOR, N);
  drop(RP,150);
  tl(-50,0.015,0.15,BACKSENSOR);
  Move(-50,-50,50);
  r();
  run(1, 2, LR, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  l();
  run(1, 1, R, FRONTSENSOR, R);
  run(1, 1, L, FRONTSENSOR, N);
  ml(40, 40, 7, 1, FRONTSENSOR);
  Move(50, 50, 50);
  l();
  run(1, 2, LR, FRONTSENSOR, N);
  Move(50,50,100);
}
*/