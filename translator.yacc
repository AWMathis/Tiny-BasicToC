%{

/**
	@author Alexander Mathis
	
	Purpose: This yacc program will take input tokens and a text file input.txt and output C code equivalent to the tiny basic code in input.txt
	Date: 11/29/2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double regs[26];
char buffer[256];
char buffer2[256];
double base;
int yylex();
int yyerror(char *s);
int yywrap();
int yydebug=1; //Allows outputting information for debugging
FILE *yyin;
%}

%start block
%union {
  int a;
  char c;
  double d;
  char *str;
}
%type <str> RELOP number statement expression exprlist term varlist exprlist factor VAR INTEGER DECIMAL
%token LETTER INTEGER VAR DECIMAL RELOP BASIC_PRINT BASIC_IF BASIC_GOTO BASIC_INPUT BASIC_LET BASIC_END BASIC_THEN
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%' '(' ')'
%left UMINUS

%%

list: /* empty */
    | list block '\n'
	| list block '\r' '\n'
    | list error '\n' {
      yyerrok;
    };

//Allows input of multiple statements
block:	block line
		| line

//Allows use of an integer before statements to provide a lable to go back to
//Prints the string of the given statement
line:	INTEGER statement '\n' {
			printf("g%s:\n", $1); //Print label so it can be used to goto
			printf("%s\n", $2); //Print returned value of statement
		}
		| statement '\n' {
			printf("%s\n", $1); //Print returned value of statement
		};

//Each statement returns a string containing it's C code.
statement:	BASIC_PRINT exprlist{
				$$ = $2; //Return contents of $2 
			}
			| BASIC_IF expression RELOP expression BASIC_THEN  statement {
				snprintf(buffer, 100, "if (%s%s%s) { %s }\n", $2, $3, $4, $6); //Store a string in buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
			}
			| BASIC_GOTO expression {
				snprintf(buffer, 100, "goto g%s;\n", $2); //Store a string in buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
			}
			| BASIC_INPUT varlist {
				$$ = $2; //Return contents of $2
			}	
			| BASIC_LET VAR '=' expression {
				snprintf(buffer, 100, "%s = %s;\n", $2, $4); //Store a string in buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
				
			}
			| BASIC_END {
				snprintf(buffer, 100, "return 0;\n"); //Store a string in buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
			};
			
//Exprlist gives c code that will print each given expression
exprlist:	exprlist ',' expression {
				snprintf(buffer, 100, "printf(\"%%g\\n\", (double)%s);\n", $3); //Store a string in buffer
				strcat($1, buffer); //Append contents of buffer to $1
				$$ = strdup($1); //Return contents of $1 (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
			}
			| expression {
				snprintf(buffer, 100, "printf(\"%%g\\n\", (double)%s);\n", $1); //Store a string in buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
			};

			
//Gives C code that will ask for values for each given VAR
varlist:	varlist ',' VAR {
				strcpy(buffer, $1); //Copy values in $1 to buffer
				snprintf(buffer2, 100, "printf(\"Enter value for %s: \");\n", $3); //Store a string in buffer2
				strcat(buffer, buffer2); //Append contents of buffer2 to buffer
				buffer2[0] = '\0';  //Clear buffer to prevent potential errors
				snprintf(buffer2, 100, "scanf(\"%%lf\", &%s );\n" , $3); //Store a string in buffer2
				strcat(buffer, buffer2); //Append contents of buffer2 to buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
				buffer2[0] = '\0'; //Clear buffer to prevent potential errors
				
			}
			| VAR {
				snprintf(buffer, 100, "printf(\"Enter value for %s: \");\n", $1); //Store a string in buffer
				snprintf(buffer2, 100, "scanf(\"%%lf\", &%s );\n" , $1); //Store a string in buffer2
				strcat(buffer, buffer2); //Append contents of buffer2 to buffer
				$$ = strdup(buffer);//Return contents of buffer (duplicated so they aren't changed later)
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
				buffer2[0] = '\0'; //Clear buffer to prevent potential errors
			
				
			};
//Merges expressions and terms with a + or - in between
expression:	expression '+' term {
				snprintf(buffer, 2, "+"); //Store a string in buffer
				strcat($1, buffer); //Append contents of buffer to $1
				strcat ($1, $3); //Append contents of $3 to $1
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
				$$ = $1;//Return contents of $1 (duplicated so they aren't changed later)
			}
			| expression '-' term {
				snprintf(buffer, 2, "-"); //Store a string in buffer
				strcat($1, buffer); //Append contents of buffer to $1
				strcat ($1, $3); //Append contents of $3 to $1
				buffer[0] = '\0'; //Clear buffer to prevent potential errors
				$$ = $1;//Return contents of $1 (duplicated so they aren't changed later)
			}
			| term;
//Merges expressions and terms with a * or / in between
term:	term '*' factor {
			snprintf(buffer2, 2, "*"); //Store a string in buffer2
			strcat($1, buffer2); //Append contents of buffer2 to $1
			strcat ($1, $3); //Append contents of $3 to $1
			$$ = strdup($1);//Return contents of $1 (duplicated so they aren't changed later)
			buffer2[0] = '\0'; //Clear buffer to prevent potential errors
		}
		| term '/' factor {
			snprintf(buffer2, 2, "/"); //Store a string in buffer2
			strcat($1, buffer2); //Append contents of buffer2 to $1
			strcat ($1, $3); //Append contents of $3 to $1
			$$ = strdup($1); //Return contents of $1 (duplicated so they aren't changed later)
			buffer2[0] = '\0'; //Clear buffer to prevent potential errors
		}
		| factor;

//Returns string value of given VAR or number, can also add parenthases around an expression
//ALL factors and higher are strings
factor:	VAR {
			$$ = $1; //Return contents of $1
		}
		| number {
			$$ = $1;  //Return contents of $1
		}
		| '(' expression ')' {
			snprintf(buffer, 100, "(%s)\n", $2); //Store a string in buffer
			$$ = strdup(buffer); //Return contents of buffer (duplicated so they aren't changed later)
			buffer[0] = '\0'; //Clear buffer to prevent potential errors
		};

//Returns string value of given input
number: INTEGER {
          $$ = $1; //Return contents of $1
        }
      | number INTEGER
	  | DECIMAL {
		$$ = $1;  //Return contents of $1
		}
	  | number DECIMAL;

	
%%

int main() {

	//Prints header info for output C program incluing dependencies, main(), and variables
	printf("#include <stdio.h>\n");
	printf("int main() {\n");
	printf("double A=0, B=0, C=0, D=0, E=0, F=0, G=0, H=0, I=0, J=0, K=0, L=0, M=0, N=0, O=0, P=0, Q=0, R=0, S=0, T=0, U=0, V=0, W=0, X=0, Y=0, Z=0;\n");
  
	//Open and parse the given file
	yyin = fopen("input.txt", "r");
	yyparse();
	fclose(yyin);
	printf("}\n");
	return 0;
}

int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 1;
}

int yywrap() {
  return 1;
}