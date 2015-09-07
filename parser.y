/*////////////////////////////////
// Parser for project 3
*/

%{
#define YYDEBUG 1
#include "jabba.h"


void DefineFunction();
%}

%token integerConstTKN
%token realConstTKN
%token identTKN
%token intTKN
%token realTKN
%token bigTKN
%token whileTKN
%token elseTKN
%token thenTKN
%token ifTKN
%token assignTKN
%token returnTKN
%token callTKN
%token printTKN
%token printlnTKN
%token lessequalTKN
%token greaterequalTKN
%token notequalTKN
%token equalTKN
%token corTKN
%token candTKN
%token globalTKN
%token localTKN
%token pointerTKN
%token stringTKN
%token uminusTKN
%token addressofTKN

%start NModule

%expect 1

%%

/*//////////////////////////////////
// Module
*/

NModule:	NGlobalSpace NFunctionList
;

NGlobalSpace:	globalTKN NIntConst
;

NFunctionList:	NFunctionList NFunction
	|	NFunction
	|	NFunction error
;

NFunction:	NIdent {
	printf("%s:\t",$1.m_sz);
	if(strcmp($1.m_sz,"main")==0)
		{
		printf("\n__start:\n\tla $a3,0($sp)\n");
		}
	} NCompoundStmt
	{
	CInstr* pinstr;
	
	$$.m_pinstrlist = CInstrList__NewList();
	CSemantics__CreateFrame(g_psem,&$$);
	CAttr__CombineCode(&$$,&$3);
	pinstr = CInstrList__ItemGet($$.m_pinstrlist);
	if((pinstr->m_iinstr != INSTR_JR) || (CInstr__GetArg(pinstr,0).m_wval !=
		REGRETURNADDR))
		{
		CSemantics__ReturnStmt(g_psem,&$$);
		}
	
	CInstrList__Output($$.m_pinstrlist);
	CALL_DESTRUCTOR(CInstrListList,&(g_psem->m_lstlst));
	CALL_CONSTRUCTOR(CInstrListList,&(g_psem->m_lstlst));

	while(CTEMPLIST__CItemsGet(&(g_psem->m_templist)))
		{
		CTEMPLIST__Rewind(&(g_psem->m_templist));
	
		STDFREE(*(CTEMPLIST__ItemGet(&(g_psem->m_templist))));
		CTEMPLIST__Delete(&(g_psem->m_templist));

		}

	AssertStd(g_psem->m_regtable.m_calloced == 0);
	}
;


/*/////////////////////////////////////////////////
// Statements
*/

NCompoundStmt: '{' NIntConst NStmtList '}'
	{
	$$ = $3;
	}
;

NStmtList:	NStmtList NStmt
	{
	$$ = $1;
	CAttr__CombineCode(&$$,&$2)
	}
	|	NStmt
;

NStmt:	NAssignStmt
	|	NWhileStmt 
	|	IfStmt  
	|	NFunctionCall 
	|	NCompoundStmt 
	|	NReturnStmt 
		{
		$$.m_pinstrlist = CInstrList__NewList();
		CSemantics__ReturnStmt(g_psem,&$$);
		}
	|	NPrintStmt 
	|	NPrintLnStmt
;

NAssignStmt: assignTKN NVariable NExpr
	{
	CSemantics__Assign(g_psem,&$2,&$3);
	$$=$3;
	}
	| assignTKN NBigVariable NBigVariable
	{
	$$ = $3;
	CSemantics__Assign(g_psem,&$2,&$$);
	}
	|
	assignTKN 	NDatatype pointerTKN intTKN localTKN NOffset NExpr
	{
	int idreg;
	CInstr instr;

	$$.m_pinstrlist = CInstrList__NewList();
	$$.m_idreg = REGFRAME;
	$$.m_wtype = $2.m_wtype;
	$$.m_wval = $6.m_wval;
	
	idreg = CSemantics__RegAlloc(g_psem,&$$,fFalse);

	CInstrList__AddInstr($$.m_pinstrlist,
		CInstr__Set(&instr,INSTR_LW,idreg,0,NULL,
			$$.m_wval,0,NULL,
			$$.m_idreg,0,NULL));
	$$.m_idreg = idreg;
	CSemantics__Assign(g_psem,&$$,&$7);
	$$ = $7;
	CSemantics__RegFree(g_psem,&$$,idreg);
	}
	|
	assignTKN 	NDatatype pointerTKN intTKN localTKN NOffset NExpr NBigVariable
	{
	$$ = $3;
	CSemantics__Assign(g_psem,&$2,&$$);
	$$ = $2;
	}
