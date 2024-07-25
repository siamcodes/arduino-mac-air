//  >>>>>>>> KEEPER <<<<<<<<<  
//   servo(1, openL);
//   servo(2, openR);
//   stop(100);
//   servo(3, down);
//   // stop(200);
    // ml(30, 30, 7, 1, FRONTSENSOR);
    // tt(40, 0.016, 0.18, 30, FRONTSENSOR);
    // tr(40, 0.015, 0.15, FRONTSENSOR);
    // tl(40, 0.015, 0.15, FRONTSENSOR);
    // tlr(60, 0.01, 0.1, FRONTSENSOR);
//   servo(1, closeL);
//   servo(2, closeR);
//   stop(100);

// >>>>>>>>>>>>>>>>>>> Drop ...............................

// tlr(50, 0.01, 0.1, FRONTSENSOR);
// tt(50, 0.016, 0.18, 30, FRONTSENSOR);
// tr(50, 0.015, 0.15, FRONTSENSOR);
// tl(50, 0.015, 0.15, FRONTSENSOR);
// drop(LP,320);
// drop(RP,320);
// drop(RS,210);          //  one
// drop(RS,120);          //  two
// drop(LS,210)           //  one
// drop(LS,120);          //  two
//  drop(L,40);
//>>>>>>>>>>>>>>>>>>>>back oil drop..........
//  run(1, 1, R, BACKSENSOR, L);
//  tr(60, 0.018, 0.18, FRONTSENSOR); 
//   rr();
//     servo(1, openL);
//   servo(2, openR);
//   stop(100);
//   servo(3, down);
//   stop(200);
//     //ml(30, 30, 7, 1, FRONTSENSOR);
//     tt(40, 0.016, 0.18, 100, FRONTSENSOR);
//     //tr(40, 0.015, 0.15, FRONTSENSOR);
//     //tl(40, 0.015, 0.15, FRONTSENSOR);
//     //tlr(60, 0.01, 0.1, FRONTSENSOR);
//   servo(1, closeL);
//   servo(2, closeR);
//   stop(100);
//   Move(-50,-50,100);
//   r();


// >>>>>>>>>>>>>>>>>>> Oil drop ..........................

// tl(60, 0.012, 0.016, FRONTSENSOR);
// r();
// tt(50, 0.019, 0.18, 650, FRONTSENSOR);
// drop(S, 200);
// run(1, 1, LR, BACKSENSOR, R); 

// >>>>>>>>>>>>>>>>>>> Standart ...........................
//  tl(60, 0.018, 0.18, FRONTSENSOR);        // hardtack
//  tr(60, 0.018, 0.18, FRONTSENSOR);        // hardtack
//  tt(60, 0.018, 0.18, 1200, FRONTSENSOR);  // hardtack
//  tlr(60, 0.01, 0.1, FRONTSENSOR);
//  Move(50, 50, 100);
//  run(1, 1, LR, FRONTSENSOR, R);
//  run(1, 1, LR, BACKSENSOR, R);
//  ml(50, 50, 7, 1, FRONTSENSOR);
//  Kt(100,200);
//  tlr(60, 0.01, 0.1, FRONTSENSOR);
//  drop(L,0);



void cube1() {
run(1, 1, LR, FRONTSENSOR, L);
tl(60, 0.018, 0.18, FRONTSENSOR); 
 ml(50, 50, 7, 1, FRONTSENSOR);
 servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
  // stop(200);
    
    tr(40, 0.015, 0.15, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  stop(100);
    r();
    tlr(60, 0.01, 0.1, FRONTSENSOR);
    l();
    run(1, 1, LR, FRONTSENSOR, L);
    run(1, 1, LR, FRONTSENSOR, R);
    run(1, 1, L, FRONTSENSOR, L);
    run(2, 1, L, FRONTSENSOR, N);
    tr(60, 0.018, 0.18, FRONTSENSOR); 
    r();
  run(2, 1, LR, FRONTSENSOR, R);
  tl(60, 0.018, 0.18, FRONTSENSOR); 
  drop(L,40);         
}
void cube2() {
 run(2, 1, R, BACKSENSOR, L);

  
 tr(60, 0.018, 0.18, FRONTSENSOR); 
  rr();
    servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
  stop(200);
    //ml(30, 30, 7, 1, FRONTSENSOR);
    tt(40, 0.016, 0.18, 100, FRONTSENSOR);
    //tr(40, 0.015, 0.15, FRONTSENSOR);
    //tl(40, 0.015, 0.15, FRONTSENSOR);
    //tlr(60, 0.01, 0.1, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  stop(100);
  Move(-50,-50,100);
  r();
  tl(60, 0.018, 0.18, FRONTSENSOR); 
  l();
   tlr(60, 0.01, 0.1, FRONTSENSOR);
   r();
  tlr(60, 0.01, 0.1, FRONTSENSOR);
  tlr(60, 0.01, 0.1, FRONTSENSOR);
  l();
  run(2, 1, R, FRONTSENSOR, N);
run(1, 1, R, FRONTSENSOR, R);
  run(1, 1, LR, FRONTSENSOR, L);
  run(1, 1, R, FRONTSENSOR, R);
  tlr(60, 0.01, 0.1, FRONTSENSOR);
    drop(R,50); 
   



}
void cube3() {
l();
 tr(60, 0.018, 0.18, FRONTSENSOR); 
    r();
    tr(60, 0.018, 0.18, FRONTSENSOR); 
ml(50, 50, 7, 1, FRONTSENSOR);
r();
tr(60, 0.018, 0.18, FRONTSENSOR); 
r();
  servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
  // stop(200);
    //ml(30, 30, 7, 1, FRONTSENSOR);
    //tt(40, 0.016, 0.18, 30, FRONTSENSOR);
    //tr(40, 0.015, 0.15, FRONTSENSOR);
    tl(40, 0.015, 0.15, FRONTSENSOR);
    //tlr(60, 0.01, 0.1, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  stop(100);
  l();
  run(2, 1, L, FRONTSENSOR, L);
  run(2, 1, L, FRONTSENSOR, N);
  tlr(60, 0.01, 0.1, FRONTSENSOR);
   r();
  tlr(60, 0.01, 0.1, FRONTSENSOR);
  tlr(60, 0.01, 0.1, FRONTSENSOR);
  r();
tl(60, 0.018, 0.18, FRONTSENSOR);
drop(S,0);
}



void cube4() {
  tlr(-60, 0.01, 0.1, BACKSENSOR);
   ll();
     servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
  // stop(200);
    //ml(30, 30, 7, 1, FRONTSENSOR);
    tt(50, 0.016, 0.18, 500, FRONTSENSOR);
    //tr(40, 0.015, 0.15, FRONTSENSOR);
    //tl(40, 0.015, 0.15, FRONTSENSOR);
    //tlr(60, 0.01, 0.1, FRONTSENSOR);
  servo(1, closeL);
  servo(2, closeR);
  stop(100);
  run(2, 1, LR, BACKSENSOR, N);
   tlr(-60, 0.01, 0.1, BACKSENSOR);
   rr();
run(2, 1, R, FRONTSENSOR, N);
run(1, 1, R, FRONTSENSOR, R);
run(1, 1, LR, FRONTSENSOR, L);
run(1, 1, R, FRONTSENSOR, R);
tlr(60, 0.01, 0.1, FRONTSENSOR);
drop(RS,0);
   
  
  
}
void cube6() {
}