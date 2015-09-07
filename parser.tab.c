
/*  A Bison parser, made from parser.y
 by  Bison version A2.6 (Andrew Consortium)
  */

#define YYBISON 1  /* Identify Bison output.  */

#define yyparse cosmoparseparse
#define yylex cosmoparselex
#define yyerror cosmoparseerror
#define yylval cosmoparselval
#define yychar cosmoparsechar
#define yydebug cosmoparsedebug
#define yynerrs cosmoparsenerrs
#define	integerConstTKN	258
#define	realConstTKN	259
#define	identTKN	260
#define	intTKN	261
#define	realTKN	262
#define	bigTKN	263
#define	whileTKN	264
#define	elseTKN	265
#define	thenTKN	266
#define	ifTKN	267
#define	assignTKN	268
#define	returnTKN	269
#define	callTKN	270
#define	printTKN	271
#define	printlnTKN	272
#define	lessequalTKN	273
#define	greaterequalTKN	274
#define	notequalTKN	275
#define	equalTKN	276
#define	corTKN	277
#define	candTKN	278
#define	globalTKN	279
#define	localTKN	280
#define	pointerTKN	281
#define	stringTKN	282
#define	uminusTKN	283
#define	addressofTKN	284

#line 5 "parser.y"

#define YYDEBUG 1
#include "jabba.h"


void DefineFunction();
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		115
#define	YYFLAG		-32768
#define	YYNTBASE	42

#define YYTRANSLATE(x) ((unsigned)(x) <= 284 ? yytranslate[x] : 72)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    41,     2,     2,     2,    38,     2,     2,    32,
    33,    36,    34,     2,    35,     2,    37,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
     2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    30,     2,    31,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     3,     6,     9,    11,    14,    15,    19,    24,    27,
    29,    31,    33,    35,    37,    39,    41,    43,    45,    49,
    53,    61,    70,    74,    79,    86,    92,    94,    97,    99,
   101,   104,   106,   108,   110,   114,   117,   120,   123,   125,
   127,   129,   131,   133,   135,   137,   139,   141,   143,   145,
   147,   149,   151,   153,   155,   157,   159,   161,   165,   171,
   178,   183,   185,   187,   189,   191,   193,   195,   197,   199
};

static const short yyrhs[] = {    43,
    44,     0,    24,    68,     0,    44,    45,     0,    45,     0,
    45,     1,     0,     0,    70,    46,    47,     0,    30,    68,
    48,    31,     0,    48,    49,     0,    49,     0,    50,     0,
    51,     0,    52,     0,    53,     0,    47,     0,    54,     0,
    55,     0,    56,     0,    13,    62,    59,     0,    13,    64,
    64,     0,    13,    65,    26,     6,    25,    67,    59,     0,
    13,    65,    26,     6,    25,    67,    59,    64,     0,     9,
    59,    49,     0,    12,    59,    11,    49,     0,    12,    59,
    11,    49,    10,    49,     0,    15,    70,    32,    68,    33,
     0,    14,     0,    16,    57,     0,    16,     0,    17,     0,
    57,    58,     0,    58,     0,    71,     0,    59,     0,    60,
    59,    59,     0,    61,    59,     0,    29,    62,     0,    29,
    64,     0,    62,     0,    63,     0,    68,     0,    69,     0,
    34,     0,    35,     0,    36,     0,    37,     0,    38,     0,
    39,     0,    40,     0,    21,     0,    18,     0,    19,     0,
    20,     0,    22,     0,    23,     0,    28,     0,    41,     0,
    65,    66,    67,     0,    65,    26,     6,    25,    67,     0,
     8,    68,    26,     6,    25,    67,     0,     8,    68,    66,
    67,     0,     6,     0,     7,     0,    25,     0,    24,     0,
    59,     0,     3,     0,     4,     0,     5,     0,    27,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    51,    54,    57,    58,    59,    62,    69,   104,   110,   115,
   118,   119,   120,   121,   122,   123,   128,   129,   132,   137,
   142,   164,   173,   179,   183,   190,   197,   200,   204,   211,
   225,   230,   237,   241,   248,   253,   258,   263,   268,   273,
   274,   278,   281,   282,   283,   284,   285,   286,   287,   288,
   289,   290,   291,   292,   293,   296,   297,   300,   316,   324,
   336,   354,   358,   364,   368,   374,   382,   389,   396,   402
};
#endif


