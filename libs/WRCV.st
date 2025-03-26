FUNCTION_BLOCK URCV
VAR_INPUT
ENR : BOOL;
ID : STRING := "";
RID : STRING := "";
END_VAR

VAR_OUTPUT
NDR : BOOL := FALSE ;
ERROR : BOOL := FALSE ;
STATUS : DINT := 0 ;
DATA : ANY := 0;
END_VAR

VAR
THIS : STRING ;
RESULT : ANY ;
END_VAR

  IF NDR THEN
    NDR := FALSE ;
    ERROR := FALSE ;
    STATUS := 0 ;
  END_IF ;

  IF isConnected(ID) = FALSE THEN
    ERROR := TRUE ;
    STATUS := 1 ;
    RETURN ;
  END_IF ;


  THIS := thisBlock ;
  RESULT := wrcvData(ID, RID, THIS) ;

  IF RESULT <> rcvError THEN
    NDR := TRUE ;
    ERROR := FALSE ;
    STATUS := 0 ;
    DATA := RESULT ;
  ELSE
    NDR := FALSE ;
    ERROR := TRUE ;
    STATUS := 1 ;
  END_IF ;

END_FUNCTION_BLOCK
