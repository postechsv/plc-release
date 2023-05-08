PROGRAMS
balancer([4, 0, 1]) ;;
obstacle([40, 0, 2]) ;;
background([50, 0 ,3]) ;;
PROGRAMSEND

TYPE
MODE : INIT, CAL, CONTROL ;
END_TYPE

VAR_GLOBAL
mode : MODE := INIT ;
obstacle_flag : BOOL := FALSE ;
END_VAR

PROGRAM balancer
VAR_IN
cmd_forward : DINT ;
cmd_turn : DINT ;
gyro_sensor : REAL ;
theta_m_l : REAL ;
theta_m_r : REAL ;
battery : REAL ;
pwm_l : DINT ;
pwm_r : DINT ;
END_VAR

VAR
avg_cnt : DINT ;
gyro_offset : REAL ;
END_VAR

CASE MODE OF
INIT:
    gyro_offset := 0;
    avg_cnt := 0;
    mode := CAL;
CAL:
    gyro_offset := gyro_offset + gyro_sensor;
    avg_cnt := avg_cnt + 1;
    IF avg_cnt >= 5 THEN
        gyro_offset := gyro_offset / avg_cnt;
        mode := CONTROL;
    END_IF;
CONTROL:

   IF obstacle_flag THEN
       cmd_forward := -100;
       cmd_turn := 0;
   ELSE
       skip;
   END_IF;

ELSE:
    skip;
END_CASE

END_PROGRAM

PROGRAM obstacle

VAR_IN
sonar : REAL;
END_VAR

IF mode := CONTROL AND sonar <= 100 THEN
    obstacle_flag := 1;
ELSE
    skip;
END_IF;

END_PROGRAM


PROGRAM background

emptyVDecl

WAIT(FALSE);

END_PROGRAM