#if YYDEBUG != 0

static const char * const yytname[] = {   "$","error","$undefined.","integerConstTKN",
"realConstTKN","identTKN","intTKN","realTKN","bigTKN","whileTKN","elseTKN","thenTKN",
"ifTKN","assignTKN","returnTKN","callTKN","printTKN","printlnTKN","lessequalTKN",
"greaterequalTKN","notequalTKN","equalTKN","corTKN","candTKN","globalTKN","localTKN",
"pointerTKN","stringTKN","uminusTKN","addressofTKN","'{'","'}'","'('","')'",
"'+'","'-'","'*'","'/'","'%'","'<'","'>'","'!'","NModule","NGlobalSpace","NFunctionList",
"NFunction","@1","NCompoundStmt","NStmtList","NStmt","NAssignStmt","NWhileStmt",
"IfStmt","NFunctionCall","NReturnStmt","NPrintStmt","NPrintLnStmt","NPrintList",
"NPrintItem","NExpr","NBinOp","NUnaryOp","NVariable","NVariablePtr","NBigVariable",
"NDatatype","NObjectArea","NOffset","NIntConst","NRealConst","NIdent","NString", NULL
};
#endif

static const short yyr1[] = {     0,
    42,    43,    44,    44,    44,    46,    45,    47,    48,    48,
    49,    49,    49,    49,    49,    49,    49,    49,    50,    50,
    50,    50,    51,    52,    52,    53,    54,    55,    55,    56,
    57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
    59,    59,    60,    60,    60,    60,    60,    60,    60,    60,
    60,    60,    60,    60,    60,    61,    61,    62,    63,    63,
    64,    65,    65,    66,    66,    67,    68,    69,    70,    71
};

static const short yyr2[] = {     0,
     2,     2,     2,     1,     2,     0,     3,     4,     2,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
     7,     8,     3,     4,     6,     5,     1,     2,     1,     1,
     2,     1,     1,     1,     3,     2,     2,     2,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     3,     5,     6,
     4,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,     0,    67,     2,    69,     1,     0,     6,     3,     5,
     0,     0,     7,     0,     0,     0,     0,    27,     0,    29,
    30,    15,     0,    10,    11,    12,    13,    14,    16,    17,
    18,    68,    62,    63,     0,    51,    52,    53,    50,    54,
    55,    56,     0,    43,    44,    45,    46,    47,    48,    49,
    57,     0,     0,     0,    39,    40,     0,    41,    42,     0,
     0,     0,     0,     0,     0,    70,    28,    32,    34,    33,
     8,     9,     0,    37,    38,     0,    23,     0,    36,    65,
    64,     0,     0,     0,     0,    19,    20,     0,     0,    31,
     0,    35,     0,    66,    58,    24,     0,     0,     0,     0,
     0,     0,    61,     0,    26,     0,    59,    25,     0,    60,
    21,    22,     0,     0,     0
};

static const short yydefgoto[] = {   113,
     2,     6,     7,    11,    22,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    67,    68,    94,    53,    54,    55,
    56,    63,    57,    83,    95,    58,    59,     8,    70
};

