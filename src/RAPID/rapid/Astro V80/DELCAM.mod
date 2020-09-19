%%%
  VERSION:1
  LANGUAGE:ENGLISH
%%%

MODULE DELCAM
  ! Home position = (0,0,0,0,90,90,9E9,9E9,9E9,9E9,9E9,9E9)
  !        Tool Origin (tool workplane relative to robot 6th axis)
  PERS tooldata claddinghead:=[TRUE,[[2.785,271.833,176.3],[0.00000000,0.00000000,1.00000000,0.00000000]],[30,[0,200,0],[1,0,0,0],0,0,0]];
  !        Part origin (part origin position relative to robot base)
  PERS wobjdata wDelcam1:=[FALSE,TRUE,"",[[1576.8,144,1160],[1,0,0,0]],[[0,0,0],[1,0,0,0]]];
  !        User defined feedrate v2
  PERS speeddata v2:=[2,500,5000,1000];
  PERS speeddata v160:=[160,500,5000,1000];
  PERS speeddata v13:=[13,500,5000,1000];
  !        User defined Zone data z0 (if not available)
  !CONST zonedata z0:=[FALSE,0.2,0.2,0.2,0.2,0.2,0.2];

  PROC main()
    ! Creation date: 2019/10/16 17:03:00
    ! Set robot acceleration and jerk
    AccSet 100,100;
    ! Configurations
    ConfJ\On;
    ConfL\Off;
    InitIO;
    !LaserOn;
    ! Start position = (2.4734,13.4689,-3.0771,0,79.6091,90,9E9,9E9,9E9,9E9,9E9,9E9)
	Proc_outer_rim_straight;
    !LaserOff;
    ConfJ\On;
    ConfL\On;
    Stop;
  ENDPROC

  	Proc InitIO()
		Reset doLaserReq;
		Reset doLaserOn;
		Reset DoBeam1;
		Reset DoAnologOn;
		SetAO aoPower,0;
		Reset doProgramStart;
	EndProc

	Proc LaserOn()
		setdo doLaserReq,1;
		Set doLaserOn;
		Set DoBeam1;
		Set DoAnologOn;
		SetAO aoPower, 2.919;
		TpWrite "Wait for laser ready signal";
		WaitDI diLaserReady,1;
		WaitTime 0.5;
	EndProc

	Proc LaserOff()
		SetAO aoPower,0;
		Reset DoAnologOn;
		Reset DoBeam1;
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
