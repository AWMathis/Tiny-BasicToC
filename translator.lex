%{
	
/**
	@author Alexander Mathis
	
	Purpose: This lex program will generate input tokens based on recieved input. The yylval of each input is set to it's string(number 1 = "1" not int 1)
	Date: 11/29/2017
*/

#include <stdio.h>
#include "y.tab.h"

int c;
extern YYSTYPE yylval;
%}

%%

" ";

PRINT {
	return(BASIC_PRINT);
}

IF {
	return(BASIC_IF);
}
GOTO {
	return(BASIC_GOTO);
}
INPUT {
	return(BASIC_INPUT);
}
LET {
	return(BASIC_LET);
}
END {
	return(BASIC_END);
}

THEN {
	return(BASIC_THEN);
}


[ \t]+ {
	
}

[0-9][0-9]* {
  c = yytext[0];
  yylval.str = strdup(yytext);
  return(INTEGER);
}

[0-9][\.][0-9]+ {
  c = yytext[0];
  yylval.str = strdup(yytext);
  return(DECIMAL);
}

[A-Z] {
  c = yytext[0];
  yylval.str = strdup(yytext);
  return(VAR);
}

[<|<=|>|>=|=|!][=]+ {
  yylval.str = strdup(yytext);
  return(RELOP);
}

[<|>] {
  yylval.str = strdup(yytext);
  return(RELOP);
}

[^a-z0-9\b] {
  c = yytext[0];
  return(c);
}


%%