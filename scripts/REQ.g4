grammar REQ ;

import COMMON ;

start : 'INPUT:' inputpart+ 'BOUND:' bound 'ADAPTER:' amap+ 'CONDITION:' expr # REQUIREMENT ;

inputpart : pname '::' varname '|->' 'repeat' '(' numdatas')' # REPEATNUM
          | pname '::' varname '|->' 'repeat' '(' booldatas')' # REPEATBOOL
          | pname '::' varname'|->' numdatas # CONCRETENUM
          | pname '::' varname '|->' booldatas # CONCRETEBOOL
          | 'empty' # EMPTY ;

bound : b=INT # BOUND
      | b=ID # INFBOUND ;

expr : op=(NOT|TEMPERALLOGIC) '(' expr ')' # UNARY
     | expr op=(UNTIL|EQUAL|MULT|DIV|MOD|ADD|SUB|AND|XOR|OR|COMPARISON|INEQUAL|IMPLICATION|COMPARISON) expr # BINARY
     | '(' expr ')' # PARENTHESIS
     | pname '::' varname # VARNAME
     | 'I[' pname '::' varname ']' # VARNAME
     | pname '::' varname '{' index=INT '}' # VARNAMEINDEX
     | 'I[' pname '::' varname ']' '{' index=INT '}' # VARNAMEINDEX
     | (INT|FLOAT|FRACTION) # BASICNUM
     | TRUE # BASICTRUE
     | FALSE # BASICFALSE ;

amap : pname '|->' adapter '/' denominator=INT ;

adapter : 'first' | 'last' | 'min' | 'max' ;

pname : ID ;
varname : '(' ID ('.' ID)+ ')' | ID ;
numdatas : number (',' number)+ # NUMDATA
            | number # NUMDATA
            | timeval (',' timeval)+ # TIMEDATA
            | timeval # TIMEDATA ;
number : INT | '??' ;
bools : TRUE | FALSE | '??' ;
timeval : ('t#' number ms=ID | 'T#' number ms=ID | '??') ;
booldatas : bools (',' bools)+ | bools ;

EQUAL : '==' ;
IMPLICATION : '==>' ;
TEMPERALLOGIC : 'FINALLY'|'GLOBALLY'|'NEXT'|'WNEXT' ;
