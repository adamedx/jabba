%{
#include <stdlib.h>
#include "jabba.h"
#include "parser.tab.h"
%}

%x ERRORRESET

ID	([a-z]|[A-Z]|_)(([a-z]|[A-Z]|[0-9]|_)*)

INTEGERCONST ((\+|\-)?)(([0-9])+)

REAL1 ((\+|\-)?)(([0-9]+)((\.[0-9]+)))(((E|e)((\+|\-)?)[0-9]*)?)
REAL2 ((\+|\-)?)(\.[0-9]+)(((E|e)((\+|\-)?)[0-9]*)?)
REAL3 ((\+|\-)?)(([0-9]+))(((E|e)((\+|\-)?)[0-9]*)?)

REALCONST ({REAL1}|{REAL2}|{REAL3})

STRINGCONST \"((.)*)\"

POSSPACEONLINE (\040|\t)+
ENDLINE	(\n|\012|\015|(\015\012)|(\012\015))

%%

"//".*{ENDLINE}		{CSemantics__IncrementLines(g_psem); printf("# "); ECHO;}
{ENDLINE}	{CSemantics__IncrementLines(g_psem);}

"assign"		return assignTKN;
"&&"		return candTKN;
"||"		return corTKN;
"<="		return lessequalTKN;
">="		return greaterequalTKN;
"=="		return equalTKN;
"<>"		return notequalTKN;
"uminus"	return uminusTKN;
"real"		return realTKN;
"integer"	return intTKN;
"if"		return ifTKN;
"while"		return whileTKN;
"then"		return thenTKN;
"return"	return returnTKN;
"else"		return elseTKN;
"call"		return callTKN;
"pointer"	return pointerTKN;
"big"		return bigTKN;
"print"		return printTKN;
"println"	return printlnTKN;
"local"		return localTKN;
"global"	return globalTKN;
"ADDRESS_OF"	return addressofTKN;

{INTEGERCONST}	return integerConstTKN;

{REALCONST}		{
	float fpval;
	sscanf(yytext,"%g",&fpval);
	return realConstTKN;
	}

{POSSPACEONLINE}	;	/* eat white space */

{STRINGCONST}	return stringTKN;

{ID}		{
	return identTKN;
	}
<<EOF>>	{
	return 0;
	}

.	return yytext[0];

<ERRORRESET>";"	{BEGIN INITIAL;}
<ERRORRESET>{ENDLINE}	{
	if(yytext[0] == '\n'|| yytext[1] == '\n')
		{
		CSemantics__IncrementLines(g_psem);
		}
	}
<ERRORRESET>.	;

%%

void ErrorReset()
	{
	BEGIN ERRORRESET;
	}
