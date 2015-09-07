/*//////////////////////////////////////////////////
// semantic.h
//
*/

#if !defined(_JABBA_H)
#define _JABBA_H

#include "std.h"
#include "stdtype.h"
#include "regalloc.h"

extern FILE *yyin;
void* alloca(unsigned size);
extern int yydebug;

/* flex's definitions */
extern char* yytext;
int yywrap();
int yylex(void);
void yyerror(char* szmsg);

enum
{
    SIZE_INTEGER = 4,
    SIZE_REAL = 4,
    SIZE_VARPARAM = 4,
    SIZE_DYNLINK = 4,
    SIZE_RETURNADDRESS = 4
};

#define ACTIVATION_OVERHEAD	(SIZE_DYNLINK + SIZE_RETURNADDRESS)

#define MAX_STRINGSERVER_STRINGS 15
#define MAX_STRINGSERVER_STRINGSIZE 2048
#define SZENDLINELOCATION "__endline__"


typedef struct _CStringServer
{
    char m_rgrgsz[MAX_STRINGSERVER_STRINGS][MAX_STRINGSERVER_STRINGSIZE + 1];
    int m_isz;
} CStringServer;

CLASS_CONSTRUCTOR(CStringServer);
char* CStringServer__SzStoreSz(CStringServer* pthis, char* szin);

enum
{
    table_types,
    table_idents
};

int yyparse();

#define MAX_INSTR_ARGS 4

typedef union _UInstrArg
{
    int m_wval;	/* holds integer operands for constants and labels */
    double m_fpval;	/* holds floating point values for real instruction operands */
    char* m_szval;
} UInstrArg;

enum
{
    ARGTYPE_INVALID,
    ARGTYPE_FLOAT,
    ARGTYPE_INT,
    ARGTYPE_MEM,
    ARGTYPE_NONE,
    ARGTYPE_BIG,
    ARGTYPE_REG,
    ARGTYPE_REGIND,
    ARGTYPE_STRING,
    ARGTYPE_LABEL
};

#define ARGTYPE_REAL ARGTYPE_FLOAT

typedef struct _InstrDescriptor
{
    char m_szname[32];
    int m_cargs;
    int m_rgargtypes[3];
} InstrDescriptor;

/* the actual instructions */

enum
{
    INSTR_INVALID = 0,
    INSTR_ADD_INT,
    INSTR_SUB_INT,
    INSTR_MULT_INT,
    INSTR_DIV_INT,
    INSTR_MOD_INT,
    INSTR_ADD_REAL,
    INSTR_SUB_REAL,
    INSTR_MULT_REAL,
    INSTR_DIV_REAL,
    INSTR_AND_OP,
    INSTR_OR_OP,
    INSTR_ILT_OP,
    INSTR_ILE_OP,
    INSTR_IGT_OP,
    INSTR_IGE_OP,
    INSTR_IEQ_OpP,
    INSTR_INE_OP,
    INSTR_RLT_OP,
    INSTR_RLE_OP,
    INSTR_RGT_OP,
    INSTR_RGE_OP,
    INSTR_REQ_OP,
    INSTR_RNE_OP,
    INSTR_LOAD_INT,
    INSTR_LOAD_INT_INDEX,
    INSTR_STORE_INT,
    INSTR_STORE_INT_INDEX,
    INSTR_LOAD_REAL,
    INSTR_LOAD_REAL_INDEX,
    INSTR_STORE_REAL,
    INSTR_STORE_REAL_INDEX,
    INSTR_CONST,
    INSTR_LABEL,
    INSTR_GOTO,
    INSTR_B_IGT,
    INSTR_B_ILT,
    INSTR_B_IGE,
    INSTR_B_ILE,
    INSTR_B_INE,
    INSTR_B_IEQ,
    INSTR_B_RGT,
    INSTR_B_RLT,
    INSTR_B_RGE,
    INSTR_B_RLE,
    INSTR_B_RNE,
    INSTR_B_REQ,
    INSTR_PARAM_OP,
    INSTR_INT_CALL_OP,
    INSTR_REAL_CALL_OP,
    INSTR_VOID_CALL_OP,
    INSTR_CAST_REAL,
    INSTR_COPY1,
    INSTR_COPY,
    INSTR_RETURN_OP,
    INSTR_REGALLOC,
    INSTR_REGFREE,
    INSTR_SYSCALL,
    INSTR_MOVE,
    INSTR_MOVS,
    INSTR_LA,
    INSTR_LASTR,
    INSTR_LI,
    INSTR_LW,
    INSTR_LWMEM,
    INSTR_SW,
    INSTR_SWMEM,
    INSTR_ADD,
    INSTR_RESETSTACK,
    INSTR_SUB,
    INSTR_SLE,
    INSTR_SNE,
    INSTR_SEQ,
    INSTR_SGE,
    INSTR_SGT,
    INSTR_SLT,
    INSTR_MULT,
    INSTR_DIV,
    INSTR_REM,
    INSTR_OR,
    INSTR_AND,
    INSTR_NEG,
    INSTR_LBL,
    INSTR_J,
    INSTR_BEQZ,
    INSTR_JR,
    INSTR_CASTINT,
    INSTR_CASTFLOAT,
    INSTR_ADDFLOAT,
    INSTR_SUBFLOAT,
    INSTR_SLEFLOAT,
    INSTR_SNEFLOAT,
    INSTR_SEQFLOAT,
    INSTR_SGEFLOAT,
    INSTR_SGTFLOAT,
    INSTR_SLTFLOAT,
    INSTR_BFLOATTRUE,
    INSTR_BFLOATFALSE,
    INSTR_MULTFLOAT,
    INSTR_DIVFLOAT,
    INSTR_NEGFLOAT,
    INSTR_MOVEFROMFLOAT,
    INSTR_MOVETOFLOAT,
    INSTR_JAL,
    INSTR_LAREG,
    INSTR_NOT,
    INSTR_NOTFLOAT,
    INSTR_ADDI,
    INSTR_MFLOI

};

