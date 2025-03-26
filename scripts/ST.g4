grammar ST ;

import COMMON ;

stapp : config (pros|subs|udfbs|funcs)* ;

config : programSection cycletime typeSection (var_global)? ;

programSection : PROGRAMS  (aProgram)+ PROGRAMSEND ;
aProgram : name=ID ';;' ;
cycletime : CycleTime ':' cycle=INT ;

typeSection : TYPESTART enum* bitfield* structure* ENDTYPE ;
enum : name=ID ':' enumVar=idList ';' ;
bitfield : name=ID ':' varType=TYPE ':' fieldVar=idList ';' ;
structure: name=ID ':' STRUCT varDecl*  END_STRUCT ;

var_priv : VAR varDecl* END_VAR ;
var_in : VAR_INPUT varDecl* END_VAR ;
var_in_out : VAR_IN_OUT varDecl* END_VAR ;
var_out : VAR_OUTPUT varDecl* END_VAR ;
var_global : VAR_GLOBAL varDecl* END_VAR ;


stappTypes : arrayType | TYPE | ID ;
arrayType : ARRAY '[' INT '..' dim=INT ']' OF varType=(TYPE|ID) ;


varDecl : name=ID ':' stappTypes ':=' listInitVar ';' # YESINITDECL
        | name=ID ':' stappTypes ';' # NOINITDECL ;

var_decl_collection : (var_priv | var_in | var_in_out | var_out)* ;

pros : PROGRAM name=ID var_decl_collection program END_PROGRAM ;
subs : SUBPROGRAM name=ID var_decl_collection program END_SUBPROGRAM ;
udfbs : FUNCTION_BLOCK name=ID var_decl_collection program END_FUNCTION_BLOCK ;
funcs : FUNCTION name=ID ':' returntype=TYPE var_decl_collection program END_FUNCTION ;

program : (statement ';')* ;

statementList :  (statement ';')+ ;

statement : assign | functioncall | iteration | selection | opwithequal | exitstatement | returnstatement | emptystatement ;

assign : expr ':=' expr ;
functioncall : (varname) '(' argumentlist ')' # USERDEFINEFUNCALL
             | funcall=(SPECIALTIMEFUN|SPECIALTIMEFUNWAIT|SPECIALTIMEFUNWAITTIME|SPECIALCOMMFUN) '(' argumentlist ')' # STANDARDFUNCALL ;

iteration : FOR assign TO expr BY expr DO statementList ENDFOR # FORSTATEMENTWITHBY
          | FOR assign TO expr DO statementList ENDFOR # FORSTATEMENT
          | WHILE expr DO statementList ENDWHILE # WHILESTATEMENT
          | REPEAT statementList UNTIL expr ENDREPEAT # REPEATSTATEMENT
          ;

selection : IF expr THEN statementList (ELSEIF expr THEN statementList)* (ELSE statementList)? ENDIF # IFSTATEMENT
          | CASE expr OF caseoptionline+ ENDCASE # CASESTATEMENT
          | CASE expr OF caseoptionline+ ELSE statementList ENDCASE # CASESTATEMENTWITHELSE
          ;

caseoption : primary
           | primary (',' primary)*
           | primary '...' primary
           ;

caseoptionline : caseoption ':' statementList ;

opwithequal : expr (op=ADD EQUAL | op=SUB EQUAL | op=MULT EQUAL) expr ;

exitstatement : EXIT ;
returnstatement : RETURN;
emptystatement : ;

expr : '(' expr ')' # PARENTHESIS
     | op=(ARITHMETICBUILTINFUNCTIONS|DATACONVERSIONBUILTINFUNCTIONS|'isConnected'|'sendData'|'rcvData'|'wrcvData') '(' argumentlist ')' # FUNCTIONCALL
     | SUB expr # NEGATIVEOPERATION
     | NOT expr # NOTOPERATION
     | <assoc=right> expr op=EXPO expr # EXPONENTIAL
     | expr op=(MULT | DIV | MOD) expr # NUMERICALOPERATION
     | expr op=(ADD|SUB) expr # NUMERICALOPERATION
     | expr op=(COMPARISON|EQUAL|INEQUAL) expr # COMPARISON
     | expr op=(AND|XOR|OR) expr # LOGICALBINARY
     | primary # PRIMARYEXPR
     | varname '[' expr ']' # ARRAYEXPR
     ;

assignargument : varname ':=' expr # ONETOONE
        | '(' assignargument ')' # ONTTOONPARENTHESIS
        ;

argumentlist : assignargument (',' assignargument)* # ONETOONELIST
             | expr (',' expr)* # ARGLIST
             ;

primary : number # NUMPRIMARY
        | 't#' number ms=ID # TIMEPRIMARY
        | 'T#' number ms=ID # TIMEPRIMARY
        | TRUE # BOOLTRUE
        | FALSE # BOOLFALSE
        | varname # VARPRIMARY
        | ID '#' ID # ENUMPRIMARY
        | string # STRINGPRIMARY
        | (SPECIALTIMEKEYWORD | SPECIALCYCLEKEYWORD | SPECIALCOMMKEYWORD) # SPECIALTOKEN
        ;

varname : ID ('.' (ID|INT))+  | ID ;

number : (INT|FLOAT|FRACTION) ;
timeval : ('t#' timesize=INT ms=ID | 'T#' INT ms=ID) ;
string : '"'ID'"' ;

listInitVar : number (',' number)*
            | (TRUE|FALSE) (',' (TRUE|FALSE))*
            | timeval (',' timeval)*
            | idList ;

idList : ID (',' ID)* ;


PROGRAMS : 'PROGRAMS' ;
PROGRAMSEND : 'PROGRAMSEND' ;
CycleTime : 'CycleTime' ;
TYPESTART : 'TYPE' ;
ENDTYPE : 'END_TYPE' ;
STRUCT : 'STRUCT' ;
END_STRUCT : 'END_STRUCT' ;

PROGRAM : 'PROGRAM';
END_PROGRAM : 'END_PROGRAM';
FUNCTION_BLOCK : 'FUNCTION_BLOCK' ;
END_FUNCTION_BLOCK : 'END_FUNCTION_BLOCK' ;
FUNCTION : 'FUNCTION' ;
END_FUNCTION : 'END_FUNCTION' ;
SUBPROGRAM : 'SUBPROGRAM';
END_SUBPROGRAM : 'END_SUBPROGRAM';

VAR : 'VAR' ;
VAR_INPUT : 'VAR_INPUT' ;
VAR_OUTPUT : 'VAR_OUTPUT' ;
VAR_IN_OUT : 'VAR_IN_OUT' ;
VAR_GLOBAL : 'VAR_GLOBAL' ;
END_VAR : 'END_VAR' ;

SPECIALTIMEFUN : '@#timerSetValue' ;
SPECIALTIMEKEYWORD : '@#timerValue' ;
SPECIALCYCLEKEYWORD : '@#cycleValue' ;
SPECIALCOMMFUN : 'connectRequest' | 'disconnect' ; 
SPECIALCOMMKEYWORD : 'rcvError' | 'thisBlock' | 'boolUserInput' ; 
SPECIALTIMEFUNWAIT : 'WAIT' ;
SPECIALTIMEFUNWAITTIME : 'WAIT_TIME' ;

EQUAL : '=' ;

ARRAY : 'ARRAY' ;

COMMENT : ('(*' .*? '*)' | '//' .*? '\n') -> skip ;


