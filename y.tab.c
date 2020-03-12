/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "translator.yacc"

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
int yydebug=1; /*Allows outputting information for debugging*/
FILE *yyin;
#line 24 "translator.yacc"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int a;
  char c;
  double d;
  char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define RELOP 257
#define VAR 258
#define INTEGER 259
#define DECIMAL 260
#define LETTER 261
#define BASIC_PRINT 262
#define BASIC_IF 263
#define BASIC_GOTO 264
#define BASIC_INPUT 265
#define BASIC_LET 266
#define BASIC_END 267
#define BASIC_THEN 268
#define UMINUS 269
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    8,    8,    8,    8,    0,    0,    9,    9,    2,    2,
    2,    2,    2,    2,    4,    4,    6,    6,    3,    3,
    3,    5,    5,    5,    7,    7,    7,    1,    1,    1,
    1,
};
static const YYINT yylen[] = {                            2,
    0,    3,    4,    3,    2,    1,    3,    2,    2,    6,
    2,    2,    4,    1,    3,    1,    3,    1,    3,    3,
    1,    3,    3,    1,    1,    1,    3,    1,    2,    1,
    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,   14,    0,    0,    6,
    0,   25,   28,   30,    0,    0,    0,    0,    0,   24,
    0,    0,   18,    0,    0,    5,    8,    7,    0,   29,
   31,    0,    0,    0,    0,    0,    0,    0,    0,   27,
    0,    0,    0,   22,   23,    0,   17,    0,    0,   10,
};
static const YYINT yydgoto[] = {                          8,
   16,    9,   17,   18,   19,   24,   20,    0,   10,
};
static const YYINT yysindex[] = {                      -243,
 -196,  -38,  -38,  -38, -248, -240,    0, -243,   34,    0,
   43,    0,    0,    0,  -38, -234,  -32,   15,  -33,    0,
  -39,  -32,    0,   20,   -4,    0,    0,    0,   13,    0,
    0,  -38,  -38,  -38,  -38,  -38,  -38, -186,  -38,    0,
  -33,  -33,  -32,    0,    0,  -42,    0,  -32, -196,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -10,   -2,   63,   -5,    0,
    0,   64,    0,   65,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,    7,    5,    0,    0,    0,    0,   66,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    6,   26,    0,   29,    0,   -8,    0,   69,
};
#define YYTABLESIZE 275
static const YYINT yytable[] = {                         26,
   32,   15,   33,   32,   21,   33,   11,   16,   35,   23,
   32,   19,   33,   36,   15,    1,   20,   25,    2,    3,
    4,    5,    6,    7,   30,   31,   44,   45,   21,   22,
   26,   26,   26,   26,   26,   21,   26,   21,   21,   21,
   29,   16,   19,   27,   19,   19,   19,   20,   15,   20,
   20,   20,   28,   40,   50,   32,   39,   33,   34,   43,
   41,   42,   46,   38,   48,    2,    3,    4,    5,    6,
    7,   47,    9,   11,   12,   13,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   37,    0,   12,
   13,   14,    0,    0,    0,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,   21,    0,    0,    0,    0,    0,   26,   19,    0,
    0,    0,   21,   20,    0,    0,    0,    0,    0,   19,
    0,    0,    0,    0,   20,
};
static const YYINT yycheck[] = {                         10,
   43,   40,   45,   43,   10,   45,    1,   10,   42,  258,
   43,   10,   45,   47,   10,  259,   10,  258,  262,  263,
  264,  265,  266,  267,  259,  260,   35,   36,    3,    4,
   41,   42,   43,   44,   45,   41,   47,   43,   44,   45,
   15,   44,   41,   10,   43,   44,   45,   41,   44,   43,
   44,   45,   10,   41,   49,   43,   61,   45,   44,   34,
   32,   33,   37,   44,   39,  262,  263,  264,  265,  266,
  267,  258,   10,   10,   10,   10,    8,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  258,
  259,  260,   -1,   -1,   -1,  268,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,
   -1,  257,   -1,   -1,   -1,   -1,   -1,  268,  257,   -1,
   -1,   -1,  268,  257,   -1,   -1,   -1,   -1,   -1,  268,
   -1,   -1,   -1,   -1,  268,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 281
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,"'\\r'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,
0,0,0,0,0,0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"RELOP","VAR","INTEGER","DECIMAL","LETTER","BASIC_PRINT",
"BASIC_IF","BASIC_GOTO","BASIC_INPUT","BASIC_LET","BASIC_END","BASIC_THEN",
"UMINUS",0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : block",
"list :",
"list : list block '\\n'",
"list : list block '\\r' '\\n'",
"list : list error '\\n'",
"block : block line",
"block : line",
"line : INTEGER statement '\\n'",
"line : statement '\\n'",
"statement : BASIC_PRINT exprlist",
"statement : BASIC_IF expression RELOP expression BASIC_THEN statement",
"statement : BASIC_GOTO expression",
"statement : BASIC_INPUT varlist",
"statement : BASIC_LET VAR '=' expression",
"statement : BASIC_END",
"exprlist : exprlist ',' expression",
"exprlist : expression",
"varlist : varlist ',' VAR",
"varlist : VAR",
"expression : expression '+' term",
"expression : expression '-' term",
"expression : term",
"term : term '*' factor",
"term : term '/' factor",
"term : factor",
"factor : VAR",
"factor : number",
"factor : '(' expression ')'",
"number : INTEGER",
"number : number INTEGER",
"number : DECIMAL",
"number : number DECIMAL",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 186 "translator.yacc"

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
#line 319 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 43 "translator.yacc"
	{
      yyerrok;
    }
break;
case 7:
#line 53 "translator.yacc"
	{
			printf("g%s:\n", yystack.l_mark[-2].str); /*Print label so it can be used to goto*/
			printf("%s\n", yystack.l_mark[-1].str); /*Print returned value of statement*/
		}
break;
case 8:
#line 57 "translator.yacc"
	{
			printf("%s\n", yystack.l_mark[-1].str); /*Print returned value of statement*/
		}
break;
case 9:
#line 62 "translator.yacc"
	{
				yyval.str = yystack.l_mark[0].str; /*Return contents of $2 */
			}
break;
case 10:
#line 65 "translator.yacc"
	{
				snprintf(buffer, 100, "if (%s%s%s) { %s }\n", yystack.l_mark[-4].str, yystack.l_mark[-3].str, yystack.l_mark[-2].str, yystack.l_mark[0].str); /*Store a string in buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
			}
break;
case 11:
#line 70 "translator.yacc"
	{
				snprintf(buffer, 100, "goto g%s;\n", yystack.l_mark[0].str); /*Store a string in buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
			}
break;
case 12:
#line 75 "translator.yacc"
	{
				yyval.str = yystack.l_mark[0].str; /*Return contents of $2*/
			}
break;
case 13:
#line 78 "translator.yacc"
	{
				snprintf(buffer, 100, "%s = %s;\n", yystack.l_mark[-2].str, yystack.l_mark[0].str); /*Store a string in buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
				
			}
break;
case 14:
#line 84 "translator.yacc"
	{
				snprintf(buffer, 100, "return 0;\n"); /*Store a string in buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
			}
break;
case 15:
#line 91 "translator.yacc"
	{
				snprintf(buffer, 100, "printf(\"%%g\\n\", (double)%s);\n", yystack.l_mark[0].str); /*Store a string in buffer*/
				strcat(yystack.l_mark[-2].str, buffer); /*Append contents of buffer to $1*/
				yyval.str = strdup(yystack.l_mark[-2].str); /*Return contents of $1 (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
			}
break;
case 16:
#line 97 "translator.yacc"
	{
				snprintf(buffer, 100, "printf(\"%%g\\n\", (double)%s);\n", yystack.l_mark[0].str); /*Store a string in buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
			}
break;
case 17:
#line 105 "translator.yacc"
	{
				strcpy(buffer, yystack.l_mark[-2].str); /*Copy values in $1 to buffer*/
				snprintf(buffer2, 100, "printf(\"Enter value for %s: \");\n", yystack.l_mark[0].str); /*Store a string in buffer2*/
				strcat(buffer, buffer2); /*Append contents of buffer2 to buffer*/
				buffer2[0] = '\0';  /*Clear buffer to prevent potential errors*/
				snprintf(buffer2, 100, "scanf(\"%%lf\", &%s );\n" , yystack.l_mark[0].str); /*Store a string in buffer2*/
				strcat(buffer, buffer2); /*Append contents of buffer2 to buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
				buffer2[0] = '\0'; /*Clear buffer to prevent potential errors*/
				
			}
break;
case 18:
#line 117 "translator.yacc"
	{
				snprintf(buffer, 100, "printf(\"Enter value for %s: \");\n", yystack.l_mark[0].str); /*Store a string in buffer*/
				snprintf(buffer2, 100, "scanf(\"%%lf\", &%s );\n" , yystack.l_mark[0].str); /*Store a string in buffer2*/
				strcat(buffer, buffer2); /*Append contents of buffer2 to buffer*/
				yyval.str = strdup(buffer);/*Return contents of buffer (duplicated so they aren't changed later)*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
				buffer2[0] = '\0'; /*Clear buffer to prevent potential errors*/
			
				
			}
break;
case 19:
#line 128 "translator.yacc"
	{
				snprintf(buffer, 2, "+"); /*Store a string in buffer*/
				strcat(yystack.l_mark[-2].str, buffer); /*Append contents of buffer to $1*/
				strcat (yystack.l_mark[-2].str, yystack.l_mark[0].str); /*Append contents of $3 to $1*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
				yyval.str = yystack.l_mark[-2].str;/*Return contents of $1 (duplicated so they aren't changed later)*/
			}
break;
case 20:
#line 135 "translator.yacc"
	{
				snprintf(buffer, 2, "-"); /*Store a string in buffer*/
				strcat(yystack.l_mark[-2].str, buffer); /*Append contents of buffer to $1*/
				strcat (yystack.l_mark[-2].str, yystack.l_mark[0].str); /*Append contents of $3 to $1*/
				buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
				yyval.str = yystack.l_mark[-2].str;/*Return contents of $1 (duplicated so they aren't changed later)*/
			}
break;
case 22:
#line 144 "translator.yacc"
	{
			snprintf(buffer2, 2, "*"); /*Store a string in buffer2*/
			strcat(yystack.l_mark[-2].str, buffer2); /*Append contents of buffer2 to $1*/
			strcat (yystack.l_mark[-2].str, yystack.l_mark[0].str); /*Append contents of $3 to $1*/
			yyval.str = strdup(yystack.l_mark[-2].str);/*Return contents of $1 (duplicated so they aren't changed later)*/
			buffer2[0] = '\0'; /*Clear buffer to prevent potential errors*/
		}
break;
case 23:
#line 151 "translator.yacc"
	{
			snprintf(buffer2, 2, "/"); /*Store a string in buffer2*/
			strcat(yystack.l_mark[-2].str, buffer2); /*Append contents of buffer2 to $1*/
			strcat (yystack.l_mark[-2].str, yystack.l_mark[0].str); /*Append contents of $3 to $1*/
			yyval.str = strdup(yystack.l_mark[-2].str); /*Return contents of $1 (duplicated so they aren't changed later)*/
			buffer2[0] = '\0'; /*Clear buffer to prevent potential errors*/
		}
break;
case 25:
#line 162 "translator.yacc"
	{
			yyval.str = yystack.l_mark[0].str; /*Return contents of $1*/
		}
break;
case 26:
#line 165 "translator.yacc"
	{
			yyval.str = yystack.l_mark[0].str;  /*Return contents of $1*/
		}
break;
case 27:
#line 168 "translator.yacc"
	{
			snprintf(buffer, 100, "(%s)\n", yystack.l_mark[-1].str); /*Store a string in buffer*/
			yyval.str = strdup(buffer); /*Return contents of buffer (duplicated so they aren't changed later)*/
			buffer[0] = '\0'; /*Clear buffer to prevent potential errors*/
		}
break;
case 28:
#line 175 "translator.yacc"
	{
          yyval.str = yystack.l_mark[0].str; /*Return contents of $1*/
        }
break;
case 30:
#line 179 "translator.yacc"
	{
		yyval.str = yystack.l_mark[0].str;  /*Return contents of $1*/
		}
break;
#line 702 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
