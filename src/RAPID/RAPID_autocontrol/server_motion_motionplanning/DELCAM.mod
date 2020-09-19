%%%
  VERSION:1
  LANGUAGE:ENGLISH
%%%

MODULE DELCAM
  ! Home position = (0,0,0,0,90,90,9E9,9E9,9E9,9E9,9E9,9E9)
  !        Tool Origin (tool workplane relative to robot 6th axis)
  PERS tooldata claddinghead:=[TRUE,[[2.785,271.833,174.487],[0.00000000,0.00000000,1.00000000,0.00000000]],[30,[0,200,0],[1,0,0,0],0,0,0]];
  !        Part origin (part origin position relative to robot base)
  PERS wobjdata wDelcam1:=[FALSE,TRUE,"",[[1202.3,88.6,1000],[1,0,0,0]],[[0,0,0],[1,0,0,0]]];
  !        User defined feedrate v2
  PERS speeddata v2:=[2,500,5000,1000];
  !        User defined Zone data z0 (if not available)
  !CONST zonedata z0:=[FALSE,0.2,0.2,0.2,0.2,0.2,0.2];

  PROC main()
    ! Creation date: 2020/06/03 11:02:26
    ! Set robot acceleration and jerk
    AccSet 20,20;
    ! Configurations
    ConfJ\On;
    ConfL\Off;
    InitIO;
    LaserOn;
    ! Start position = (4.0376,-5.8051,30.8485,0,64.9566,90,9E9,9E9,9E9,9E9,9E9,9E9)
	Proc_a20x40_wo_profile;
  LaserOff;
    ConfJ\On;
    ConfL\On;
    Stop;
  ENDPROC
  
  	Proc InitIO()
		Reset doLaserReq;
		Reset doLaserOn;
		Reset DoBeam2;
		Reset DoAnologOn;
		SetAO aoPower,0;
		Reset doProgramStart;
	EndProc

	Proc LaserOn()
		setdo doLaserReq,1;
		Set doLaserOn;
		Set DoBeam2;
		Set DoAnologOn;
		SetAO aoPower, 2.2;
		TpWrite "Wait for laser ready signal";
		WaitDI diLaserReady,1;
		WaitTime 0.5;
	EndProc

	Proc LaserOff()
		SetAO aoPower,0;
		Reset DoAnologOn;
		Reset DoBeam2;
		Reset doLaserOn;
		WaitDI diLaserReady,0;
		setdo doLaserReq,0;
	EndProc

	Proc LaserStart()
		TpWrite "Laser welding started";
		setdo doProgramStart,1;
	EndProc

	Proc LaserEnd()
		setdo doProgramStart,0;
		TpWrite "Laser welding finished";
	EndProc  
  
ENDMODULE
