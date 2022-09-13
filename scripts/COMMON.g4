lexer grammar COMMON ;

TRUE : 'true'|'TRUE' ;
FALSE : 'false'|'FALSE' ;

NOT : 'not'|'NOT' ;

EXPO : '**' ;
MULT : '*' ;
DIV : '/' ;
MOD : 'MOD' ;
ADD : '+' ;
SUB : '-' ;

COMPARISON : '>'|'<'|'>='|'<=' ;
INEQUAL : '<>' ;

AND : '&' | 'and' | 'AND' ;
XOR : 'xor'|'XOR' ;
OR : 'or'|'OR' ;

TYPE : 'BOOL' | 'SINT' | 'REAL' | 'USINT' | 'BYTE' | 'INT' | 'UINT' | 'WORD' | 'DINT' | 'UDINT'
     | 'DWORD' | 'LINT' | 'LREAL' | 'TIME' | 'STRING' ;

ARITHMETICBUILTINFUNCTIONS : 'LIMIT'|'MAX'|'MIN'|'ODD'|'MUX4'|'MUX8'|'SEL'|'RAND'
                           | 'ABS'|'EXP'|'EXPT'|'LOG'|'LN'|'POW'|'ROOT' | 'SQRT' |'ScaleLIn'|'TRUNC'
                           | 'SIN' | 'COS' | 'TAN' | 'ASIN' | 'ACOS' | 'ATAN'
                           ;

DATACONVERSIONBUILTINFUNCTIONS : 'ANY_TO_TIME'|'ANY_TO_BOOL'|'ANY_TO_SINT'|'ANY_TO_INT'|'ANY_TO_LINT'|'ANY_TO_REAL'|'ANY_TO_LREAL'
                               | 'ANY_TO_STRING'|'NUM_TO_STRING'|'UDINT_TO_DINT'|'DINT_TO_UDINT'|'BOOL_TO_UDINT'|'BOOL_TO_DINT'
                               | 'DINT_TO_DINT'|'ANY_TO_DINT'
                               ;

FOR : 'for'|'FOR' ;
TO : 'to'|'TO';
BY : 'by' | 'BY' ;
DO : 'do' | 'DO' ;
ENDFOR : 'end_for'|'END_FOR';

WHILE : 'while'|'WHILE' ;
ENDWHILE : 'end_while' | 'END_WHILE' ;

REPEAT : 'repeat' | 'REPEAT';
UNTIL : 'until' | 'UNTIL ' ;
ENDREPEAT : 'end_repeat' | 'END_REPEAT' ;

IF : 'if' | 'IF' ;
THEN : 'then' | 'THEN' ;
ELSEIF : 'elsif' | 'ELSIF' ;
ELSE : 'else' | 'ELSE' ;
ENDIF : 'end_if' | 'END_IF' ;

CASE : 'case' | 'CASE' ;
OF : 'of' | 'OF' ;
ENDCASE : 'end_case' | 'END_CASE' ;

EXIT : 'exit'|'EXIT';
RETURN : 'return'|'RETURN' ;


INT : DIGIT+ | SUB DIGIT+  ;
FLOAT : DIGIT+ '.' DIGIT+ | SUB DIGIT+ '.' DIGIT+ ;
FRACTION : INT DIV INT ;


ID : ID_LETTER (ID_LETTER|DIGIT)* ;

WS : (' '|'\t'|'\r'|'\n')+ -> skip ;


fragment ID_LETTER : 'a'..'z'|'A'..'Z'|'_' ;
fragment DIGIT : '0'..'9' ;