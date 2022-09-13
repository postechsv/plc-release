FUNCTION_BLOCK TON
VAR_INPUT
IN : BOOL := FALSE ;
PT : TIME := 0 ;
END_VAR

VAR_OUTPUT
Q : BOOL := FALSE ;
ET : TIME := 0 ;
END_VAR

VAR
H : BOOL := FALSE ;
END_VAR

  IF NOT IN OR NOT H THEN
    Q  :=  FALSE ;
    ET  :=  T# 0 ms ;
    @#timerSetValue(T# 0 ms) ;
  ELSE
     IF @#timerValue >= PT THEN
      ET  :=  PT ;
      Q  :=  TRUE ;
      ELSE
      ET  :=  @#timerValue ;
    END_IF ;
  END_IF ;

  H := IN ;

END_FUNCTION_BLOCK