;

NWhileStmt:	whileTKN NExpr NStmt
	{
	CSemantics__IWhile(g_psem,&$2,&$3,&$$);
	}
;

IfStmt:	ifTKN NExpr thenTKN NStmt
	{
	CSemantics__IIfThen(g_psem,&$2,&$4,&$$);
	}
	| ifTKN NExpr thenTKN NStmt elseTKN NStmt
	{
	CSemantics__IIfThenElse(g_psem,&$2,&$4,&$6,&$$);
	}
;


NFunctionCall:	callTKN NIdent '(' NIntConst ')'
	{
	CSemantics__FunctionCall(g_psem,&$2,&$4);
	$$ = $2;
	}
;

NReturnStmt:	returnTKN
; 

NPrintStmt:	printTKN NPrintList
	{
	$$ = $2;
	}
	|	printTKN
	{
	$$.m_wtype = ARGTYPE_STRING;
	$$.m_pinstrlist = CInstrList__NewList();
	}
;

NPrintLnStmt:	/*printlnTKN NPrintList
	{
	$$ = $2;
	$$.m_wtype = ARGTYPE_STRING;
	if($$.m_pinstrlist)CSemantics__PrintEOL(g_psem, &$$);
	}
	|*/	printlnTKN
	{
	$$.m_wtype = ARGTYPE_STRING;
	$$.m_pinstrlist = CInstrList__NewList();
	CSemantics__PrintEOL(g_psem, &$$);
	}
;

NPrintList: NPrintList NPrintItem
	{
	CSemantics__FPrintCall(g_psem,&($2));
	CAttr__CombineCode(&$$,&$2);
	}
	| NPrintItem
	{
	$$ = $1;
	CSemantics__FPrintCall(g_psem,&($$))
	}
;

NPrintItem:	NString
	{
	$$.m_pinstrlist = CInstrList__NewList();
	}
	|	NExpr
;

/*///////////////////////////////////////////////////
// Expressions
*/

NExpr:	NBinOp NExpr NExpr
	{
	CSemantics__BinaryOp(g_psem,&$1,&$2,&$3);
	$$=$1;
	}
	|	NUnaryOp NExpr
	{
	CSemantics__UnaryOp(g_psem,&$1,&$2);
	$$=$2;
	}
	| addressofTKN NVariable
	{
	CSemantics__AddressOf(g_psem,&$2);
	$$ = $2;
	}
	| addressofTKN NBigVariable
	{
	CSemantics__AddressOf(g_psem,&$2);
	$$ = $2;
	}
	|	NVariable
	{
	$$ = $1;
	CSemantics__VariableExpr(g_psem,&$$);
	}
	| NVariablePtr
	|	NIntConst
	{
	CSemantics__IntConst(g_psem,&$$);
	}
	|	NRealConst
;

NBinOp:	'+'	{$$.m_iinstrint = INSTR_ADD; $$.m_iinstrfloat = INSTR_ADDFLOAT;	}
	| '-' {$$.m_iinstrint = INSTR_SUB; $$.m_iinstrfloat = INSTR_SUBFLOAT;	}
	| '*' {$$.m_iinstrint = INSTR_MULT; $$.m_iinstrfloat = INSTR_MULTFLOAT;	}
	| '/' {$$.m_iinstrint = INSTR_DIV; $$.m_iinstrfloat = INSTR_DIVFLOAT;	}
	| '%' {$$.m_iinstrint = INSTR_REM; $$.m_iinstrfloat = INSTR_INVALID;	}
	| '<' {$$.m_iinstrint = INSTR_SLT; $$.m_iinstrfloat = INSTR_SLTFLOAT;	}
	| '>' {$$.m_iinstrint = INSTR_SGT; $$.m_iinstrfloat = INSTR_SGTFLOAT;	}
	| equalTKN {$$.m_iinstrint = INSTR_SEQ; $$.m_iinstrfloat = INSTR_SEQFLOAT;	}
	| lessequalTKN {$$.m_iinstrint = INSTR_SLE; $$.m_iinstrfloat = INSTR_SLEFLOAT;	}
	| greaterequalTKN {$$.m_iinstrint = INSTR_SGE; $$.m_iinstrfloat = INSTR_SGEFLOAT;	}
	| notequalTKN {$$.m_iinstrint = INSTR_SNE; $$.m_iinstrfloat = INSTR_SNEFLOAT;	}
	| corTKN {$$.m_iinstrint = INSTR_OR; $$.m_iinstrfloat = INSTR_OR;	}
	| candTKN {$$.m_iinstrint = INSTR_AND; $$.m_iinstrfloat = INSTR_AND;	}