static const short yypact[] = {   -18,
     6,    10,-32768,-32768,-32768,    10,    11,-32768,-32768,-32768,
   -12,     6,-32768,    41,   116,   116,    34,-32768,    10,    77,
-32768,-32768,    13,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,     6,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    34,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    41,   116,   116,-32768,-32768,    35,-32768,-32768,    12,
     6,   116,    23,    42,     3,-32768,    77,-32768,-32768,-32768,
-32768,-32768,    19,-32768,-32768,    -4,-32768,   116,-32768,-32768,
-32768,    31,   116,    41,    -4,-32768,-32768,    40,     6,-32768,
    43,-32768,    26,-32768,-32768,    38,   116,    44,    32,    45,
   116,    41,-32768,   116,-32768,   116,-32768,-32768,   116,-32768,
    23,-32768,    73,    74,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    69,-32768,    65,-32768,   -20,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    20,   -15,-32768,-32768,   -10,
-32768,   -39,    -9,    -8,   -87,     1,-32768,    59,-32768
};


#define	YYLAST		157


static const short yytable[] = {    52,
    60,     4,    72,    75,    69,     1,    62,    64,     3,   103,
    -4,    10,    14,   107,     5,    -4,   109,    12,   110,    80,
    81,    15,    84,    87,    16,    17,    18,    19,    20,    21,
    61,    77,    74,    76,    89,    73,    93,    78,    79,    33,
    34,    61,    12,    71,    91,    98,    86,   102,   100,    15,
   101,    69,    16,    17,    18,    19,    20,    21,    80,    81,
    82,    85,    92,    96,   105,    80,    81,    88,   104,   106,
    12,   112,   114,   115,     9,    13,    97,    65,     0,     3,
    32,   108,    33,    34,    35,     0,    90,     0,     0,    99,
     0,     0,     0,   111,    36,    37,    38,    39,    40,    41,
     0,     0,     0,    66,    42,    43,     0,     0,     0,     0,
    44,    45,    46,    47,    48,    49,    50,    51,     3,    32,
     0,    33,    34,    35,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    36,    37,    38,    39,    40,    41,     0,
     0,     0,     0,    42,    43,     0,     0,     0,     0,    44,
    45,    46,    47,    48,    49,    50,    51
};

