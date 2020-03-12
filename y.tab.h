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
extern YYSTYPE yylval;
