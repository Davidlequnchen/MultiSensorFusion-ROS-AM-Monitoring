%%%
  VERSION:1
  LANGUAGE:ENGLISH
%%%


MODULE a20x40_wo_profile


LOCAL VAR intnum interrupt_path; !// intnum is used to identify an interupt
PERS num scanning_task:=0; !// scanning_task = 0 means not in scanning (interrupt) routine, but in normal routine
VAR robtarget stop_pos;



PROC Proc_a20x40_wo_profile()

  ! Set up interrupt
  IDelete interrupt_path; 
  CONNECT interrupt_path WITH trap_in_stop_point; !// connect interrupt signal to trap routine
  IPers scanning_task, interrupt_path; !// Interrupt at value change of a persistent variable
  ! Other interrupt method: ISignalDI (Interrupt Signal Digital In) is used to order and enable interrupts from a digital
  ! input signal

  routine_command:=2; !// change the mode to 2 (control mode)

  !ActUnit STN1;
    ! Start position = (4.0376,-5.8051,30.8485,0,64.9566,90,9E9,9E9,9E9,9E9,9E9,9E9)
  MoveL [[40.000,0.001,0.005],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v40,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,20.000,0.005],[0.73701988,0.00000000,0.00000000,-0.67587107],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[39.000,20.000,0.005],[0.73701988,0.00000000,0.00000000,-0.67587107],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[39.000,0.000,0.005],[0.73160810,0.00000000,0.00000000,-0.68172545],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[38.000,0.000,0.005],[0.73160810,0.00000000,0.00000000,-0.68172545],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[38.000,20.000,0.005],[0.73705647,0.00000000,0.00000000,-0.67583117],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[37.000,20.000,0.005],[0.73709013,0.00000000,0.00000000,-0.67579445],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[37.000,0.000,0.005],[0.73164210,0.00000000,0.00000000,-0.68168896],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[36.000,0.000,0.005],[0.73164210,0.00000000,0.00000000,-0.68168896],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[36.000,20.000,0.005],[0.73709013,0.00000000,0.00000000,-0.67579445],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[35.000,20.000,0.005],[0.73712379,0.00000000,0.00000000,-0.67575773],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[35.000,0.000,0.005],[0.73167610,0.00000000,0.00000000,-0.68165247],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[34.000,0.000,0.005],[0.73167610,0.00000000,0.00000000,-0.68165247],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[34.000,20.000,0.005],[0.73715746,0.00000000,0.00000000,-0.67572101],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[33.000,20.000,0.005],[0.73715746,0.00000000,0.00000000,-0.67572101],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[33.000,0.000,0.005],[0.73171010,0.00000000,0.00000000,-0.68161597],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[32.000,0.000,0.005],[0.73174409,0.00000000,0.00000000,-0.68157948],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[32.000,20.000,0.005],[0.73719111,0.00000000,0.00000000,-0.67568429],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[31.000,20.000,0.005],[0.73722477,0.00000000,0.00000000,-0.67564757],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[31.000,0.000,0.005],[0.73174409,0.00000000,0.00000000,-0.68157948],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[30.000,0.000,0.005],[0.73177808,0.00000000,0.00000000,-0.68154298],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[30.000,20.000,0.005],[0.73722477,0.00000000,0.00000000,-0.67564757],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[29.000,20.000,0.005],[0.73725842,0.00000000,0.00000000,-0.67561085],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[29.000,0.000,0.005],[0.73177808,0.00000000,0.00000000,-0.68154298],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[28.000,0.000,0.005],[0.73181207,0.00000000,0.00000000,-0.68150649],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[28.000,20.000,0.005],[0.73729207,0.00000000,0.00000000,-0.67557413],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[27.000,20.000,0.005],[0.73732572,0.00000000,0.00000000,-0.67553740],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[27.000,0.000,0.005],[0.73184606,0.00000000,0.00000000,-0.68146999],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[26.000,0.000,0.005],[0.73184606,0.00000000,0.00000000,-0.68146999],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[26.000,20.000,0.005],[0.73732572,0.00000000,0.00000000,-0.67553740],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[25.000,20.000,0.005],[0.73735937,0.00000000,0.00000000,-0.67550068],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[25.000,0.000,0.005],[0.73188004,0.00000000,0.00000000,-0.68143349],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[24.000,0.000,0.005],[0.73188247,0.00000000,0.00000000,-0.68143088],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[24.000,20.000,0.005],[0.73739301,0.00000000,0.00000000,-0.67546395],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[23.000,20.000,0.005],[0.73742665,0.00000000,0.00000000,-0.67542722],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[23.000,0.000,0.005],[0.73191646,0.00000000,0.00000000,-0.68139438],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[22.000,0.000,0.005],[0.73191646,0.00000000,0.00000000,-0.68139438],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[22.000,20.000,0.005],[0.73742665,0.00000000,0.00000000,-0.67542722],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[21.000,20.000,0.005],[0.73746029,0.00000000,0.00000000,-0.67539049],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[21.000,0.000,0.005],[0.73195044,0.00000000,0.00000000,-0.68135787],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[20.000,0.000,0.005],[0.73198442,0.00000000,0.00000000,-0.68132137],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[20.000,20.000,0.005],[0.73749689,0.00000000,0.00000000,-0.67535053],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[19.000,20.000,0.005],[0.73749689,0.00000000,0.00000000,-0.67535053],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[19.000,0.000,0.005],[0.73198442,0.00000000,0.00000000,-0.68132137],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[18.000,0.000,0.005],[0.73201840,0.00000000,0.00000000,-0.68128486],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[18.000,20.000,0.005],[0.73753053,0.00000000,0.00000000,-0.67531379],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[17.000,20.000,0.005],[0.73756416,0.00000000,0.00000000,-0.67527706],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[17.000,0.000,0.005],[0.73201840,0.00000000,0.00000000,-0.68128486],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[16.000,0.000,0.005],[0.73205238,0.00000000,0.00000000,-0.68124835],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[16.000,20.000,0.005],[0.73756416,0.00000000,0.00000000,-0.67527706],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[15.000,20.000,0.005],[0.73759780,0.00000000,0.00000000,-0.67524032],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[15.000,0.000,0.005],[0.73205238,0.00000000,0.00000000,-0.68124835],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[14.000,0.000,0.005],[0.73208635,0.00000000,0.00000000,-0.68121184],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[14.000,20.000,0.005],[0.73763143,0.00000000,0.00000000,-0.67520358],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[13.000,20.000,0.005],[0.73766505,0.00000000,0.00000000,-0.67516684],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[13.000,0.000,0.005],[0.73212032,0.00000000,0.00000000,-0.68117533],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[12.000,0.000,0.005],[0.73212032,0.00000000,0.00000000,-0.68117533],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[12.000,20.000,0.005],[0.73766505,0.00000000,0.00000000,-0.67516684],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[11.000,20.000,0.005],[0.73769868,0.00000000,0.00000000,-0.67513010],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[11.000,0.000,0.005],[0.73215429,0.00000000,0.00000000,-0.68113882],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[10.000,0.000,0.005],[0.73215429,0.00000000,0.00000000,-0.68113882],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[10.000,20.000,0.005],[0.73773230,0.00000000,0.00000000,-0.67509336],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[9.000,20.000,0.005],[0.73776592,0.00000000,0.00000000,-0.67505662],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[9.000,0.000,0.005],[0.73218826,0.00000000,0.00000000,-0.68110231],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[8.000,0.000,0.005],[0.73222222,0.00000000,0.00000000,-0.68106579],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[8.000,20.000,0.005],[0.73776592,0.00000000,0.00000000,-0.67505662],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[7.000,20.000,0.005],[0.73779954,0.00000000,0.00000000,-0.67501988],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[7.000,0.000,0.005],[0.73222222,0.00000000,0.00000000,-0.68106579],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[6.000,0.000,0.005],[0.73225619,0.00000000,0.00000000,-0.68102928],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[6.000,20.000,0.005],[0.73783615,0.00000000,0.00000000,-0.67497986],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[5.000,20.000,0.005],[0.73783615,0.00000000,0.00000000,-0.67497986],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[5.000,0.000,0.005],[0.73225619,0.00000000,0.00000000,-0.68102928],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[4.000,0.000,0.005],[0.73229015,0.00000000,0.00000000,-0.68099276],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[4.000,20.000,0.005],[0.73786977,0.00000000,0.00000000,-0.67494311],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[3.000,20.000,0.005],[0.73790338,0.00000000,0.00000000,-0.67490636],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[3.000,0.000,0.005],[0.73232410,0.00000000,0.00000000,-0.68095624],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[2.000,0.000,0.005],[0.73232410,0.00000000,0.00000000,-0.68095624],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[2.000,20.000,0.005],[0.73793699,0.00000000,0.00000000,-0.67486961],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[1.000,20.000,0.005],[0.73793699,0.00000000,0.00000000,-0.67486961],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[1.000,0.000,0.005],[0.73235806,0.00000000,0.00000000,-0.68091973],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,0.000,0.005],[0.73235806,0.00000000,0.00000000,-0.68091973],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,20.000,0.005],[0.73797060,0.00000000,0.00000000,-0.67483286],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  scanning_task:= 1; ! interrupt occurs, jump to trap routine
  ISleep interrupt_path; ! Deactivate interrupt
  scanning_task :=0; ! change back to 0
  IWatch interrupt_path; !Activate interrupt
  
  MoveL [[0.000,20.000,0.505],[0.73797060,0.00000000,0.00000000,-0.67483286],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v40,fine,claddinghead\WObj:=wDelcam1;
  MoveL [[40.000,0.000,0.505],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v40,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,0.000,0.505],[0.73235806,0.00000000,0.00000000,-0.68091973],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd; 
  MoveL [[0.000,1.000,0.505],[0.73266606,0.00000000,0.00000000,-0.68058831],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,1.000,0.505],[0.73184606,0.00000000,0.00000000,-0.68146999],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,2.000,0.505],[0.73212032,0.00000000,0.00000000,-0.68117533],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,2.000,0.505],[0.73294001,0.00000000,0.00000000,-0.68029328],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,3.000,0.505],[0.73321131,0.00000000,0.00000000,-0.68000087],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,3.000,0.505],[0.73239201,0.00000000,0.00000000,-0.68088321],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,4.000,0.505],[0.73266606,0.00000000,0.00000000,-0.68058831],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,4.000,0.505],[0.73348503,0.00000000,0.00000000,-0.67970560],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,5.000,0.505],[0.73379254,0.00000000,0.00000000,-0.67937362],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,5.000,0.505],[0.73294001,0.00000000,0.00000000,-0.68029328],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,6.000,0.505],[0.73321131,0.00000000,0.00000000,-0.68000087],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,6.000,0.505],[0.73406342,0.00000000,0.00000000,-0.67908092],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,7.000,0.505],[0.73433681,0.00000000,0.00000000,-0.67878527],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,7.000,0.505],[0.73348503,0.00000000,0.00000000,-0.67970560],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,8.000,0.505],[0.73375867,0.00000000,0.00000000,-0.67941020],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,8.000,0.505],[0.73461011,0.00000000,0.00000000,-0.67848949],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,9.000,0.505],[0.73491438,0.00000000,0.00000000,-0.67815990],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,9.000,0.505],[0.73402957,0.00000000,0.00000000,-0.67911751],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,10.000,0.505],[0.73430298,0.00000000,0.00000000,-0.67882188],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,10.000,0.505],[0.73518744,0.00000000,0.00000000,-0.67786387],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,11.000,0.505],[0.73546039,0.00000000,0.00000000,-0.67756772],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,11.000,0.505],[0.73457360,0.00000000,0.00000000,-0.67852902],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,12.000,0.505],[0.73484678,0.00000000,0.00000000,-0.67823315],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,12.000,0.505],[0.73573045,0.00000000,0.00000000,-0.67727447],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,13.000,0.505],[0.73600317,0.00000000,0.00000000,-0.67697809],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,13.000,0.505],[0.73511987,0.00000000,0.00000000,-0.67793715],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,14.000,0.505],[0.73539009,0.00000000,0.00000000,-0.67764402],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,14.000,0.505],[0.73630951,0.00000000,0.00000000,-0.67664489],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,15.000,0.505],[0.73657914,0.00000000,0.00000000,-0.67635137],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,15.000,0.505],[0.73566295,0.00000000,0.00000000,-0.67734779],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,16.000,0.505],[0.73593571,0.00000000,0.00000000,-0.67705143],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,16.000,0.505],[0.73685152,0.00000000,0.00000000,-0.67605461],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,17.000,0.505],[0.73712379,0.00000000,0.00000000,-0.67575773],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,17.000,0.505],[0.73620552,0.00000000,0.00000000,-0.67675803],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,18.000,0.505],[0.73647805,0.00000000,0.00000000,-0.67646144],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,18.000,0.505],[0.73742665,0.00000000,0.00000000,-0.67542722],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,19.000,0.505],[0.73769868,0.00000000,0.00000000,-0.67513010],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,19.000,0.505],[0.73675047,0.00000000,0.00000000,-0.67616473],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,20.000,0.505],[0.73701988,0.00000000,0.00000000,-0.67587107],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,20.000,0.505],[0.73797060,0.00000000,0.00000000,-0.67483286],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,20.000,1.005],[0.73797060,0.00000000,0.00000000,-0.67483286],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,0.000,1.005],[0.73235806,0.00000000,0.00000000,-0.68091973],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[1.000,0.000,1.005],[0.73235806,0.00000000,0.00000000,-0.68091973],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[1.000,20.000,1.005],[0.73793699,0.00000000,0.00000000,-0.67486961],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[2.000,20.000,1.005],[0.73793699,0.00000000,0.00000000,-0.67486961],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[2.000,0.000,1.005],[0.73232410,0.00000000,0.00000000,-0.68095624],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[3.000,0.000,1.005],[0.73232410,0.00000000,0.00000000,-0.68095624],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[3.000,20.000,1.005],[0.73790338,0.00000000,0.00000000,-0.67490636],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[4.000,20.000,1.005],[0.73786977,0.00000000,0.00000000,-0.67494311],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[4.000,0.000,1.005],[0.73229015,0.00000000,0.00000000,-0.68099276],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[5.000,0.000,1.005],[0.73225619,0.00000000,0.00000000,-0.68102928],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[5.000,20.000,1.005],[0.73783615,0.00000000,0.00000000,-0.67497986],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[6.000,20.000,1.005],[0.73783615,0.00000000,0.00000000,-0.67497986],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[6.000,0.000,1.005],[0.73225619,0.00000000,0.00000000,-0.68102928],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[7.000,0.000,1.005],[0.73222222,0.00000000,0.00000000,-0.68106579],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[7.000,20.000,1.005],[0.73779954,0.00000000,0.00000000,-0.67501988],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[8.000,20.000,1.005],[0.73776592,0.00000000,0.00000000,-0.67505662],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[8.000,0.000,1.005],[0.73222222,0.00000000,0.00000000,-0.68106579],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[9.000,0.000,1.005],[0.73218826,0.00000000,0.00000000,-0.68110231],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[9.000,20.000,1.005],[0.73776592,0.00000000,0.00000000,-0.67505662],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[10.000,20.000,1.005],[0.73773230,0.00000000,0.00000000,-0.67509336],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[10.000,0.000,1.005],[0.73215429,0.00000000,0.00000000,-0.68113882],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[11.000,0.000,1.005],[0.73215429,0.00000000,0.00000000,-0.68113882],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[11.000,20.000,1.005],[0.73769868,0.00000000,0.00000000,-0.67513010],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[12.000,20.000,1.005],[0.73766505,0.00000000,0.00000000,-0.67516684],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[12.000,0.000,1.005],[0.73212032,0.00000000,0.00000000,-0.68117533],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[13.000,0.000,1.005],[0.73212032,0.00000000,0.00000000,-0.68117533],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[13.000,20.000,1.005],[0.73766505,0.00000000,0.00000000,-0.67516684],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[14.000,20.000,1.005],[0.73763143,0.00000000,0.00000000,-0.67520358],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[14.000,0.000,1.005],[0.73208635,0.00000000,0.00000000,-0.68121184],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[15.000,0.000,1.005],[0.73205238,0.00000000,0.00000000,-0.68124835],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[15.000,20.000,1.005],[0.73759780,0.00000000,0.00000000,-0.67524032],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[16.000,20.000,1.005],[0.73756416,0.00000000,0.00000000,-0.67527706],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[16.000,0.000,1.005],[0.73205238,0.00000000,0.00000000,-0.68124835],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[17.000,0.000,1.005],[0.73201840,0.00000000,0.00000000,-0.68128486],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[17.000,20.000,1.005],[0.73756416,0.00000000,0.00000000,-0.67527706],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[18.000,20.000,1.005],[0.73753053,0.00000000,0.00000000,-0.67531379],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[18.000,0.000,1.005],[0.73201840,0.00000000,0.00000000,-0.68128486],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[19.000,0.000,1.005],[0.73198442,0.00000000,0.00000000,-0.68132137],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[19.000,20.000,1.005],[0.73749689,0.00000000,0.00000000,-0.67535053],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[20.000,20.000,1.005],[0.73749689,0.00000000,0.00000000,-0.67535053],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[20.000,0.000,1.005],[0.73198442,0.00000000,0.00000000,-0.68132137],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[21.000,0.000,1.005],[0.73195044,0.00000000,0.00000000,-0.68135787],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[21.000,20.000,1.005],[0.73746029,0.00000000,0.00000000,-0.67539049],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[22.000,20.000,1.005],[0.73742665,0.00000000,0.00000000,-0.67542722],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[22.000,0.000,1.005],[0.73191646,0.00000000,0.00000000,-0.68139438],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[23.000,0.000,1.005],[0.73191646,0.00000000,0.00000000,-0.68139438],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[23.000,20.000,1.005],[0.73742665,0.00000000,0.00000000,-0.67542722],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[24.000,20.000,1.005],[0.73739301,0.00000000,0.00000000,-0.67546395],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[24.000,0.000,1.005],[0.73188247,0.00000000,0.00000000,-0.68143088],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[25.000,0.000,1.005],[0.73188004,0.00000000,0.00000000,-0.68143349],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[25.000,20.000,1.005],[0.73735937,0.00000000,0.00000000,-0.67550068],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[26.000,20.000,1.005],[0.73732572,0.00000000,0.00000000,-0.67553740],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[26.000,0.000,1.005],[0.73184606,0.00000000,0.00000000,-0.68146999],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[27.000,0.000,1.005],[0.73184606,0.00000000,0.00000000,-0.68146999],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[27.000,20.000,1.005],[0.73732572,0.00000000,0.00000000,-0.67553740],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[28.000,20.000,1.005],[0.73729207,0.00000000,0.00000000,-0.67557413],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[28.000,0.000,1.005],[0.73181207,0.00000000,0.00000000,-0.68150649],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[29.000,0.000,1.005],[0.73177808,0.00000000,0.00000000,-0.68154298],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[29.000,20.000,1.005],[0.73725842,0.00000000,0.00000000,-0.67561085],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[30.000,20.000,1.005],[0.73725842,0.00000000,0.00000000,-0.67561085],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[30.000,0.000,1.005],[0.73177808,0.00000000,0.00000000,-0.68154298],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[31.000,0.000,1.005],[0.73174409,0.00000000,0.00000000,-0.68157948],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[31.000,20.000,1.005],[0.73722477,0.00000000,0.00000000,-0.67564757],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[32.000,20.000,1.005],[0.73719111,0.00000000,0.00000000,-0.67568429],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[32.000,0.000,1.005],[0.73174409,0.00000000,0.00000000,-0.68157948],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[33.000,0.000,1.005],[0.73171010,0.00000000,0.00000000,-0.68161597],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[33.000,20.000,1.005],[0.73715746,0.00000000,0.00000000,-0.67572101],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[34.000,20.000,1.005],[0.73715746,0.00000000,0.00000000,-0.67572101],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[34.000,0.000,1.005],[0.73167610,0.00000000,0.00000000,-0.68165247],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[35.000,0.000,1.005],[0.73167610,0.00000000,0.00000000,-0.68165247],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[35.000,20.000,1.005],[0.73712379,0.00000000,0.00000000,-0.67575773],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[36.000,20.000,1.005],[0.73709013,0.00000000,0.00000000,-0.67579445],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[36.000,0.000,1.005],[0.73164210,0.00000000,0.00000000,-0.68168896],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[37.000,0.000,1.005],[0.73164210,0.00000000,0.00000000,-0.68168896],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[37.000,20.000,1.005],[0.73709013,0.00000000,0.00000000,-0.67579445],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[38.000,20.000,1.005],[0.73705647,0.00000000,0.00000000,-0.67583117],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[38.000,0.000,1.005],[0.73160810,0.00000000,0.00000000,-0.68172545],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[39.000,0.000,1.005],[0.73160810,0.00000000,0.00000000,-0.68172545],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[39.000,20.000,1.005],[0.73701988,0.00000000,0.00000000,-0.67587107],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,20.000,1.005],[0.73701988,0.00000000,0.00000000,-0.67587107],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,0.000,1.005],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,0.000,1.505],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v40,fine,claddinghead\WObj:=wDelcam1;
  MoveL [[0.000,20.000,1.505],[0.73797060,0.00000000,0.00000000,-0.67483286],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v40,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,20.000,1.505],[0.73701988,0.00000000,0.00000000,-0.67587107],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,19.000,1.505],[0.73675047,0.00000000,0.00000000,-0.67616473],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,19.000,1.505],[0.73769868,0.00000000,0.00000000,-0.67513010],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,18.000,1.505],[0.73742665,0.00000000,0.00000000,-0.67542722],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,18.000,1.505],[0.73647805,0.00000000,0.00000000,-0.67646144],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,17.000,1.505],[0.73620552,0.00000000,0.00000000,-0.67675803],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,17.000,1.505],[0.73712379,0.00000000,0.00000000,-0.67575773],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,16.000,1.505],[0.73685152,0.00000000,0.00000000,-0.67605461],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,16.000,1.505],[0.73593571,0.00000000,0.00000000,-0.67705143],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,15.000,1.505],[0.73566295,0.00000000,0.00000000,-0.67734779],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,15.000,1.505],[0.73657914,0.00000000,0.00000000,-0.67635137],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,14.000,1.505],[0.73630951,0.00000000,0.00000000,-0.67664489],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,14.000,1.505],[0.73539009,0.00000000,0.00000000,-0.67764402],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,13.000,1.505],[0.73511987,0.00000000,0.00000000,-0.67793715],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,13.000,1.505],[0.73600317,0.00000000,0.00000000,-0.67697809],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,12.000,1.505],[0.73573045,0.00000000,0.00000000,-0.67727447],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,12.000,1.505],[0.73484678,0.00000000,0.00000000,-0.67823315],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,11.000,1.505],[0.73457360,0.00000000,0.00000000,-0.67852902],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,11.000,1.505],[0.73546039,0.00000000,0.00000000,-0.67756772],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,10.000,1.505],[0.73518744,0.00000000,0.00000000,-0.67786387],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,10.000,1.505],[0.73430298,0.00000000,0.00000000,-0.67882188],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,9.000,1.505],[0.73402957,0.00000000,0.00000000,-0.67911751],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,9.000,1.505],[0.73491438,0.00000000,0.00000000,-0.67815990],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,8.000,1.505],[0.73461011,0.00000000,0.00000000,-0.67848949],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,8.000,1.505],[0.73375867,0.00000000,0.00000000,-0.67941020],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,7.000,1.505],[0.73348503,0.00000000,0.00000000,-0.67970560],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,7.000,1.505],[0.73433681,0.00000000,0.00000000,-0.67878527],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,6.000,1.505],[0.73406342,0.00000000,0.00000000,-0.67908092],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,6.000,1.505],[0.73321131,0.00000000,0.00000000,-0.68000087],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,5.000,1.505],[0.73294001,0.00000000,0.00000000,-0.68029328],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,5.000,1.505],[0.73379254,0.00000000,0.00000000,-0.67937362],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,4.000,1.505],[0.73348503,0.00000000,0.00000000,-0.67970560],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,4.000,1.505],[0.73266606,0.00000000,0.00000000,-0.68058831],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,3.000,1.505],[0.73239201,0.00000000,0.00000000,-0.68088321],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,3.000,1.505],[0.73321131,0.00000000,0.00000000,-0.68000087],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,2.000,1.505],[0.73294001,0.00000000,0.00000000,-0.68029328],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,2.000,1.505],[0.73212032,0.00000000,0.00000000,-0.68117533],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[40.000,1.000,1.505],[0.73184606,0.00000000,0.00000000,-0.68146999],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[0.000,1.000,1.505],[0.73266606,0.00000000,0.00000000,-0.68058831],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Ends
  LaserEnd;
  MoveL [[0.000,0.000,1.505],[0.73235806,0.00000000,0.00000000,-0.68091973],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  ! Cutting Move Starts
  LaserStart;
  MoveL [[40.000,0.000,1.505],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v20,fine,claddinghead\WObj:=wDelcam1;
  LaserEnd;
  !DeActUnit STN1;

  routine_command:=0; !// change to mode 0 (idle mode)

  IDelete interrupt_path; 
ENDPROC




! the trap routine for surface scanning task
! trap_in_stop_point: Stop in next stop point
LOCAL TRAP trap_in_stop_point
  ! VAR robtarget stop_pos;
  ! Current move instruction on motion base path level continue
  ! New motion path level for new movements in the TRAP
  StorePath;
  ! Get current tool and work object data
  GetSysData claddinghead; 
  GetSysData wDelcam1;
  ! Store current position from motion base path level
  stop_pos := CRobT(\Tool:=claddinghead \WObj:=wDelcam1);

  ! Do the work
  routine_command:=0; !// tell ROS current state is 0: idle
  !// move to the point where scanning starts
  MoveL [[0.000,20.000,90.000],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v10,fine,claddinghead\WObj:=wDelcam1;
  
  routine_command:=1; ! routine_command is set to 1 (scanning mode), which will be read by Socket_routine.mod, and send to ROS
  WaitTime 5; !// wait for 5 seconds to let everything get ready
  !// scanning
  MoveL [[0.000,120.000,90.000],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v10,fine,claddinghead\WObj:=wDelcam1;
  routine_command:=0; ! idle mode 

  WaitTime 10; !// wait for ML and pcl segmentation result: is_defects 
  !// -------------------------------------------------------------------
  !// Defects check: global variable is_defects, which is declared in COMMOM.sys and read by Socket_routine, send by ROS
  !// -------------------------------------------------------------------
  IF is_defects = TRUE THEN
    Motion_command;  !// if there is defects, call the SERVER_motion function to execute the path planning results(JSON command)
    WaitTime 10;
  ENDIF

  
  ! Move back to interrupted position on the motion base path level
  MoveL stop_pos, v10, fine, claddinghead, \WObj:=wDelcam1;
  ! Go back to motion base path level
  RestoPath;
  ! Restart the interupted movements on motion base path level
  StartMove;

  routine_command:=2; ! set the routine_command to 2, which will let the ROS go to process control mode


ENDTRAP



! Stop on path at once
LOCAL TRAP trap_stop_at_once
  VAR robtarget stop_pos;
  ! Current move instruction on motion base path level stops
  ! at once If StopMove is used, the movement stops at once on the on-going path; otherwise,
  ! the movement continues to the ToPoint in the actual move instruction.
  StopMove;
  ! New motion path level for new movements in the TRAP
  StorePath;
  ! Get current tool and work object data note the name should be same as you defined
  GetSysData claddinghead; 
  GetSysData wDelcam1;
  ! Store current position from motion base path level
  stop_pos := CRobT(\Tool:=claddinghead \WObj:=wDelcam1);
  ! Do the work
  MoveL [[0.000,20.000,90.000],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v10,fine,claddinghead\WObj:=wDelcam1;
  MoveL [[100.000,20.000,90.000],[0.73157410,0.00000000,0.00000000,-0.68176194],[0,0,1,0],[9E9,9E9,9E9,9E9,9E9,9E9]],v10,fine,claddinghead\WObj:=wDelcam1;
  ! Move back to interrupted position on the motion base path level
  MoveL stop_pos, v10, fine, claddinghead,\WObj:=wDelcam1;
  ! Go back to motion base path level
  RestoPath;
  ! Restart the interupted movements on motion base path level
  StartMove;
ENDTRAP

ENDMODULE
