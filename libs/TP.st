FUNCTION_BLOCK TP
VAR_INPUT
IN : BOOL := FALSE ;
PT : TIME := 0 ;
END_VAR

VAR_OUTPUT
Q : BOOL := FALSE  ;
ET : TIME := 0  ;
END_VAR

  IF (NOT IN AND NOT Q) THEN
    Q := FALSE ;
    ET := T# 0 ms ;
    @#timerSetValue(T# 0 ms) ;
  END_IF ;

  IF IN  THEN
    Q := TRUE ;
    ET := @#timerValue ;
  END_IF ;

  IF (@#timerValue >= PT ) THEN
    ET := PT ;
    Q := FALSE ;
    END_IF ;

END_FUNCTION_BLOCK