static const short yycheck[] = {    15,
    16,     1,    23,    43,    20,    24,    17,    17,     3,    97,
     0,     1,    12,   101,     5,     5,   104,    30,   106,    24,
    25,     9,    11,    63,    12,    13,    14,    15,    16,    17,
     8,    52,    43,    43,    32,    35,     6,    53,    54,     6,
     7,     8,    30,    31,    26,     6,    62,    10,     6,     9,
    25,    67,    12,    13,    14,    15,    16,    17,    24,    25,
    26,    61,    78,    84,    33,    24,    25,    26,    25,    25,
    30,   111,     0,     0,     6,    11,    85,    19,    -1,     3,
     4,   102,     6,     7,     8,    -1,    67,    -1,    -1,    89,
    -1,    -1,    -1,   109,    18,    19,    20,    21,    22,    23,
    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
    34,    35,    36,    37,    38,    39,    40,    41,     3,     4,
    -1,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    34,
    35,    36,    37,    38,    39,    40,    41
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "c:/data/source/yacc/bison-a2.6/share/bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "c:/data/source/yacc/bison-a2.6/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 6:
#line 62 "parser.y"
{
	printf("%s:\t",yyvsp[0].m_sz);
	if(strcmp(yyvsp[0].m_sz,"main")==0)
		{
		printf("\n__start:\n\tla $a3,0($sp)\n");
		}
	;
    break;}
case 7:
#line 69 "parser.y"
{
	CInstr* pinstr;
	
	yyval.m_pinstrlist = CInstrList__NewList();
	CSemantics__CreateFrame(g_psem,&yyval);
	CAttr__CombineCode(&yyval,&yyvsp[0]);
	pinstr = CInstrList__ItemGet(yyval.m_pinstrlist);
	if((pinstr->m_iinstr != INSTR_JR) || (CInstr__GetArg(pinstr,0).m_wval !=
		REGRETURNADDR))
		{
		CSemantics__ReturnStmt(g_psem,&yyval);
		}
	
	CInstrList__Output(yyval.m_pinstrlist);
	CALL_DESTRUCTOR(CInstrListList,&(g_psem->m_lstlst));
	CALL_CONSTRUCTOR(CInstrListList,&(g_psem->m_lstlst));

	while(CTEMPLIST__CItemsGet(&(g_psem->m_templist)))
		{
		CTEMPLIST__Rewind(&(g_psem->m_templist));
	
		STDFREE(*(CTEMPLIST__ItemGet(&(g_psem->m_templist))));
		CTEMPLIST__Delete(&(g_psem->m_templist));

		}

	AssertStd(g_psem->m_regtable.m_calloced == 0);
	;
    break;}
case 8:
#line 105 "parser.y"
{
	yyval = yyvsp[-1];
	;
    break;}
case 9:
#line 111 "parser.y"
{
	yyval = yyvsp[-1];
	CAttr__CombineCode(&yyval,&yyvsp[0])
	;
    break;}
case 16:
#line 124 "parser.y"
{
		yyval.m_pinstrlist = CInstrList__NewList();
		CSemantics__ReturnStmt(g_psem,&yyval);
		;
    break;}
case 19:
#line 133 "parser.y"
{
	CSemantics__Assign(g_psem,&yyvsp[-1],&yyvsp[0]);
	yyval=yyvsp[0];
	;
    break;}
case 20:
#line 138 "parser.y"
{
	yyval = yyvsp[0];
	CSemantics__Assign(g_psem,&yyvsp[-1],&yyval);
	;
    break;}
case 21:
#line 144 "parser.y"
{
	int idreg;
	CInstr instr;

	yyval.m_pinstrlist = CInstrList__NewList();
	yyval.m_idreg = REGFRAME;
	yyval.m_wtype = yyvsp[-5].m_wtype;
	yyval.m_wval = yyvsp[-1].m_wval;
	
	idreg = CSemantics__RegAlloc(g_psem,&yyval,fFalse);

	CInstrList__AddInstr(yyval.m_pinstrlist,
		CInstr__Set(&instr,INSTR_LW,idreg,0,NULL,
			yyval.m_wval,0,NULL,
			yyval.m_idreg,0,NULL));
	yyval.m_idreg = idreg;
	CSemantics__Assign(g_psem,&yyval,&yyvsp[0]);
	yyval = yyvsp[0];
	CSemantics__RegFree(g_psem,&yyval,idreg);
	;
    break;}
case 22:
#line 166 "parser.y"
{
	yyval = yyvsp[-5];
	CSemantics__Assign(g_psem,&yyvsp[-6],&yyval);
	yyval = yyvsp[-6];
	;
    break;}
case 23:
#line 174 "parser.y"
{
	CSemantics__IWhile(g_psem,&yyvsp[-1],&yyvsp[0],&yyval);
	;
    break;}
case 24:
#line 180 "parser.y"
{
	CSemantics__IIfThen(g_psem,&yyvsp[-2],&yyvsp[0],&yyval);
	;
    break;}
case 25:
#line 184 "parser.y"
{
	CSemantics__IIfThenElse(g_psem,&yyvsp[-4],&yyvsp[-2],&yyvsp[0],&yyval);
	;
    break;}
case 26:
#line 191 "parser.y"
{
	CSemantics__FunctionCall(g_psem,&yyvsp[-3],&yyvsp[-1]);
	yyval = yyvsp[-3];
	;
    break;}
case 28:
#line 201 "parser.y"
{
	yyval = yyvsp[0];
	;
    break;}
case 29:
#line 205 "parser.y"
{
	yyval.m_wtype = ARGTYPE_STRING;
	yyval.m_pinstrlist = CInstrList__NewList();
	;
    break;}
case 30:
#line 218 "parser.y"
{
	yyval.m_wtype = ARGTYPE_STRING;
	yyval.m_pinstrlist = CInstrList__NewList();
	CSemantics__PrintEOL(g_psem, &yyval);
	;
    break;}
case 31:
#line 226 "parser.y"
{
	CSemantics__FPrintCall(g_psem,&(yyvsp[0]));
	CAttr__CombineCode(&yyval,&yyvsp[0]);
	;
    break;}
case 32:
#line 231 "parser.y"
{
	yyval = yyvsp[0];
	CSemantics__FPrintCall(g_psem,&(yyval))
	;
    break;}
case 33:
#line 238 "parser.y"
{
	yyval.m_pinstrlist = CInstrList__NewList();
	;
    break;}
case 35:
#line 249 "parser.y"
{
	CSemantics__BinaryOp(g_psem,&yyvsp[-2],&yyvsp[-1],&yyvsp[0]);
	yyval=yyvsp[-2];
	;
    break;}
case 36:
#line 254 "parser.y"
{
	CSemantics__UnaryOp(g_psem,&yyvsp[-1],&yyvsp[0]);
	yyval=yyvsp[0];
	;
    break;}
case 37:
#line 259 "parser.y"
{
	CSemantics__AddressOf(g_psem,&yyvsp[0]);
	yyval = yyvsp[0];
	;
    break;}
case 38:
#line 264 "parser.y"
{
	CSemantics__AddressOf(g_psem,&yyvsp[0]);
	yyval = yyvsp[0];
	;
    break;}
case 39:
#line 269 "parser.y"
{
	yyval = yyvsp[0];
	CSemantics__VariableExpr(g_psem,&yyval);
	;
    break;}
case 41:
#line 275 "parser.y"
{
	CSemantics__IntConst(g_psem,&yyval);
	;
    break;}
case 43:
#line 281 "parser.y"
{yyval.m_iinstrint = INSTR_ADD; yyval.m_iinstrfloat = INSTR_ADDFLOAT;	;
    break;}
case 44:
#line 282 "parser.y"
{yyval.m_iinstrint = INSTR_SUB; yyval.m_iinstrfloat = INSTR_SUBFLOAT;	;
    break;}
case 45:
#line 283 "parser.y"
{yyval.m_iinstrint = INSTR_MULT; yyval.m_iinstrfloat = INSTR_MULTFLOAT;	;
    break;}
case 46:
#line 284 "parser.y"
{yyval.m_iinstrint = INSTR_DIV; yyval.m_iinstrfloat = INSTR_DIVFLOAT;	;
    break;}
case 47:
#line 285 "parser.y"
{yyval.m_iinstrint = INSTR_REM; yyval.m_iinstrfloat = INSTR_INVALID;	;
    break;}
case 48:
#line 286 "parser.y"
{yyval.m_iinstrint = INSTR_SLT; yyval.m_iinstrfloat = INSTR_SLTFLOAT;	;
    break;}
case 49:
#line 287 "parser.y"
{yyval.m_iinstrint = INSTR_SGT; yyval.m_iinstrfloat = INSTR_SGTFLOAT;	;
    break;}
case 50:
#line 288 "parser.y"
{yyval.m_iinstrint = INSTR_SEQ; yyval.m_iinstrfloat = INSTR_SEQFLOAT;	;
    break;}
case 51:
#line 289 "parser.y"
{yyval.m_iinstrint = INSTR_SLE; yyval.m_iinstrfloat = INSTR_SLEFLOAT;	;
    break;}
case 52:
#line 290 "parser.y"
{yyval.m_iinstrint = INSTR_SGE; yyval.m_iinstrfloat = INSTR_SGEFLOAT;	;
    break;}
case 53:
#line 291 "parser.y"
{yyval.m_iinstrint = INSTR_SNE; yyval.m_iinstrfloat = INSTR_SNEFLOAT;	;
    break;}
case 54:
#line 292 "parser.y"
{yyval.m_iinstrint = INSTR_OR; yyval.m_iinstrfloat = INSTR_OR;	;
    break;}
case 55:
#line 293 "parser.y"
{yyval.m_iinstrint = INSTR_AND; yyval.m_iinstrfloat = INSTR_AND;	;
    break;}
case 56:
#line 296 "parser.y"
{yyval.m_iinstrint = INSTR_NEG; yyval.m_iinstrfloat = INSTR_NEGFLOAT;	;
    break;}
case 57:
#line 297 "parser.y"
{yyval.m_iinstrint = INSTR_SEQ; yyval.m_iinstrfloat = INSTR_SEQFLOAT;	;
    break;}
case 58:
#line 301 "parser.y"
{
	CInstr instr;
	yyval.m_idreg = yyvsp[-1].m_idreg;
	yyval.m_wtype = yyvsp[-2].m_wtype;
	yyval.m_wval = yyvsp[0].m_wval;
	yyval.m_pinstrlist = yyvsp[0].m_pinstrlist;
	CInstrList__AddInstr(yyval.m_pinstrlist,
		CInstr__Set(&instr,INSTR_ADD,yyvsp[0].m_idreg,0,NULL,
			yyvsp[0].m_idreg,0,NULL,
			yyval.m_idreg,0,NULL));
	yyval.m_idreg = yyvsp[0].m_idreg;

	;
    break;}
case 59:
#line 317 "parser.y"
{
	yyval.m_pinstrlist = CInstrList__NewList();
	yyval.m_idreg = REGFRAME;
	yyval.m_wtype = yyvsp[-4].m_wtype;
	yyval.m_wval = yyvsp[0].m_wval;
	CSemantics__Dereference(g_psem,&yyval);
	;
    break;}
case 60:
#line 325 "parser.y"
{
	yyval.m_pinstrlist = CInstrList__NewList();
	yyval.m_idreg = REGFRAME;
	yyval.m_wtype = ARGTYPE_BIG;
	yyval.m_wval = yyvsp[0].m_wval;
	yyval.m_cbsize = yyvsp[-4].m_wval;
	CSemantics__Dereference(g_psem,&yyval);
	;
    break;}
case 61:
#line 337 "parser.y"
{
	CInstr instr;
	yyval.m_idreg = yyvsp[-1].m_idreg;
	yyval.m_wtype = ARGTYPE_BIG;
	yyval.m_wval = yyvsp[0].m_wval;
	yyval.m_cbsize = yyvsp[-2].m_wval;
	yyval.m_pinstrlist = yyvsp[0].m_pinstrlist;
	CInstrList__AddInstr(yyval.m_pinstrlist,
		CInstr__Set(&instr,INSTR_ADD,yyvsp[0].m_idreg,0,NULL,
			yyvsp[0].m_idreg,0,NULL,
			yyval.m_idreg,0,NULL));
	yyval.m_idreg = yyvsp[0].m_idreg;

	;
    break;}
case 62:
#line 355 "parser.y"
{
	yyval.m_wtype = ARGTYPE_INT;
	;
    break;}
case 63:
#line 359 "parser.y"
{
	yyval.m_wtype = ARGTYPE_FLOAT;
	;
    break;}
case 64:
#line 365 "parser.y"
{
	yyval.m_idreg = REGFRAME;
	;
    break;}
case 65:
#line 369 "parser.y"
{
	yyval.m_idreg = REGGLOBAL;
	;
    break;}
case 67:
#line 383 "parser.y"
{
	yyval.m_wtype = ARGTYPE_INT;
	yyval.m_wval = atoi(yytext);
	;
    break;}
case 68:
#line 390 "parser.y"
{
	yyval.m_wtype = ARGTYPE_REAL;
	sscanf(yytext,"%s",&(yyval.m_fpval));
	;
    break;}
case 69:
#line 397 "parser.y"
{
	yyval.m_sz = CStringServer__SzStoreSz(&(g_psem->m_stringsrvr),yytext);
	;
    break;}
case 70:
#line 403 "parser.y"
{
	yyval.m_wtype = ARGTYPE_STRING;
	yyval.m_sz = CStringServer__SzStoreSz(&(g_psem->m_stringsrvr),yytext);
	;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "c:/data/source/yacc/bison-a2.6/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 409 "parser.y"
