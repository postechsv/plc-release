PROGRAMS
balancer([1, 4, 0]) ;;
obstacle([2, 6, 0]) ;;
background([3, 12, 0]) ;;
PROGRAMSEND

TYPE
MODE : INIT, CAL, CONTROL ;
END_TYPE

VAR_GLOBAL
mode : MODE := INIT ;
obstacle_flag : BOOL := FALSE ;
END_VAR

PROGRAM balancer
VAR_INPUT
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
avg_cnt : REAL ;
gyro_offset : REAL ;
END_VAR

CASE mode OF
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
   END_IF;

ELSE
    ;
END_CASE;

END_PROGRAM

PROGRAM obstacle

VAR_INPUT
sonar : REAL;
END_VAR

IF mode = CONTROL AND sonar <= 100 THEN
    obstacle_flag := 1;
END_IF;

END_PROGRAM


PROGRAM background

WAIT(FALSE);

END_PROGRAM