;

NUnaryOp:	uminusTKN {$$.m_iinstrint = INSTR_NEG; $$.m_iinstrfloat = INSTR_NEGFLOAT;	}
	| '!' {$$.m_iinstrint = INSTR_SEQ; $$.m_iinstrfloat = INSTR_SEQFLOAT;	}
;

NVariable:	NDatatype NObjectArea NOffset
	{
	CInstr instr;
	$$.m_idreg = $2.m_idreg;
	$$.m_wtype = $1.m_wtype;
	$$.m_wval = $3.m_wval;
	$$.m_pinstrlist = $3.m_pinstrlist;
	CInstrList__AddInstr($$.m_pinstrlist,
		CInstr__Set(&instr,INSTR_ADD,$3.m_idreg,0,NULL,
			$3.m_idreg,0,NULL,
			$$.m_idreg,0,NULL));
	$$.m_idreg = $3.m_idreg;

	}
;

NVariablePtr:	NDatatype pointerTKN intTKN localTKN NOffset
	{
	$$.m_pinstrlist = CInstrList__NewList();
	$$.m_idreg = REGFRAME;
	$$.m_wtype = $1.m_wtype;
	$$.m_wval = $5.m_wval;
	CSemantics__Dereference(g_psem,&$$);
	}
	| 	bigTKN NIntConst pointerTKN intTKN localTKN NOffset
	{
	$$.m_pinstrlist = CInstrList__NewList();
	$$.m_idreg = REGFRAME;
	$$.m_wtype = ARGTYPE_BIG;
	$$.m_wval = $6.m_wval;
	$$.m_cbsize = $2.m_wval;
	CSemantics__Dereference(g_psem,&$$);
	}

;

NBigVariable: bigTKN NIntConst NObjectArea NOffset
	{
	CInstr instr;
	$$.m_idreg = $3.m_idreg;
	$$.m_wtype = ARGTYPE_BIG;
	$$.m_wval = $4.m_wval;
	$$.m_cbsize = $2.m_wval;
	$$.m_pinstrlist = $4.m_pinstrlist;
	CInstrList__AddInstr($$.m_pinstrlist,
		CInstr__Set(&instr,INSTR_ADD,$4.m_idreg,0,NULL,
			$4.m_idreg,0,NULL,
			$$.m_idreg,0,NULL));
	$$.m_idreg = $4.m_idreg;

	}
;


NDatatype:	intTKN
	{
	$$.m_wtype = ARGTYPE_INT;
	}
	| realTKN
	{
	$$.m_wtype = ARGTYPE_FLOAT;
	}
;

NObjectArea: localTKN
	{
	$$.m_idreg = REGFRAME;
	}
	| globalTKN
	{
	$$.m_idreg = REGGLOBAL;
	}
;

NOffset:	NExpr
;


/*/////////////////////////////////////////////////
// General
*/

NIntConst:	integerConstTKN
	{
	$$.m_wtype = ARGTYPE_INT;
	$$.m_wval = atoi(yytext);
	}
;

NRealConst:	realConstTKN
	{
	$$.m_wtype = ARGTYPE_REAL;
	sscanf(yytext,"%s",&($$.m_fpval));
	}
;	

NIdent:	identTKN
	{
	$$.m_sz = CStringServer__SzStoreSz(&(g_psem->m_stringsrvr),yytext);
	}
;

NString:	stringTKN
	{
	$$.m_wtype = ARGTYPE_STRING;
	$$.m_sz = CStringServer__SzStoreSz(&(g_psem->m_stringsrvr),yytext);
	}
;

