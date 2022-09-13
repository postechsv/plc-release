grammar REQ ;

import COMMON ;

start : 'INPUT:' inputpart+ 'STEP:' steppart 'CONDITION:' expr # STEPYES
       | 'INPUT:' inputpart+ 'CONDITION:' expr # STEPNO ;

inputpart : functionblock '::' varname '|->' '??' # SYMBOLIC
          | functionblock '::' varname '|->' 'repeat' '(' numdatas')' # REPEATNUM
          | functionblock '::' varname '|->' 'repeat' '(' booldatas')' # REPEATBOOL
          | functionblock '::' varname'|->' numdatas # CONCRETENUM
          | functionblock '::' varname '|->' booldatas # CONCRETEBOOL
          | 'empty' # EMPTY ;

steppart :  stepsize=INT # STEPPPARTNUM
          | stepsize=ID # STEPPARTID ;

expr : op=(NOT|TEMPERALLOGIC) '(' expr ')' # UNARY
     | expr op=(UNTIL|EQUAL|MULT|DIV|MOD|ADD|SUB|AND|XOR|OR|COMPARISON|INEQUAL|IMPLICATION|COMPARISON) expr # BINARY
     | '(' expr ')' # PARENTHESIS
     | functionblock '::' varname # VARNAME
     | 'I[' functionblock '::' varname ']' # VARNAME
     | functionblock '::' varname '{' index=INT '}' # VARNAMEINDEX
     | 'I[' functionblock '::' varname ']' '{' index=INT '}' # VARNAMEINDEX
     | (INT|FLOAT|FRACTION) # BASICNUM
     | TRUE # BASICTRUE
     | FALSE # BASICFALSE ;


functionblock : ID ;
varname : '(' ID ('.' ID)+ ')' | ID ;
numdatas : number (',' number)+ # NUMDATA
            | number # NUMDATA
            | timeval (',' timeval)+ # TIMEDATA
            | timeval # TIMEDATA ;
number : INT ;
timeval : ('t#' number ms=ID | 'T#' number ms=ID) ;
booldatas : (TRUE|FALSE) (',' (TRUE|FALSE))+ | (TRUE|FALSE) ;

EQUAL : '==' ;
IMPLICATION : '==>' ;
TEMPERALLOGIC : 'FINALLY'|'GLOBALLY'|'NEXT'|'WNEXT' ;