typedef struct _CInstr
{
    int m_iinstr;	/* holds an enum from above */
    int m_iargtype;	/* what type (int, real, etc) this instruction leaves on the stack */
    int m_iargtype2;
    int m_iargtype3;
    UInstrArg m_arg;	/* the instruction's argument */
    UInstrArg m_arg2;
    UInstrArg m_arg3;
} CInstr;

typedef int INSTRKEY;

CLASS_CONSTRUCTOR(CInstr);
CLASS_DESTRUCTOR(CInstr);

void CInstr__Assign(CInstr* pthis, CInstr* pother);

/* sets the fields of an instruction */
CInstr* CInstr__SetInstr(CInstr* pthis, int iinstr, int wval, double fpval, int iargtype);
CInstr* CInstr__Set(CInstr* pthis, int iinstr, int wval1, double fpval1,char* szarg1,
                    int wval2, double fpval2, char* szarg2,
                    int wval3, double fpval3, char* szarg3);
void SetArg(UInstrArg* parg, int wval, double fpval, char* szarg, int iinstr, int i);

void CInstr__OutputArgs(CInstr* pthis);
UInstrArg CInstr__GetArg(CInstr* pthis, int iarg);

LIST_TEMPLATE_DECLARATION(CInstrList,CInstr,INSTRKEY);	/* instruction list -- stores a sequence of instrs */

typedef CInstrList* CInstrListRef;

LIST_TEMPLATE_DECLARATION(CInstrListList,CInstrListRef,NOKEY);

CLASS_CONSTRUCTOR(CInstrListRef);
CLASS_DESTRUCTOR(CInstrListRef);


CInstrList* CInstrList__NewList();	/* creates a new instruction list */
void CInstrList__FreeList(CInstrList* pthis);	/* destroys a construction list */
CInstrList* CInstrList__CatLists(CInstrList* pthis, CInstrList* pother); /* combines 2 instruction lists */
CInstrList* CInstrList__CatAndFree(CInstrList* pthis, CInstrList* pother);/* combines, but destroys the second */
void CInstrList__AddInstr(CInstrList*, CInstr* pinstr); /* adds an instruction to the end of  a list */
void CInstrList__Output(CInstrList* pthis);	/* outputs an instruction */

typedef struct _CAttr
{
    char* m_sz;
    float m_fpval;
    int m_wval;
    int m_iinstrfloat;
    int m_iinstrint;
    int m_cbsize;
    int m_wtype;
    int m_idreg;
    CInstrList* m_pinstrlist;
} CAttr;

CAttr* CAttr__CombineCode(CAttr* pthis,CAttr* pother);

typedef char* TEMPSTRING;
CLASS_CONSTRUCTOR(TEMPSTRING);
CLASS_DESTRUCTOR(TEMPSTRING);

LIST_TEMPLATE_DECLARATION(CTEMPLIST,TEMPSTRING,TEMPSTRING);

#define YYSTYPE CAttr

