PROGRAMS
timer([1, 500, 0]) ;;
nsCar([2, 500, 0]) ;;
ewCar([3, 500, 0]) ;;
nsPed([3, 500, 0]) ;;
ewPed([4, 500, 0]) ;;
PROGRAMSEND

TYPE
COLOR : GREEN,RED,YELLOW,BLINKING;
END_TYPE

VAR_GLOBAL
nsTime : TIME ;
ewTime : TIME ;
nsContRed : BOOL := FALSE ;
ewContRed : BOOL := FALSE ;
nsColor : COLOR := RED ;
ewColor : COLOR := GREEN ;
END_VAR

PROGRAM timer

VAR
timer : TON ;
END_VAR

(* global timer setting*)
timer(TRUE, T#3500ms) ;

nsTime := timer.ET ;

IF timer.Q THEN
    timer(FALSE, T#3500ms);
    timer(TRUE, T#3500ms);
    nsTime := T#0ms;
END_IF;

(* offset setting. *)
ewTime := timer.ET + T#2s;

IF ewTime >= T#3500ms THEN
    ewTime := ewTime - T#3500ms;
END_IF;

END_PROGRAM

PROGRAM nsCar
VAR_INPUT
incoming : BOOL ;
END_VAR

VAR
controller : carLight ;
present : BOOL := FALSE ;
END_VAR

VAR_OUTPUT
color : COLOR;
green : BOOL;
END_VAR

present := present OR incoming;
controller(nsTime, present, nsContRed, ewContRed);
color := controller.color;
IF nsContRed AND ewContRed THEN
    color := RED;
END_IF;

nsColor := color;
green := color = GREEN;

END_PROGRAM

PROGRAM ewCar
VAR_INPUT
incoming : BOOL ;
END_VAR

VAR
controller : carLight ;
present : BOOL := FALSE ;
END_VAR

VAR_OUTPUT
color : COLOR;
green : BOOL;
END_VAR

present := present OR incoming;
controller(ewTime, present, ewContRed, nsContRed);
color := controller.color;
IF nsContRed AND ewContRed THEN
    color := GREEN;
END_IF;
ewColor := color;
green := color = GREEN;
END_PROGRAM

FUNCTION_BLOCK carLight
VAR_INPUT
currTime : TIME ;
END_VAR

VAR_IN_OUT
present : BOOL ;
continueRed : BOOL ;
continueGreen : BOOL ;
END_VAR

VAR_OUTPUT
color : COLOR ;
END_VAR

IF continueGreen THEN
    color := GREEN;
    WAIT(NOT continueGreen);
ELSE
;
END_IF;

IF currTime < T#2s THEN
    continueRed := color <> RED;
    color := RED;
ELSE
    IF currTime < T#3000ms THEN
        color := GREEN;
    ELSE
        color := YELLOW;
    END_IF;
END_IF;

IF continueRed THEN
    color := RED;
ELSE
;
END_IF;

continueRed := continueRed AND NOT (currTime <= T#500ms AND present);

present := present AND NOT color = GREEN;

END_FUNCTION_BLOCK



FUNCTION_BLOCK pedLight

VAR_INPUT
motherLight : COLOR ;
END_VAR

VAR_IN_OUT
buttonLit : BOOL ;
END_VAR

VAR_OUTPUT
color : COLOR ;
END_VAR

IF motherLight = RED THEN
    color := RED;
END_IF;

IF motherLight = GREEN AND buttonLit THEN
    color := motherLight;
    buttonLit := FALSE;
END_IF;

IF motherLight = YELLOW AND color = GREEN THEN
    color := BLINKING;
END_IF;

END_FUNCTION_BLOCK

PROGRAM nsPed 
VAR_INPUT
incoming : BOOL ;
END_VAR

VAR
controller : pedLight ;
buttonLit : BOOL ;
END_VAR

VAR_OUTPUT
color : COLOR ;
END_VAR

buttonLit := buttonLit OR incoming;

controller(nsColor, buttonLit);
color := controller.color;

END_PROGRAM


PROGRAM ewPed 

VAR_INPUT
incoming : BOOL ;
END_VAR

VAR
controller : pedLight ;
buttonLit : BOOL ;
END_VAR

VAR_OUTPUT
color : COLOR ;
END_VAR

buttonLit := buttonLit OR incoming;

controller(ewColor, buttonLit);
color := controller.color;

END_PROGRAM
