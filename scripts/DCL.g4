grammar DCL ;

import COMMON ;

start : ';K5 project' apart* '</A,end>' tpart* '</T,end>' ppart* '</P,end>' '/G,GLOBAL' '/G,RETAIN' '</G,end>' vpart* ;
local : vpart* ;


apart : '/A,' '<' INT '>' (INT (',' INT)+ ','?) # USELESSAPART
      | '/A,' '<' INT '>' (ID)+ # USELESSAPART
      | '/A,' '<' check=INT '>' cycletime=INT # CYCLEPART;

tpart : '/T,' 'ENUM:' enumname=ID '=' varnamelist # ENUMPART
      | '/T,' 'BITFIELD:' bitfieldname=ID '=' fieldtype=TYPE ':' varnamelist # BITFIELDPART ;

ppart : '/P,' name=ID ',' ('T'|'F') ',' ('E'|'B') ('/P,' '<' INT '>' '#' switch=(TRUE|FALSE) '#')? ('/P,' '<' INT '>' '%' period=INT '=' phase=INT)? # MAINPARGRAM
      | '/P,' name=ID ',' ('T'|'F') ',' ('E'|'B') ('/P,' '<' INT '>' 'OnCall') # SUBPROGRAM
      | '/P,' name=ID ',' 'T' ',' 'U' '/P,' '<' INT '>' '#' switch=(TRUE|FALSE) '#' # UDFB
      | '/P,' name=ID ',' 'T' ',' 'U' '/P,' '<' INT '>' 'Struct' # STRUCTURE
      ;

vpart : '/V,' position=('G,'|'L,') typename=(TYPE|ID) '(0)' '[' dimension=INT ']' ',' varUsageType=INT ',' variablename=ID ('/V,=' numdatas )? # VARDECLINITNUM
      | '/V,' position=('G,'|'L,') typename=(TYPE|ID) '(0)' '[' dimension=INT ']' ',' varUsageType=INT ',' variablename=ID ('/V,=' booldatas)? # VARDECLINITBOOL
      | '/V,' position=('G,'|'L,') typename=(TYPE|ID) '(0)' '[' dimension=INT ']' ',' varUsageType=INT ',' variablename=ID ('/V,=' timedatas)? # VARDECLTIME
      | '/V,' '<' INT '>' ID # USELESSVPART ;


varnamelist : ID (',' ID)+ | ID ;

numdatas : (INT|FLOAT|FRACTION) (',' (INT|FLOAT|FRACTION))+ | (INT|FLOAT|FRACTION) ;
booldatas : (TRUE|FALSE) (',' (TRUE|FALSE))+ | (TRUE|FALSE) ;

number : (INT|FLOAT|FRACTION) ;
timedatas :  ('t#' timesize=INT ms=ID |'T#' timesize=INT ms=ID) (',' ('t#' timesize=INT ms=ID |'T#' timesize=INT ms=ID)+)
            | ('t#' timesize=INT ms=ID |'T#' timesize=INT ms=ID) ;

