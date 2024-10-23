//  >>>>>>>> KEEPER <<<<<<<<<
  // servo(1, openL);
  // servo(2, openR);
  // stop(100);
  // servo(3, down);
  //     stop(200);
  //     ml(60, 62, 7, 1, FRONTSENSOR);
  //     tr(50, 0.015, 0.15, FRONTSENSOR);
  //     tl(50, 0.015, 0.15, FRONTSENSOR);
  //     tlr(50, 0.01, 0.1, FRONTSENSOR);
  //     tt(50, 0.016, 0.18, 30, FRONTSENSOR);
  //     tt(40, 0.018, 0.18, 000, FRONTSENSOR);      
                
  //  servo(1, closeL);
  //  servo(2, closeR);
  //  stop(100);

      // //         T   = 100       2b_box = 606 L                b  = 606 L 
      // //         2T  = 450       2b_box = 606 L                2b = 606 L    
      // //         2T  = 450       2b_box = 210 S                2b = 480 S        
      // //         3T  = 650       2b_box = 240 M  speed = 40    2b = 240 M  speed = 40                           
      // //         1Y  = 110       C  = 60  
      // //         2Y  = 650       KEEPDOUBLE = 350         HALF _LCYCLE =  tt(40, 0.020, 0.18, 550, FRONTSENSOR);    HALF _SCYCLE   tt(40, 0.018, 0.18, 800, FRONTSENSOR);
     //  tt(40, 0.018, 0.18, 100, FRONTSENSOR);   เดินหน้่นิดเดียวเพื่อตบซ้าย

// >>>>>>>>>>>>>>>>>>> Shoot Big  ...............................
//   servo(3, up);  
//   stop(100);

    //  r();
    //  l();
    //  tt(40, 0.025, 0.22, 100, FRONTSENSOR);
    //  servo(3, medium);
    //  stop(50);
    //  servo(1, openL);
    //  servo(2, openR);
    //  stop(150);
    //  Move(-60,-62,100);

//   r_lstop();
//   tt(40, 0.025, 0.22, timer_in, FRONTSENSOR);
//   Move(-60,-60,180);
//   servo(1, openL180);
//   servo(2, openR180);
//   stop(50);
//   Move(100,100,180);
//   Move(-60,-62,180);
//   stop(100);
//   servo(3, up);
//   stop(100);
//   servo(1, closeL);
//   servo(2, closeR); 



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
// drop(L,200);
// drop(L,0)
// drop (R,200);
// drop (RR,);
// drop (R,0);
// drop (Lo,120);
// drop (Ro,60);
// drop (LS,150);
// drop (LLS,0);
// drop(SS,100);          // OPEN
// drop(S,100);           // CLOSE



//<<<<<<<<<<<<<<<<<<<<<<<<<<drop up>>>>>>>>>>>>>>>>>>>>>>.
// tr(60, 0.013, 0.2,  FRONTSENSOR);
// servo(3, up70);
// tl(40, 0.01, 0.2,  FRONTSENSOR);
// servo(1, openLup);
//   servo(2, openRup);
//   stop(300);

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
//  ml(60, 62, 7, 1, FRONTSENSOR);
//  Kt(100,200);
//  tlr(60, 0.01, 0.1, FRONTSENSOR);
//   ml(60, 62, 7, 1, FRONTSENSOR);
//  drop(L,0);
// tr(40, 0.022, 0.22, FRONTSENSOR);
// rrr();
// rrr();

//>>>>>>>>>>>>>>>>>>>>>>>>>> Move.................... ...........
//    Move(60,-60,50);                          //  30_R
//    Move(60,-60,100);                         //  45_R
//    Move(60,-60,150);                          //  60_R
//    Move(60,-60,175);                         //  90_R
//    Move(60,-60,250);                         //  120_R
//    Move(-60,60,50);                          //  30_L
//    Move(-60,60,100);                         //  45_L
//    c                        //  60_L
//    Move(60,-60,175);                         //  90_L
//    Move(-60,60,250);                         //  120_L
//    Move(60,-60,50);                          //
//    Move(60,-60,120);                         //  FRONT_90