typedef struct _CSemantics
{
    int m_clines;
    int m_fException;
    int m_cerrors;
    int m_cSemanticErrors;
    int m_iscope;
    int m_idynlink;
    int m_ilabel;
    int m_fAddFunction;
    int m_cbret;
    CRegTable m_regtable;
    CStringServer m_stringsrvr;
    CInstrListList m_lstlst;
    CTEMPLIST m_templist;
} CSemantics;

typedef char* OutToken;

extern CSemantics* g_psem;

CLASS_CONSTRUCTOR(CSemantics);
CLASS_DESTRUCTOR(CSemantics);

void CSemantics__Intro(CSemantics* pthis);
void CSemantics__Exit(CSemantics* pthis);
void CSemantics__IncrementLines(CSemantics* pthis);
void CSemantics__IncrementErrors(CSemantics* pthis);
void CSemantics__IncrementSemanticErrors(CSemantics* pthis);
void CSemantics__ShowError(char* szformat, char* szarg);
void CSemantics__ThrowException(CSemantics* pthis);
void CSemantics__Generate(OutToken tokout);
int CSemantics__GetToken();
char* CSemantics__CatSz(char* sz1, char* sz2);
BOOLFLAG CSemantics__FPrintCall(CSemantics* pthis, CAttr* pattr);
int CSemantics__GenerateLabel(CSemantics* pthis);
void CSemantics__PrintEOL(CSemantics* pthis, CAttr* pattr);
void CSemantics__CreateFrame(CSemantics* pthis, CAttr* pattr);
void CSemantics__DestroyFrame(CSemantics* pthis, CAttr* pattr);
void CSemantics__ReturnStmt(CSemantics* pthis, CAttr* pattr);
void CSemantics__BindInstr(CSemantics* pthis, CInstr* pinstr);
int CSemantics__BindRegister(CSemantics* pthis, int idvirtreg);

BOOLFLAG CSemantics__BinaryOp(CSemantics* pthis, CAttr* popattr, CAttr* pattr1, CAttr* pattr2);
BOOLFLAG CSemantics__UnaryOp(CSemantics* pthis, CAttr* popattr, CAttr* pattr);
int CSemantics__RegAlloc(CSemantics* pthis,CAttr* pattr,BOOLFLAG ffloat);
void CSemantics__RegFree(CSemantics* pthis,CAttr* pattr, int idvirt);
void CSemantics__IntConst(CSemantics* pthis, CAttr* pattr);
void CSemantics__Assign(CSemantics* pthis,CAttr* pvarattr,CAttr* pexprattr);
void CSemantics__AssignScalar(CSemantics* pthis,CAttr* pvarattr,CAttr* pexprattr);
void CSemantics__AssignBig(CSemantics* pthis,CAttr* psrcattr,CAttr* pdestattr);
void CSemantics__VariableExpr(CSemantics* pthis, CAttr* pattr);
void CSemantics__FunctionCall(CSemantics* pthis, CAttr* pattrfunc, CAttr* pattrstack);
void CSemantics__SaveActive(CSemantics* pthis, CAttr* pattr);
void CSemantics__RestoreActive(CSemantics* pthis, CAttr* pattr);
void CSemantics__AddressOf(CSemantics* pthis,CAttr* pattr);
void CSemantics__Dereference(CSemantics* pthis,CAttr* pattr);

BOOLFLAG CSemantics__IIfThen(CSemantics* pthis, CAttr* pattr1, CAttr* pattr2, CAttr* pattr);
BOOLFLAG CSemantics__IIfThenElse(CSemantics* pthis, CAttr* pattr1, CAttr* pattr2, CAttr* pattr3, CAttr* pattr);
BOOLFLAG CSemantics__IWhile(CSemantics* pthis, CAttr* pattr1, CAttr* pattr2, CAttr* pattr);


#define CSEMANTICS__CATCH(x) if((x)->m_fException)
#define CSEMANTICS__THROWUP(x) {CSemantics__ThrowException(x);goto __exception_exit;}
#define CSEMANTICS__THROW(x) {CSemantics__ThrowException(x);}
#define CSEMANTICS__EXCEPTION_EXIT __exception_exit:	if(0){goto __exception_exit;}
#define CSEMANTICS__CATCH_AND_THROW(x) {if((x)->m_fException){CSEMANTICS__THROWUP((x));}}

#define NEWSTRING(x)	g_sztemp = CSemantics__CatSz("",x);             \
    g_sztemp = *(CTEMPLIST__InsertAfter(&(g_psem->m_templist), &g_sztemp));


extern InstrDescriptor g_rginstrs[];


#endif /* !defined(_JABBA_H) */
