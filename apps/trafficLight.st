PROGRAMS
Main([1,1]) ;;
PROGRAMSEND
CycleTime: 500

TYPE
COLOR : GREEN,RED,YELLOW,BLINKING ;
DIRECTION : NS,EW ;
PLMode : NORMAL,EMERGENCY ;


END_TYPE

VAR_GLOBAL
totalDuration : TIME := T#3500ms ;
END_VAR


PROGRAM Main
VAR
c1NS : carLight ;
c1EW : carLight ;
timer : TON ;
currTime : TIME ;
startBit : BOOL := TRUE ;
nsColor : COLOR ;
NScontGreen : BOOL := FALSE ;
NScontRed : BOOL := FALSE ;
currTime2 : TIME ;
EWcontGreen : BOOL := FALSE ;
EWcontRed : BOOL := FALSE ;
ewColor : COLOR ;
nsPresent : BOOL := FALSE ;
ewPresent : BOOL := FALSE ;
nsPedWaiting : BOOL := FALSE ;
ewPedWaiting : BOOL := FALSE ;
nsPed : pedLight ;
ewPed : pedLight ;
nsPedColor : COLOR ;
ewPedColor : COLOR ;
p1 : BOOL ;
p2 : BOOL ;
nsIncoming : BOOL := FALSE ;
ewIncoming : BOOL := FALSE ;
nspIncoming : BOOL := FALSE ;
ewpIncoming : BOOL := FALSE ;
yellow1 : TIME ;
yellow2 : TIME ;
isGreen : BOOL ;
isRed : BOOL ;
bothGreen : BOOL ;
bothRed : BOOL ;
END_VAR

(* global timer setting*)
timer(TRUE, totalDuration);

currTime := timer.ET;

IF timer.Q THEN
    timer(FALSE, totalDuration);
    timer(TRUE, totalDuration);
    currTime := T#0s;
END_IF;

(* offset setting. *)
currTime2 := timer.ET + T#2s;

IF currTime2 >= T#3500ms THEN
    currTime2 := currTime2 - T#3500ms;
END_IF;

(* main logic *)



nsPresent := nsPresent OR nsIncoming;
nsIncoming := FALSE;

ewPresent := ewPresent OR ewIncoming;
ewIncoming := FALSE;

nsPedWaiting := nsPedWaiting OR nspIncoming;
nspIncoming := FALSE;

ewPedWaiting := ewPedWaiting OR ewpIncoming;
ewpIncoming := FALSE;

p1 := nsPresent OR nsPedWaiting;
p2 := ewPresent OR ewPedWaiting;

c1NS(currTime,  p1, yellow1, NScontGreen, NScontRed);
c1EW(currTime2, p2, yellow2, EWcontGreen, EWcontRed);
nsPed(nsColor, nsPedWaiting);
ewPed(ewColor, ewPedWaiting);

nsColor  := c1NS.color;
ewColor  := c1EW.color;
nsPedColor := nsPed.color;
ewPedColor := ewPed.color;

EWcontGreen := EWcontGreen AND NOT (p1 AND currTime2 >= T#2s AND currTime2 < T#3s);
(* buggy code *)
NScontGreen := NScontGreen AND NOT p2;
(* the fix
NScontGreen := NScontGreen AND NOT (p2 AND currTime >= T#2s AND currTime < T#3s);
*)

nsPresent := nsPresent AND NOT (c1NS.color = GREEN);
ewPresent := ewPresent AND NOT (c1EW.color = GREEN);

isGreen := (nsColor = GREEN);
isRed := (nsColor = RED);
bothGreen := (nsColor = GREEN) AND (ewColor = GREEN);

END_PROGRAM

SUBPROGRAM pOnDivZero
END_SUBPROGRAM

SUBPROGRAM pOnBadIndex
END_SUBPROGRAM

FUNCTION_BLOCK carLight
VAR_INPUT
currTime : TIME ;
present : BOOL ;
yellowTime : TIME ;
END_VAR

VAR_IN_OUT
continueGreen : BOOL ;
continueRed : BOOL ;
END_VAR

VAR_OUTPUT
color : COLOR ;
END_VAR

yellowTime := MAX(T#500ms, yellowTime);

(* override behavior *)
IF continueRed THEN
    color := RED;
ELSE 
    IF continueGreen THEN
        color := GREEN;
    ELSE
(* default behavior *)
        IF currTime < T#2s THEN
            continueRed := color <> RED;
            color := RED;
        ELSE 
            IF currTime < T#3500ms - yellowTime AND color <> YELLOW THEN
                continueGreen := color <> GREEN;
                color := GREEN;
            ELSE
                color := YELLOW;
            END_IF;    
        END_IF;
    END_IF;
END_IF;

continueRed := continueRed AND NOT (currTime <= T#500ms AND present);
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