//    Move(-60,60,150);                         //  BACK_90
//    Move(60,-60,150);                         //  FRONT_C
//  ml(15, 50, 0, 1, FRONTSENSOR);              //  Cycle

//>>>>>>>>>>>>>>>>>MARKSHOOT..........................
//  shoot_r(260);
//  shoot_l(260);
//  tt(40, 0.018, 0.18, 350, FRONTSENSOR);       // Shoot 2T
//  shoot_t(0);

//_________________________________________________.  ตบซ้าย  ลูกใหญ่
     //tl(60, 0.018, 0.18, FRONTSENSOR); 
//    tt(40, 0.018, 0.18, 100, FRONTSENSOR);
// drop(SS,100);
//  Move(60,-60,175);
// servo(3, down);
// stop(200);
// Move(-100,100,150); 
//------------------------------                          ตบขวา.  
//tr(60, 0.018, 0.18, FRONTSENSOR); 
//    tt(40, 0.018, 0.18, 100, FRONTSENSOR);
// drop(SS,100);
//  Move(-60,60,175);
// servo(3, down);
// stop(200);
// Move(100,-100,150); 

//>>>>>>>>>>>>>>>>>Kr/Kl/kt..........................
//  kr(70);             // one  blick
//  kr(200);            // two  blick
//  kl(70);             // one  blick
//  kl(200);            // two  blick

