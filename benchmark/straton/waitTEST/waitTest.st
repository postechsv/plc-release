PROGRAMS
Main([1,1]) ;;
Main2([1,1]) ;;
PROGRAMSEND
CycleTime: 0

TYPE


END_TYPE


PROGRAM Main
VAR
NewVar : BOOL ;
CYCLE : DINT ;
END_VAR

NewVar := NOT NewVar ;

WAIT(FALSE) ;

NewVar := NOT NewVar ;

CYCLE := CYCLE + 1 ;

END_PROGRAM

PROGRAM Main2
VAR
CYCLE2 : DINT ;
END_VAR

CYCLE2 := CYCLE2 + 1 ;
END_PROGRAM

SUBPROGRAM pOnDivZero
// pOnDivZero: this sub program is called in case of a division by zero

// add your code here


// to turn the Service in 'cycle to cycle' pause mode, use:
//  CycleStop (TRUE);

// to turn the Service in 'fatal error' mode, use:
//  FatalStop (TRUE);
END_SUBPROGRAM

SUBPROGRAM pOnBadIndex
// pOnBadIndex: called in case of array index out of bounds

END_SUBPROGRAM

