%%%
  VERSION:1
  LANGUAGE:ENGLISH
%%%

MODULE FREECAD
  ! Home position = (0,0,0,0,90,90,9E9,9E9,9E9,9E9,9E9,9E9)
  !        Tool Origin (tool workplane relative to robot 6th axis)
  PERS tooldata claddinghead:=[TRUE,[[1.235,270.986,166.765],[0.00000000,0.00000000,1.00000000,0.00000000]],[30,[0,200,0],[1,0,0,0],0,0,0]];
  !        Part origin (part origin position relative to robot base)
  PERS wobjdata wFCpivot:=[FALSE,TRUE,"",[[1257.2,445,938.4],[1,0,0,0]],[[0,0,0],[1,0,0,0]]];
  !        User defined feedrate v2
  PERS speeddata v2:=[2,500,5000,1000];
  !        User defined Zone data z0 (if not available)
  !CONST zonedata z0:=[FALSE,0.2,0.2,0.2,0.2,0.2,0.2];

  PROC main()
    ! Creation date: 2019/9/6 10:9:5
    ! Set robot acceleration and jerk
    AccSet 60,60;
    ! Configurations
    ConfJ\On;
    ConfL\Off;
    InitIO;
    LaserOn;
    ! Start position = (4.0531,-6.6801,29.4404,0,67.2402,90,9E9,9E9,9E9,9E9,9E9,9E9)
	Proc_Sphere_top_post_RAPID_PROC;
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
		SetAO aoPower, 4.8;
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