void cube1() {
  run(2, 1, R, FRONTSENSOR, R);
   tt(50, 0.016, 0.18, 200, FRONTSENSOR);
     servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
      stop(200);
      ////ml(60, 62, 7, 1, FRONTSENSOR);
      //tr(50, 0.015, 0.15, FRONTSENSOR);
      tl(50, 0.015, 0.15, FRONTSENSOR);
      //tlr(50, 0.01, 0.1, FRONTSENSOR);
      ////tt(50, 0.016, 0.18, 30, FRONTSENSOR);
      //tt(40, 0.018, 0.18, 000, FRONTSENSOR);      
                
   servo(1, closeL);
   servo(2, closeR);
   stop(100);
  l();
  run(1, 1, R, FRONTSENSOR, R);
  
    tr(70, 0.018, 0.18, FRONTSENSOR);
    r();
    tr(50, 0.015, 0.15, FRONTSENSOR);
    drop(R,210);
   

    }
    void cube2() {
  run(2, 1, R, FRONTSENSOR, N);
  Move(-60,60,150);
    servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
      stop(200);
      ml(70, 72, 7, 1, FRONTSENSOR);
    
      //tr(50, 0.015, 0.15, FRONTSENSOR);
      //tl(50, 0.015, 0.15, FRONTSENSOR);
      //tlr(50, 0.01, 0.1, FRONTSENSOR);
      //tt(50, 0.016, 0.18, 30, FRONTSENSOR);
      //tt(40, 0.018, 0.18, 000, FRONTSENSOR);      
                
   servo(1, closeL);
   servo(2, closeR);
   stop(100);
 ml(60, 62, 7, 1, BACKSENSOR);
 Move(-60,-60,150);
 l();
run(1, 1, L, FRONTSENSOR, N);

tl(60, 0.018, 0.18, FRONTSENSOR);
tl(60, 0.018, 0.18, FRONTSENSOR);
l();
tr(70, 0.018, 0.18, FRONTSENSOR);
l();
tr(65, 0.018, 0.18, FRONTSENSOR);
r();
tt(50, 0.016, 0.18, 400, FRONTSENSOR);
Move(-60,60,150); 
  ml(60, 62, 7, 2, FRONTSENSOR);
//  Move(60,60,100);
 l();
 ll();
 tt(50, 0.016, 0.18, 300, FRONTSENSOR);
 shoot_t(0);

//`  tr(65, 0.018, 0.18, FRONTSENSOR);

    }
    void cube3() {
 run(1, 1, L, BACKSENSOR, N);
       Move(-60,60,110);
       ml(60, 62, 7, 2, FRONTSENSOR);
    l();
    tr(65, 0.018, 0.18, FRONTSENSOR);
      r();
      tr(60, 0.018, 0.18, FRONTSENSOR);
      l();
        servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
      stop(200);
      // ml(60, 62, 7, 1, FRONTSENSOR);
       tr(50, 0.01, 0.1, FRONTSENSOR);
      // tl(50, 0.015, 0.15, FRONTSENSOR);
      // tlr(50, 0.01, 0.1, FRONTSENSOR);
      // tt(50, 0.016, 0.18, 30, FRONTSENSOR);
      tt(40, 0.015, 0.18, 105, FRONTSENSOR);      
                
   servo(1, closeL);
   servo(2, closeR);
   stop(100);
   l();
       run(2, 1, LR, FRONTSENSOR, N);
           run(1, 1, L, FRONTSENSOR, N);
           servo(3, medium);
              tl(65, 0.018, 0.18, FRONTSENSOR);
      l();
     
       tt(45, 0.018, 0.18, 470, FRONTSENSOR);  
  servo(1, openL);
  servo(2, openR);

    }
    void cube4() {

 run(1, 1, R, BACKSENSOR, L);
  servo(3, up);
  run(1, 1, R, FRONTSENSOR, R);
  servo(1, closeL);
  servo(2, closeR);
 run(2, 1, L, FRONTSENSOR, N);
 tl(50, 0.015, 0.15, FRONTSENSOR);
 ll();
   servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
      stop(200);
      // ml(60, 62, 7, 1, FRONTSENSOR);
      // tr(50, 0.015, 0.15, FRONTSENSOR);
      // tl(50, 0.015, 0.15, FRONTSENSOR);
      // tlr(50, 0.01, 0.1, FRONTSENSOR);
      // tt(50, 0.016, 0.18, 30, FRONTSENSOR);
      tt(40, 0.017, 0.18, 100, FRONTSENSOR);      
                
   servo(1, closeL);
   servo(2, closeR);
   stop(100);
   Move(-60,-60,100);
   l();
    run(2, 1,R, FRONTSENSOR, N);
    tl(65, 0.018, 0.18, FRONTSENSOR);
               
      r();
      tr(60, 0.018, 0.18, FRONTSENSOR);
l();
tr(65, 0.018, 0.18, FRONTSENSOR);
r();
tt(50, 0.016, 0.18, 400, FRONTSENSOR);
Move(-60,60,150); 
  ml(60, 62, 7, 2, FRONTSENSOR);
  Move(60,60,100);

 l();
 tt(40, 0.018, 0.18, 350, FRONTSENSOR);
 shoot_t(0);

    }
    void cube5() {
run(1, 1, L, BACKSENSOR, N);
       Move(-60,60,110);
       ml(60, 62, 7, 2, FRONTSENSOR);
    l();
    tr(65, 0.018, 0.18, FRONTSENSOR);
      r();
      tr(60, 0.018, 0.18, FRONTSENSOR);
      l();
        servo(1, openL);
  servo(2, openR);
  stop(100);
  servo(3, down);
      stop(200);
      // ml(60, 62, 7, 1, FRONTSENSOR);
       tr(50, 0.015, 0.15, FRONTSENSOR);
      // tl(50, 0.015, 0.15, FRONTSENSOR);
      // tlr(50, 0.01, 0.1, FRONTSENSOR);
      // tt(50, 0.016, 0.18, 30, FRONTSENSOR);
      tt(30, 0.015, 0.18, 250, FRONTSENSOR);      
                
   servo(1, closeL);
   servo(2, closeR);
   stop(100);
   l();
run(2, 1, LR, FRONTSENSOR, N);

 tr(70, 0.018, 0.18, FRONTSENSOR);
    r();
    tr(50, 0.015, 0.15, FRONTSENSOR);
    drop(R,120);
// run(1, 1, LR, BACKSENSOR,R);
// run(2, 2, LR, FRONTSENSOR,R);

 tlr(-50, 0.01, 0.1, BACKSENSOR);
 r();
run(2, 2, LR, FRONTSENSOR,R);
run(1, 1, LR, FRONTSENSOR,N);
    }

