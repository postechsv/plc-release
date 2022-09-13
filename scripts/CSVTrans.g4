grammar CSVTrans ;

import COMMON ;

start : 'StreamMap' '-->' outputresult (',' outputresult)* 'RESULT:checkSATResult' '-->' intputresult (intputresult)* 'KTPS:KeyTypePairSet' '-->' typeresult (typeresult)* ;

outputresult : '(' outputresult ')' # PARENTHESIS
             | functionblock '::' varname '|->' numdatas # OUTPUTNUM
             | functionblock '::' varname '|->' booldatas # OUTPUTBOOL
             | functionblock '::' varname '|->' exprs # OUTPUTEXPR
             ;

intputresult : '(' functionblock '::' varname '--' step=INT ')' '||-->' semanticValuesNum # INPUTNUM
            | '(' functionblock '::' varname '--' step=INT ')' '||-->' semanticValuesBoolean # INPUTBOOL
            | 'FVAR--' INT '||-->' semanticValuesBoolean # FRESHVARPART
            | 'SAT' # EMPTYINPUT
            | 'emptyAssignment' # EMPTYINPUT ;

typeresult : '(' functionblock '::' varname 'is' dataType=TYPE ')' # TYPEDATA
           | functionblock '::' varname 'is' dataType=TYPE # TYPEDATA
           | 'emptyKTPS' # EMPTYTYPE ;



functionblock : '\'' name=ID ;
varname : '(' '\'' name=ID ('.' '\'' names=ID)+ ')'  # NAMELIST
         | '\'' name=ID # SINGLENAME ;

semanticValuesNum : '(' number ').Integer' | '(' number ').NzNat' | '(' number ').NzInt' | '(' number ').Real' | '(' number ').Zero' | number ;
semanticValuesBoolean : '(' data=TRUE ').Bool' | '(' data=FALSE ').Bool' | '(' data=TRUE ').Boolean' | '(' data=FALSE ').Boolean' |  data=(TRUE|FALSE) ;
symbolicValues : symblocvarType=('i'|'b'|'r')'(' functionblock '::' varname '--' step=INT ')' ;

expr : '(' expr ')' # PARENTHESISEXPR
     | SUB expr # NEGATIVEOPERATION
     | NOT expr # NOTOPERATION
     | <assoc=right> expr op=EXPO expr # EXPONENTIAL
     | expr op=(MULT | DIV | MOD) expr # NUMERICALOPERATION
     | expr op=(ADD|SUB) expr # NUMERICALOPERATION
     | expr op=(COMPARISON|EQUAL|INEQUAL) expr # COMPARISON
     | expr op=(AND|XOR|OR) expr # LOGICALBINARY
     | semanticValuesBoolean # PRIMARYEXPR
     | semanticValuesNum # PRIMARYEXPR
     | symbolicValues # PRIMARYSYMBOLICEXPR
     ;



number : (INT|FLOAT|FRACTION) ;

numdatas : '[' semanticValuesNum ']' (',' '[' semanticValuesNum ']')+ | '[' semanticValuesNum ']' ;
booldatas : '[' semanticValuesBoolean ']' (',' '[' semanticValuesBoolean ']')+ | '[' semanticValuesBoolean ']' ;
exprs : '[' expr ']' (',' '[' expr ']')+ | '[' expr ']' ;

MOD : '%' ;
EQUAL : '====' ;
USELESS : .*? 'STRMAP:' -> skip ;
WSAPPEND : '///' -> skip ;