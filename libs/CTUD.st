FUNCTION_BLOCK CTUD

VAR_INPUT
CU : BOOL := FALSE  ;
CD : BOOL := FALSE  ;
R : BOOL := FALSE  ;
LD : BOOL := FALSE  ;
PV : DINT :=  0  ;
END_VAR

VAR_OUTPUT
QU : BOOL := FALSE  ;
QD : BOOL := FALSE ;
CV : DINT :=  0  ;
END_VAR

IF R THEN CV := 0 ;
ELSIF LD THEN CV := PV ;
ELSE
    IF NOT (CU AND CD) THEN
        IF CU AND (CV < PV)
        THEN CV := CV + 1 ;
        ELSIF CD AND (CV > PV)
        THEN CV := CV - 1 ;
        END_IF ;
    END_IF ;
END_IF ;
QU := (CV >= PV) ;
QD := (CV <= 0) ;

END_FUNCTION_BLOCK