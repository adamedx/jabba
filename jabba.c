/*/////////////////////////////
// jabba.c
*/

#include "jabba.h"
#include "parser.tab.h"

CSemantics* g_psem = NULL;

char g_szEndLineLocation[] = SZENDLINELOCATION;
char* g_sztemp;

CLASS_CONSTRUCTOR(CSemantics)
	{
	pthis->m_clines = 0;
	pthis->m_fException = fFalse;
	pthis->m_cerrors = 0;
	pthis->m_cSemanticErrors = 0;
	pthis->m_idynlink = 0;
	pthis->m_ilabel = 0;
	pthis->m_fAddFunction = fFalse;
	CALL_CONSTRUCTOR(CStringServer, &(pthis->m_stringsrvr));
	CALL_CONSTRUCTOR(CInstrListList,&(pthis->m_lstlst));
	CALL_CONSTRUCTOR(CRegTable,&(pthis->m_regtable));
	CALL_CONSTRUCTOR(CTEMPLIST,&(pthis->m_templist));

	g_psem = pthis;
	return pthis;
	}

CLASS_DESTRUCTOR(CSemantics)
	{
	CALL_DESTRUCTOR(CRegTable,&(pthis->m_regtable));
	CALL_DESTRUCTOR(CInstrListList,&(pthis->m_lstlst));
	CALL_DESTRUCTOR(CTEMPLIST,&(pthis->m_templist));

	return pthis;
	}

int CSemantics__GenerateLabel(CSemantics* pthis)
	{
	return (pthis->m_ilabel)++;
	}


void CSemantics__IncrementErrors(CSemantics* pthis)
	{
	pthis->m_cerrors++;
	}

void CSemantics__IncrementSemanticErrors(CSemantics* pthis)
	{
	pthis->m_cSemanticErrors++;
	}

void CSemantics__IncrementLines(CSemantics* pthis)
	{
	pthis->m_clines++;
	}

void CSemantics__Intro(CSemantics* pthis)
	{
	fprintf(stderr,"AfroSoft (R) 32-bit p4 Compiler Phase 2 Version 1.4.96\n");
	}

void CSemantics__Exit(CSemantics* pthis)
	{
	fprintf(stderr,"%d lines scanned.\n",pthis->m_clines);
	fprintf(stderr,"%d error(s).\n",pthis->m_cerrors);
	}

void CSemantics__BindInstr(CSemantics* pthis, CInstr* pinstr)
	{
	int i;
	int cargs = g_rginstrs[pinstr->m_iinstr].m_cargs;
	for(i=0;i<cargs;i++)
		{
		UInstrArg arg = CInstr__GetArg(pinstr,i);
		
		switch(g_rginstrs[pinstr->m_iinstr].m_rgargtypes[i])
			{
		case ARGTYPE_REG:
			switch(arg.m_wval)
				{
			case INTCALLREG:
			case FLOATCALLREG:
			case RETURNREG:
			case REGRETURNADDR:
			case REGFRAME:
			case REGSTACK:
			case REGGLOBAL:
			case REGZERO:
				break;
			case REGINVALID:
				AssertStd(fFalse);
				break;
			default:
				if((arg.m_wval & 0xf0000000) != REGADDR)
					{
					arg.m_wval = CSemantics__BindRegister(pthis,arg.m_wval);
					}
				break;
				}
			break;
		default:
			break;
			}
		switch(i)
			{
		case 0:
			pinstr->m_arg = arg;
			break;
		case 1:
			pinstr->m_arg2 = arg;
			break;
		case 2:
			pinstr->m_arg3 = arg;
			break;
			}

		}
	}

int CSemantics__BindRegister(CSemantics* pthis, int idvirtreg)
	{
	CVirtReg* pcur;
	CVirtReg* pold;
	CPhysReg* pphysreg;
	int idrealreg;

	pcur = CRegTable__GetVirtReg(&(pthis->m_regtable),idvirtreg);
	idrealreg = CRegTable__RealRegFromVirtID(&(pthis->m_regtable),idvirtreg);
	pphysreg = CRegTable__GetPhysReg(&(pthis->m_regtable),
		pcur->m_idphysreg,pcur->m_ffloat);
	pold = CPhysReg__GetCurrentOwner(pphysreg);

	if(!(pcur->m_fShared))
		{
		return idrealreg;
		}

	printf("\tsw\t$"); 
	switch(idrealreg & 0xf0000000)
		{
	case REGADDR:
		printf("a");
		break;
	case REGTEMP:
		printf("t");
		break;
	case REGFLOAT:
		printf("f");
		break;
	case REGSAVE:
		printf("s");
		break;
	default:
		AssertStd(fFalse);
		}
	printf("%d,%d($fp)\n",idrealreg & REGMAX,
		g_psem->m_idynlink - pold->m_cboffset);

	printf("\tlw\t$"); 
	switch(idrealreg & 0xf0000000)
		{
	case REGADDR:
		printf("a");
		break;
	case REGTEMP:
		printf("t");
		break;
	case REGFLOAT:
		printf("f");
		break;
	case REGSAVE:
		printf("s");
		break;
	default:
		AssertStd(fFalse);
		}
	printf("%d,%d($fp)\n",idrealreg & REGMAX,
		g_psem->m_idynlink - pcur->m_cboffset);

	pcur->m_fShared = fFalse;
		
	return idrealreg;
	}

void CSemantics__ShowError(char* szformat, char* szarg)
	{
	char szoutbuf[2048];

	if(szarg)
		{
		sprintf(szoutbuf,szformat,szarg);
		yyerror(szoutbuf);
		}
	else
		{
		yyerror(szformat);
		}
	}

void CSemantics__CreateFrame(CSemantics* pthis, CAttr* pattr)
	{
	CInstr instr;
	CInstrList* pinstrlist = pattr->m_pinstrlist;
	CALL_CONSTRUCTOR(CInstr,&instr);

	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_SW,REGFRAME,0,NULL,
			0,0,NULL,
			REGSTACK,0,NULL));
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_SW,REGRETURNADDR,0,NULL,
			-4,0,NULL,
			REGSTACK,0,NULL));
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_MOVE,REGFRAME,0,NULL,
			REGSTACK,0,NULL,
			0,0,NULL));
	CALL_DESTRUCTOR(CInstr,&instr);
	}
	
void CSemantics__DestroyFrame(CSemantics* pthis, CAttr* pattr)
	{
	CInstr instr;
	CInstrList* pinstrlist = pattr->m_pinstrlist;

	CALL_CONSTRUCTOR(CInstr,&instr);

	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_MOVE,REGSTACK,0,NULL,
			REGFRAME,0,NULL,
			0,0,NULL));
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_LW,REGRETURNADDR,0,NULL,
			-4,0,NULL,
			REGSTACK,0,NULL));

	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_LW,REGFRAME,0,NULL,
			0,0,NULL,
			REGSTACK,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);
	}


char* CSemantics__CatSz(char* sz1, char* sz2)
	{
	char* sznewbuf = STDMALLOC((strlen(sz1) + strlen(sz2) + 1) * sizeof(char));
	strcpy(sznewbuf,sz1);
	return strcat(sznewbuf,sz2);
	}

BOOLFLAG CSemantics__FPrintCall(CSemantics* pthis, CAttr* pattr)
	{
	CInstrList* pinstrlist;	
	CInstr instr;

	int ilbl;

	CALL_CONSTRUCTOR(CInstr,&instr);
	
	pinstrlist = pattr->m_pinstrlist;
	
	switch(pattr->m_wtype)
		{
	case ARGTYPE_INT:
		CInstrList__AddInstr(pinstrlist,
			CInstr__Set(&instr,INSTR_MOVE,INTCALLREG,0,NULL,
				pattr->m_idreg,0,NULL,
				0,0,NULL));
		CInstrList__AddInstr(pinstrlist,
			CInstr__Set(&instr,INSTR_LI,RETURNREG,0,NULL,
				1,0,NULL,
				0,0,NULL));
		break;
	case ARGTYPE_FLOAT:
		return 0;
		CInstrList__AddInstr(pinstrlist,
			CInstr__Set(&instr,INSTR_MOVE,FLOATCALLREG,0,NULL,
				pattr->m_idreg,0,NULL,
				0,0,NULL));
		CInstrList__AddInstr(pinstrlist,
			CInstr__Set(&instr,INSTR_LI,RETURNREG,0,NULL,
				2,0,NULL,
				0,0,NULL));
		break;
	case ARGTYPE_STRING:
		ilbl = CSemantics__GenerateLabel(pthis);
		printf("\t.data\n");
		printf("L%d:\t.asciiz\t%s\n",ilbl,pattr->m_sz);
		printf("\t.text\n");
		pinstrlist = pattr->m_pinstrlist = CInstrList__NewList();
		CInstrList__AddInstr(pinstrlist,
			CInstr__Set(&instr,INSTR_LASTR,INTCALLREG,0,NULL,
				ilbl,0,0,
				0,0,NULL));
		CInstrList__AddInstr(pinstrlist,
			CInstr__Set(&instr,INSTR_LI,RETURNREG,0,NULL,
				4,0,NULL,
				0,0,NULL));
		break;
	default:
		/*CInstrList__FreeList(pattr->m_pinstrlist);*/
		printf("println takes only int, real, or string constant arguments\n");			
		CALL_DESTRUCTOR(CInstr,&instr);
		return fFalse;
		}
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_SYSCALL,0,0,NULL,
			0,0,NULL,
			0,0,NULL));
	if(pattr->m_wtype != ARGTYPE_STRING)
		{
		CSemantics__RegFree(pthis,pattr,pattr->m_idreg);
		}
	CALL_DESTRUCTOR(CInstr,&instr);
	return fTrue;
	}

void CSemantics__PrintEOL(CSemantics* pthis, CAttr* pattr)
	{
	CInstrList* pinstrlist = pattr->m_pinstrlist;
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	NEWSTRING(g_szEndLineLocation);

	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_LA,INTCALLREG,0,NULL,
			0,0,g_sztemp,
			0,0,NULL));
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_LI,RETURNREG,0,NULL,
			4,0,NULL,
			0,0,NULL));
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_SYSCALL,0,0,NULL,
			0,0,NULL,
			0,0,NULL));
	CALL_DESTRUCTOR(CInstr,&instr);
	}

void CSemantics__ReturnStmt(CSemantics* pthis, CAttr* pattr)
	{
	CInstr instr;
	CInstrList* pinstrlist = pattr->m_pinstrlist;

	CALL_CONSTRUCTOR(CInstr,&instr);
	
	CSemantics__DestroyFrame(g_psem,pattr);
	
	CInstrList__AddInstr(pinstrlist,
		CInstr__Set(&instr,INSTR_JR,REGRETURNADDR,0,NULL,
			0,0,NULL,
			0,0,NULL));
	}

BOOLFLAG CSemantics__UnaryOp(CSemantics* pthis, CAttr* popattr, CAttr* pattr)
	{
	int iinstr = popattr->m_iinstrint;
	CInstr instr;
	int wtype = pattr->m_wtype;
	int idzeroreg = REGZERO;

	CALL_CONSTRUCTOR(CInstr,&instr);
	
	switch(wtype)
		{
	case ARGTYPE_FLOAT:
		wtype =ARGTYPE_FLOAT;
		iinstr = popattr->m_iinstrfloat;
		break;
	case ARGTYPE_INT:
		wtype =ARGTYPE_INT;
		iinstr = popattr->m_iinstrint;
		break;
	default:
		CSemantics__ShowError("Argument to Unary Op is not of float or int type",NULL);
		break;
		}

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,iinstr,pattr->m_idreg,0,NULL,
			pattr->m_idreg,0,NULL,
			REGZERO,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);
	return fTrue;
	
	}

void CSemantics__AddressOf(CSemantics* pthis,CAttr* pattr)
	{
	CInstr instr;
	int idreg;
	CALL_CONSTRUCTOR(CInstr,&instr);
	
	pattr->m_pinstrlist = CInstrList__NewList();

	/* get a register for the variable */
	idreg = CSemantics__RegAlloc(pthis,pattr,fFalse);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_ADDI,idreg,0,NULL,
			pattr->m_idreg,0,NULL,
			pattr->m_wval,0,NULL));

	pattr->m_idreg = idreg;
	CALL_DESTRUCTOR(CInstr,&instr);
	}

void CSemantics__Dereference(CSemantics* pthis,CAttr* pattr)
	{
	CInstr instr;
	int idreg;
	CALL_CONSTRUCTOR(CInstr,&instr);

	/* get a register for the variable */
	idreg = CSemantics__RegAlloc(pthis,pattr,fFalse);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LW,idreg,0,NULL,
			pattr->m_wval,0,NULL,
			pattr->m_idreg,0,NULL));

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LW,idreg,0,NULL,
			0,0,NULL,
			idreg,0,NULL));

	pattr->m_idreg = idreg;
	pattr->m_wval = 0;
	CALL_DESTRUCTOR(CInstr,&instr);
	
	}


BOOLFLAG CSemantics__BinaryOp(CSemantics* pthis, CAttr* popattr, CAttr* pattr1, CAttr* pattr2)
	{
	int iinstr = popattr->m_iinstrint;
	CInstr instr;

	int wtype = ARGTYPE_INT;
	int wtype1 = pattr1->m_wtype;
	int wtype2 = pattr2->m_wtype;
	int idreg1 = pattr1->m_idreg;
	int idreg2 = pattr2->m_idreg;
	int oldreg1 = idreg1;
	int oldreg2 = idreg2;
	BOOLFLAG ffloatcond = fFalse;

	CALL_CONSTRUCTOR(CInstr,&instr);

	/* generate necessary casts */
	popattr->m_pinstrlist = CInstrList__NewList();

	switch(wtype1)
		{
	case ARGTYPE_FLOAT:
		wtype = wtype1 = ARGTYPE_FLOAT;
		iinstr = popattr->m_iinstrfloat;
		idreg1 = CSemantics__RegAlloc(pthis,pattr1,fTrue);
		CInstrList__AddInstr(pattr1->m_pinstrlist,
			CInstr__Set(&instr,INSTR_CASTFLOAT,pattr1->m_idreg,0,NULL,
				idreg1,0,NULL,
				0,0,NULL));
		CSemantics__RegFree(pthis,pattr1,pattr1->m_idreg);
		break;
	case ARGTYPE_INT:
		break;
	default:
		CSemantics__ShowError("Argument 1 is not of float or int type",NULL);
		break;
		}

	switch(wtype2)
		{
	case ARGTYPE_FLOAT:
		wtype = wtype2 = ARGTYPE_FLOAT;
		iinstr = popattr->m_iinstrfloat;
		idreg2 = CSemantics__RegAlloc(pthis,pattr2,fTrue);
		CInstrList__AddInstr(pattr2->m_pinstrlist,
			CInstr__Set(&instr,INSTR_CASTFLOAT,pattr2->m_idreg,0,NULL,
				idreg2,0,NULL,
				0,0,NULL));
		CSemantics__RegFree(pthis,pattr2,pattr2->m_idreg);
		break;
	case ARGTYPE_INT:
		break;
	default:
		CSemantics__ShowError("Argument 1 is not of float or int type",NULL);
		break;
		}
	
	CAttr__CombineCode(popattr,pattr1);
	CAttr__CombineCode(popattr,pattr2);

	switch(iinstr)
		{
	case INSTR_SLEFLOAT:
	case INSTR_SNEFLOAT:
	case INSTR_SEQFLOAT:
	case INSTR_SGEFLOAT:
	case INSTR_SGTFLOAT:
	case INSTR_SLTFLOAT:
		ffloatcond = fTrue;
		popattr->m_idreg = CSemantics__RegAlloc(pthis,popattr,fFalse);
		break;
	default:
		break;
		/*popattr->m_idreg = CSemantics__RegAlloc(pthis,popattr,wtype == ARGTYPE_FLOAT);*/
		}

	if((iinstr == INSTR_MULT) || (iinstr == INSTR_DIV))
		{
		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,iinstr,oldreg1,0,NULL,
				idreg2,0,NULL,
				0,0,NULL));

		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,INSTR_MFLOI,oldreg1,0,NULL,
				0,0,NULL,
				0,0,NULL));
		}
	else
		{
		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,iinstr,oldreg1,0,NULL,
				idreg1,0,NULL,
				idreg2,0,NULL));
		}
	/*CSemantics__RegFree(pthis,popattr,oldreg1);*/
	CSemantics__RegFree(pthis,popattr,oldreg2);

	if(ffloatcond)
		{
		int lbl = CSemantics__GenerateLabel(pthis);
		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,INSTR_MOVE,popattr->m_idreg,0,NULL,
				REGZERO,0,NULL,
				0,0,NULL));
		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,INSTR_BFLOATFALSE,lbl,0,NULL,
				0,0,NULL,
				0,0,NULL));
		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,INSTR_LI,popattr->m_idreg,0,NULL,
				1,0,NULL,
				0,0,NULL));
		CInstrList__AddInstr(popattr->m_pinstrlist,
			CInstr__Set(&instr,INSTR_LABEL,lbl,0,NULL,
				0,0,NULL,
				0,0,NULL));
		}
	else
		{
		popattr->m_idreg = oldreg1;
		}
				
	popattr->m_wtype = wtype;


	CALL_DESTRUCTOR(CInstr,&instr);
	return fTrue;
	}

int CSemantics__RegAlloc(CSemantics* pthis,CAttr* pattr,BOOLFLAG ffloat)
	{
	int idreg;
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	idreg = CRegTable__RegRequest(&(pthis->m_regtable),ffloat);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_REGALLOC,idreg,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);

	return idreg;
	
	}

void CSemantics__RegFree(CSemantics* pthis,CAttr* pattr, int idvirt)
	{
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_REGFREE,idvirt,0,NULL,
			0,0,NULL,
			0,0,NULL));
	}

void CSemantics__IntConst(CSemantics* pthis, CAttr* pattr)
	{
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	pattr->m_pinstrlist = CInstrList__NewList();

	pattr->m_idreg = CSemantics__RegAlloc(pthis,pattr,fFalse);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LI,pattr->m_idreg,0,NULL,
			pattr->m_wval,0,NULL,
			0,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);
	}
	
void CSemantics__Assign(CSemantics* pthis,CAttr* pvarattr,CAttr* pexprattr)
	{

	switch(pvarattr->m_wtype)
		{
	case ARGTYPE_INT:
		CSemantics__AssignScalar(pthis,pvarattr,pexprattr);
		break;
	case ARGTYPE_FLOAT:
		CSemantics__AssignScalar(pthis,pvarattr,pexprattr);
		break;
	case ARGTYPE_BIG:
		CSemantics__AssignBig(pthis,pvarattr,pexprattr);
		break;
	default:
		AssertStd(fFalse);
		break;
		}

	}

void CSemantics__AssignScalar(CSemantics* pthis,CAttr* pvarattr,CAttr* pexprattr)
	{
	CInstr instr;
	int idreg;

	CALL_CONSTRUCTOR(CInstr,&instr);
		
	idreg = pexprattr->m_idreg;

	/* see if we need to typecast */
	if(pvarattr->m_wtype != pexprattr->m_wtype)
		{
		if(pvarattr->m_wtype == ARGTYPE_INT)
			{
			idreg = CSemantics__RegAlloc(pthis,pexprattr,fFalse);

			CInstrList__AddInstr(pexprattr->m_pinstrlist,
				CInstr__Set(&instr,INSTR_CASTINT,pexprattr->m_idreg,0,NULL,
					pexprattr->m_idreg,0,NULL,
					0,0,NULL));

			CInstrList__AddInstr(pexprattr->m_pinstrlist,
				CInstr__Set(&instr,INSTR_MOVEFROMFLOAT,idreg,0,NULL,
					pexprattr->m_idreg,0,NULL,
					0,0,NULL));

			CSemantics__RegFree(pthis,pexprattr,pexprattr->m_idreg);
			}
		else
			{
			idreg = CSemantics__RegAlloc(pthis,pexprattr,fTrue);

			CInstrList__AddInstr(pexprattr->m_pinstrlist,
				CInstr__Set(&instr,INSTR_MOVETOFLOAT,idreg,0,NULL,
					pexprattr->m_idreg,0,NULL,
					0,0,NULL));

			CInstrList__AddInstr(pexprattr->m_pinstrlist,
				CInstr__Set(&instr,INSTR_CASTFLOAT,idreg,0,NULL,
					idreg,0,NULL,
					0,0,NULL));

			CSemantics__RegFree(pthis,pexprattr,pexprattr->m_idreg);

			}
		}

	/* now perform the assignment -- a store word */
	if(pvarattr->m_wtype == ARGTYPE_FLOAT)
		{
		/* first we must store it in an integer reg */
		if(pexprattr->m_wtype == ARGTYPE_FLOAT)
			{
			int idintreg = CSemantics__RegAlloc(pthis,pexprattr,fFalse);

			CInstrList__AddInstr(pexprattr->m_pinstrlist,
				CInstr__Set(&instr,INSTR_MOVEFROMFLOAT,idintreg,0,NULL,
					idreg,0,NULL,
					0,0,NULL));
			CSemantics__RegFree(pthis,pexprattr,idreg);
			idreg = idintreg;
			}
		}
	
	/* store the value */

	CAttr__CombineCode(pexprattr,pvarattr);
	CInstrList__AddInstr(pexprattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_SW,idreg,0,NULL,
			0,0,NULL,
			pvarattr->m_idreg,0,NULL));

	CSemantics__RegFree(pthis,pexprattr,pexprattr->m_idreg);
	CSemantics__RegFree(pthis,pexprattr,pvarattr->m_idreg);
	
	CALL_DESTRUCTOR(CInstr,&instr);
	}

void CSemantics__VariableExpr(CSemantics* pthis, CAttr* pattr)
	{
	/*int idreg;*/
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	/* get a register for the variable */

	/*idreg = CSemantics__RegAlloc(pthis,pattr,pattr->m_wtype == ARGTYPE_FLOAT);*/

	/* store the value */
	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LW,pattr->m_idreg,0,NULL,
			0,0,NULL,
			pattr->m_idreg,0,NULL));
	/*pattr->m_idreg = idreg;*/

	CALL_DESTRUCTOR(CInstr,&instr);
	}

void CSemantics__AssignBig(CSemantics* pthis,CAttr* psrcattr,CAttr* pdestattr)
	{
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	CAttr__CombineCode(pdestattr,psrcattr);

	CInstrList__AddInstr(pdestattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LAREG,REGADDR | 1,0,NULL,
			0,0,NULL,
			pdestattr->m_idreg,0,NULL));

	CInstrList__AddInstr(pdestattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LAREG,REGADDR | 0,0,NULL,
			0,0,NULL,
			psrcattr->m_idreg,0,NULL));
	
	CInstrList__AddInstr(pdestattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LI,REGADDR | 2,0,NULL,
			psrcattr->m_cbsize,0,NULL,
			0,0,NULL));

	
	NEWSTRING("__copy");
	CInstrList__AddInstr(pdestattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_JAL,0,0,g_sztemp,
			0,0,NULL,
			0,0,NULL));

	CSemantics__RegFree(pthis,pdestattr,pdestattr->m_idreg);
	CSemantics__RegFree(pthis,pdestattr,psrcattr->m_idreg);

	CALL_DESTRUCTOR(CInstr,&instr);
	}


/*///////////////////////////////////////////////////////
// CSemantics__IWhile
// Generates the code for a while instruction
*/

BOOLFLAG CSemantics__IWhile(CSemantics* pthis, CAttr* pattr1, CAttr* pattr2, CAttr* pattr)
	{
	CInstr instr;
	int ilblbegin = CSemantics__GenerateLabel(pthis);
	int ilblend = CSemantics__GenerateLabel(pthis);

	CALL_CONSTRUCTOR(CInstr,&instr);

	pattr->m_pinstrlist = CInstrList__NewList();

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LBL,ilblbegin,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CAttr__CombineCode(pattr,pattr1);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_BEQZ,pattr1->m_idreg,0,NULL,
			ilblend,0,NULL,
			0,0,NULL));

	CSemantics__RegFree(pthis,pattr,pattr1->m_idreg);

	CAttr__CombineCode(pattr,pattr2);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_J,ilblbegin,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LBL,ilblend,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);
	return fTrue;
	}

/*///////////////////////////////////////////////////////
// CSemantics__IIfThen
// Generates the code for an if-then instruction
*/

BOOLFLAG CSemantics__IIfThen(CSemantics* pthis, CAttr* pattr1, CAttr* pattr2, CAttr* pattr)
	{
	CInstr instr;
	int ilblend = CSemantics__GenerateLabel(pthis);

	CALL_CONSTRUCTOR(CInstr,&instr);

	pattr->m_pinstrlist = CInstrList__NewList();

	CAttr__CombineCode(pattr,pattr1);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_BEQZ,pattr1->m_idreg,0,NULL,
			ilblend,0,NULL,
			0,0,NULL));

	CSemantics__RegFree(pthis,pattr,pattr1->m_idreg);

	CAttr__CombineCode(pattr,pattr2);
	
	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LBL,ilblend,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);
	return fTrue;
	}

/*///////////////////////////////////////////////////////
// CSemantics__IIfThenElse
// Generates the code for an if-then-else instruction
*/

BOOLFLAG CSemantics__IIfThenElse(CSemantics* pthis, CAttr* pattr1, CAttr* pattr2, CAttr* pattr3, CAttr* pattr)
	{
	CInstr instr;
	int ilblelse = CSemantics__GenerateLabel(pthis);	
	int ilblend = CSemantics__GenerateLabel(pthis);

	CALL_CONSTRUCTOR(CInstr,&instr);

	pattr->m_pinstrlist = CInstrList__NewList();

	CAttr__CombineCode(pattr,pattr1);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_BEQZ,pattr1->m_idreg,0,NULL,
			ilblelse,0,NULL,
			0,0,NULL));

	CSemantics__RegFree(pthis,pattr,pattr1->m_idreg);

	CAttr__CombineCode(pattr,pattr2);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_J,ilblend,0,NULL,
			0,0,NULL,
			0,0,NULL));
	
	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LBL,ilblelse,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CAttr__CombineCode(pattr,pattr3);

	CInstrList__AddInstr(pattr->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LBL,ilblend,0,NULL,
			0,0,NULL,
			0,0,NULL));

	CALL_DESTRUCTOR(CInstr,&instr);
	return fTrue;
	}

void CSemantics__FunctionCall(CSemantics* pthis, CAttr* pattrfunc, CAttr* pattrstack)
	{
	CInstr instr;
	CALL_CONSTRUCTOR(CInstr,&instr);

	pattrfunc->m_pinstrlist = CInstrList__NewList();

	CInstrList__AddInstr(pattrfunc->m_pinstrlist,
		CInstr__Set(&instr,INSTR_LAREG,REGSTACK,0,NULL,
			pattrstack->m_wval,0,NULL,
			REGFRAME,0,NULL));

	NEWSTRING(pattrfunc->m_sz);

	CInstrList__AddInstr(pattrfunc->m_pinstrlist,
		CInstr__Set(&instr,INSTR_JAL,0,0,g_sztemp,
			0,0,NULL,
			0,0,NULL));


	CALL_DESTRUCTOR(CInstr,&instr);
	}

/*////////////////////////////////////////////////////////////////////
// instruction decoding
*/

InstrDescriptor g_rginstrs[] = 
	{
	{"INSTR_INVALID",0,{0,0,0}},
	{"ADD_INT",1,{ARGTYPE_INT,0,0}},
	{"SUB_INT",1,{ARGTYPE_INT,0,0}},
	{"MULT_INT",1,{ARGTYPE_INT,0,0}},
	{"DIV_INT",1,{ARGTYPE_INT,0,0}},
	{"MOD_INT",1,{ARGTYPE_INT,0,0}},
	{"ADD_REAL",1,{ARGTYPE_FLOAT,0,0}},
	{"SUB_REAL",1,{ARGTYPE_FLOAT,0,0}},
	{"MULT_REAL",1,{ARGTYPE_FLOAT,0,0}},
	{"DIV_REAL",1,{ARGTYPE_FLOAT,0,0}},
	{"AND_OP",1,{ARGTYPE_INT,0,0}},
	{"OR_OP",1,{ARGTYPE_INT,0,0}},
	{"ILT_OP",1,{ARGTYPE_INT,0,0}},
	{"ILE_OP",1,{ARGTYPE_INT,0,0}},
	{"IGT_OP",1,{ARGTYPE_INT,0,0}},
	{"IGE_OP",1,{ARGTYPE_INT,0,0}},
	{"IEQ_OP",1,{ARGTYPE_INT,0,0}},
	{"INE_OP",1,{ARGTYPE_INT,0,0}},
	{"RLT_OP",1,{ARGTYPE_FLOAT,0,0}},
	{"REL_OP",1,{ARGTYPE_FLOAT,0,0}},
	{"RGT_OP",1,{ARGTYPE_FLOAT,0,0}},
	{"RGE_OP",1,{ARGTYPE_FLOAT,0,0}},
	{"REQ_OP",1,{ARGTYPE_FLOAT,0,0}},
	{"RNE_OP",1,{ARGTYPE_FLOAT,0,0}},
	{"LOAD_INT",1,{ARGTYPE_MEM,0,0}},
	{"LOAD_INT_INDEX",1,{ARGTYPE_MEM,0,0}},
	{"STORE_INT",1,{ARGTYPE_MEM,0,0}},
	{"STORE_INT_INDEX",1,{ARGTYPE_MEM,0,0}},
	{"LOAD_REAL",1,{ARGTYPE_MEM,0,0}},
	{"LOAD_REAL_INDEX",1,{ARGTYPE_MEM,0,0}},
	{"STORE_REAL",1,{ARGTYPE_MEM,0,0}},
	{"STORE_REAL_INDEX",1,{ARGTYPE_MEM,0,0}},
	{"CONST",1,{ARGTYPE_INT,0,0}},
	{"LABEL",1,{ARGTYPE_INT,0,0}},
	{"GOTO",1,{ARGTYPE_INT,0,0}},
	{"B_IGT",1,{ARGTYPE_INT,0,0}},
	{"B_ILT",1,{ARGTYPE_INT,0,0}},
	{"B_IGE",1,{ARGTYPE_INT,0,0}},
	{"B_ILE",1,{ARGTYPE_INT,0,0}},
	{"B_INE",1,{ARGTYPE_INT,0,0}},
	{"B_IEQ",1,{ARGTYPE_INT,0,0}},
	{"B_RGT",1,{ARGTYPE_FLOAT,0,0}},
	{"B_RLT",1,{ARGTYPE_FLOAT,0,0}},
	{"B_RGE",1,{ARGTYPE_FLOAT,0,0}},
	{"B_RLE",1,{ARGTYPE_FLOAT,0,0}},
	{"B_RNE",1,{ARGTYPE_FLOAT,0,0}},
	{"B_REQ",1,{ARGTYPE_FLOAT,0,0}},
	{"PARAM_OP",1,{ARGTYPE_MEM,0,0}},
	{"INT_CALL_OP",1,{ARGTYPE_NONE,0,0}},
	{"REAL_CALL_OP",1,{ARGTYPE_NONE,0,0}},
	{"VOID_CALL_OP",1,{ARGTYPE_NONE,0,0}},
	{"CAST_REAL",1,{ARGTYPE_INT,0,0}},
	{"",0,{ARGTYPE_NONE,0,0}},
	{"COPY",1,{ARGTYPE_NONE,0,0}},
	{"RETURN_OP",0,{ARGTYPE_NONE,0,0}},
	{"regalloc",1,{ARGTYPE_REG,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"regfree",1,{ARGTYPE_REG,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"syscall",0,{ARGTYPE_NONE,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"move",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"mov.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"la",2,{ARGTYPE_REG,ARGTYPE_MEM,ARGTYPE_NONE}},
	{"la",2,{ARGTYPE_REG,ARGTYPE_LABEL,ARGTYPE_NONE}},
	{"li",2,{ARGTYPE_REG,ARGTYPE_INT,ARGTYPE_NONE}},
	{"lw",3,{ARGTYPE_REG,ARGTYPE_REGIND,ARGTYPE_REG}},
	{"lw",2,{ARGTYPE_REG,ARGTYPE_MEM,ARGTYPE_NONE}},
	{"sw",3,{ARGTYPE_REG,ARGTYPE_REGIND,ARGTYPE_REG}},
	{"sw",2,{ARGTYPE_REG,ARGTYPE_MEM,ARGTYPE_NONE}},
	{"add",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"reset",0,{ARGTYPE_NONE,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"sub",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"sle",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"sne",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"seq",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"sge",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"sgt",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"slt",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"mult",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"div",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"rem",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"or",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"and",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"neg",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"lbl",1,{ARGTYPE_LABEL,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"j",1,{ARGTYPE_LABEL,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"beqz",2,{ARGTYPE_REG,ARGTYPE_LABEL,ARGTYPE_NONE}},
	{"jr",1,{ARGTYPE_REG,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"cvt.w.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"cvt.s.w",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"add.s",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"sub.s",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"c.le.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"c.ne.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"c.eq.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"c.ge.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"c.gt.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"c.lt.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"bc1t",1,{ARGTYPE_LABEL,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"bc1f",1,{ARGTYPE_LABEL,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"mul.s",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"div.s",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_REG}},
	{"neg.s",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"mfc1",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"mtc1",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"jal",1,{ARGTYPE_MEM,ARGTYPE_NONE,ARGTYPE_NONE}},
	{"la",3,{ARGTYPE_REG,ARGTYPE_REGIND,ARGTYPE_REG}},
	{"not",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"not",2,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_NONE}},
	{"addi",3,{ARGTYPE_REG,ARGTYPE_REG,ARGTYPE_INT}},
	{"mflo",1,{ARGTYPE_REG,ARGTYPE_NONE,ARGTYPE_NONE}}
	};


/*////////////////////////////////////////////////////////////
// class CInstr
// Instruction class
*/

/*///////////////////////////////////////////////////////
// CInstr Constructor
*/

CLASS_CONSTRUCTOR(CInstr)
	{
	pthis->m_arg.m_szval = NULL;
	pthis->m_arg2.m_szval = NULL;
	pthis->m_arg3.m_szval = NULL;

	pthis->m_iargtype = ARGTYPE_NONE;
	pthis->m_iargtype2 = ARGTYPE_NONE;
	pthis->m_iargtype3 = ARGTYPE_NONE;
	return pthis;
	}

/*///////////////////////////////////////////////////////
// CInstr Destructor
*/

CLASS_DESTRUCTOR(CInstr)
	{
	return pthis;
	}

/*///////////////////////////////////////////////////////
// CInstr__Assign
*/

void CInstr__Assign(CInstr* pthis, CInstr* pother)
	{
	*pthis = *pother;
	}

/*///////////////////////////////////////////////////////
// CInstr__SetInstr
*/

CInstr* CInstr__SetInstr(CInstr* pthis, int iinstr, int wval, double fpval, int iargtype)
	{
	AssertStd(fFalse);
	pthis->m_iinstr = iinstr;
	pthis->m_iargtype = iargtype;

	switch(iargtype)
		{
	case ARGTYPE_FLOAT:
		pthis->m_arg.m_fpval = fpval;
		break;
	case ARGTYPE_INT:
		pthis->m_arg.m_wval = wval;
		break;
	case ARGTYPE_MEM:
	/*	pthis->m_arg.m_szval = psym;*/
		break;
	case ARGTYPE_NONE:
		break;
	default:
		AssertStd(fFalse);
		}

	return pthis;
	}			 


/*///////////////////////////////////////////////////////
// CInstr__Output
*/

void CInstr__Output(CInstr* pthis)
	{

	switch(pthis->m_iinstr)
		{
	case INSTR_LABEL:
	case INSTR_LBL:
		printf("L%d:\n",pthis->m_arg.m_wval);
		return;
	case INSTR_REGFREE:
		CRegTable__RegFree(&(g_psem->m_regtable),pthis->m_arg.m_wval);
		return;
	case INSTR_RESETSTACK:
		/*g_cstackextra = g_cbasestack;*/
		return;
	case INSTR_REGALLOC:
		CRegTable__RegAlloc(&(g_psem->m_regtable),pthis->m_arg.m_wval);
		return;
		}

	CSemantics__BindInstr(g_psem,pthis);

	printf("\t%s ",g_rginstrs[pthis->m_iinstr].m_szname);
	
	CInstr__OutputArgs(pthis);

	printf("\n");

	}

UInstrArg CInstr__GetArg(CInstr* pthis, int iarg)
	{
	switch(iarg)
		{
	case 0:
		return pthis->m_arg;
	case 1:
		return pthis->m_arg2;
	case 2:
		return pthis->m_arg3;
	default:
		AssertStd(fFalse);	/* we shouldn't get here */
		return pthis->m_arg;/* have to return something to compile*/
		}
	}
		
/*////////////////////////////////////////////////////////
// CInstr__OutputArgs
*/

void CInstr__OutputArgs(CInstr* pthis)
	{
	int i;
	int cargs = g_rginstrs[pthis->m_iinstr].m_cargs;
	int fComma = fTrue;
	
	for(i=0;i<cargs;i++)
		{
		UInstrArg arg = CInstr__GetArg(pthis,i);
		
		switch(g_rginstrs[pthis->m_iinstr].m_rgargtypes[i])
			{
		case ARGTYPE_FLOAT:
			printf("%lf",arg.m_fpval);
			break;
		case ARGTYPE_INT:
			printf("%d",arg.m_wval);
			break;
		case ARGTYPE_MEM:
			printf("%s",arg.m_szval);
			fComma = fFalse;
			break;
		case ARGTYPE_LABEL:
			printf("L%d",arg.m_wval);
			break;
		case ARGTYPE_NONE:
			break;
		case ARGTYPE_REGIND:
			printf("%d(",arg.m_wval);
			fComma = fFalse;
			break;
		case ARGTYPE_REG:
			switch(arg.m_wval)
				{
			case INTCALLREG:
				printf("$a0");
				break;
			case FLOATCALLREG:
				printf("$f12");
				break;
			case RETURNREG:
				printf("$v0");
				break;
			case REGRETURNADDR:
				printf("$ra");
				break;
			case REGFRAME:
				printf("$fp");
				break;
			case REGSTACK:
				printf("$sp");
				break;
			case REGZERO:
				printf("$0");
				break;
			case REGGLOBAL:
				printf("$gp");
				break;
			case REGINVALID:
				AssertStd(fFalse);
				break;
			default:
				printf("$");
				switch(arg.m_wval & 0xf0000000)
					{
				case REGADDR:
					printf("a");
					break;
				case REGTEMP:
					printf("t");
					break;
				case REGFLOAT:
					printf("f");
					break;
				case REGSAVE:
					printf("s");
					break;
				default:
					AssertStd(fFalse);
					}
				printf("%d",arg.m_wval & REGMAX);
				break;
				}
			break;
		default:
			AssertStd(fFalse);
			}
		if(fComma && (i<(cargs -1)))
			{
			printf(",");
			}
		if((i==(cargs-1)) && (g_rginstrs[pthis->m_iinstr].m_rgargtypes[i-1] == ARGTYPE_REGIND))
			{
			printf(")");
			}
		}

	}

CInstr* CInstr__Set(CInstr* pthis, int iinstr, int wval1, double fpval1,char* szarg1,
	int wval2, double fpval2, char* szarg2,
	int wval3, double fpval3, char* szarg3)
	{
	pthis->m_iinstr = iinstr;
	SetArg(&(pthis->m_arg),wval1,fpval1,szarg1,iinstr,0);
	SetArg(&(pthis->m_arg2),wval2,fpval2,szarg2,iinstr,1);
	SetArg(&(pthis->m_arg3),wval3,fpval3,szarg3,iinstr,2);
	pthis->m_iargtype = g_rginstrs[iinstr].m_rgargtypes[0];
	pthis->m_iargtype2 = g_rginstrs[iinstr].m_rgargtypes[1];
	pthis->m_iargtype3 = g_rginstrs[iinstr].m_rgargtypes[2];
	return pthis;
	}
	
void SetArg(UInstrArg* parg, int wval, double fpval, char* szarg, int iinstr, int i)
	{
	switch(g_rginstrs[iinstr].m_rgargtypes[i])
		{
	case ARGTYPE_FLOAT:
		parg->m_fpval = fpval;
		break;
	case ARGTYPE_REG:
	case ARGTYPE_REGIND:
	case ARGTYPE_LABEL:
	case ARGTYPE_INT:
		parg->m_wval = wval;
		break;
	case ARGTYPE_MEM:
	case ARGTYPE_STRING:
		parg->m_szval = szarg;
		break;
	case ARGTYPE_NONE:
		break;
	default:
		AssertStd(fFalse);
		}
	}

BOOLFLAG INSTRKEY__FEquivalent(INSTRKEY* pinstr1, INSTRKEY* pinstr2)
	{
	return *pinstr1 == *pinstr2;
	}


INSTRKEY* CInstr__GetKey(CInstr* pthis)
	{
	return &(pthis->m_iinstr);
	}


/*//////////////////////////////////////////////////////////////////
// class CInstrList
*/

LIST_TEMPLATE_DEFINITION(CInstrList,CInstr,INSTRKEY)
LIST_TEMPLATE_DEFINITION(CInstrListList,CInstrListRef,NOKEY);

NOKEY * CInstrListRef__GetKey(CInstrListRef * pthis)
	{
	return NULL;
	}


CLASS_CONSTRUCTOR(CInstrListRef)
	{
	*pthis = NULL;
	return pthis;
	}

CLASS_DESTRUCTOR(CInstrListRef)
	{
	if(*pthis)
		{
		DELETEOBJECT(CInstrList,*pthis);
		}
	return pthis;
	}

void CInstrListRef__Assign(CInstrListRef* pthis, CInstrListRef* pother)
	{
	*pthis = *pother;
	}

/*///////////////////////////////////////////////////////
// CInstrList__NewList
*/
CInstrList* CInstrList__NewList()
	{
	CInstrList* pinstrlist = NEWOBJECT(CInstrList);
	CInstrListList__InsertAfter(&(g_psem->m_lstlst),&pinstrlist);
	return pinstrlist;
	}

/*///////////////////////////////////////////////////////
// CInstrList__FreeList()
*/

void CInstrList__FreeList(CInstrList* pthis)
	{
	/*if(pthis)
		{
		DELETEOBJECT(CInstrList,pthis);
		}
	pthis = NULL;*/
	CInstrList__Clear(pthis);
	}

/*///////////////////////////////////////////////////////
// CInstrList__CatLists
*/

CInstrList* CInstrList__CatLists(CInstrList* pthis, CInstrList* pother)
	{
	int citems;
	CNODECInstrListCInstr * pcurrent;
	int i;

	citems = CInstrList__CItemsGet(pother);

	pcurrent = pother->pcurrent;

	CInstrList__Rewind(pother);

	while(CInstrList__FMoveNext(pthis));

	for(i = 0;i<citems;i++)
		{
		CInstrList__InsertAfter(pthis,CInstrList__ItemGet(pother));
		CInstrList__FMoveNext(pother);
		}
	pother->pcurrent = pcurrent;

	return pthis;
	}

/*///////////////////////////////////////////////////////
// CInstrList__CatAndFree
*/

CInstrList* CInstrList__CatAndFree(CInstrList* pthis, CInstrList* pother)
	{
	CInstrList__CatLists(pthis,pother);
	CInstrList__FreeList(pother);
	return pthis;
	}


/*///////////////////////////////////////////////////////
// CInstrList__Output
*/

void CInstrList__Output(CInstrList* pthis)
	{
	int citems;
	int i;
	citems = CInstrList__CItemsGet(pthis);
	CInstrList__Rewind(pthis);
	printf("\n");	

	for(i=0;i<citems;i++)
		{
		CInstr__Output(CInstrList__ItemGet(pthis));
		CInstrList__FMoveNext(pthis);
		}

	}

void CInstrList__AddInstr(CInstrList* pthis, CInstr* pinstr)
	{
	CInstrList__InsertAfter(pthis,pinstr);
	}

CAttr* CAttr__CombineCode(CAttr* pthis,CAttr* pother)
	{
	if(!(pthis->m_pinstrlist))
		{
		pthis->m_pinstrlist = pother->m_pinstrlist;
		pother->m_pinstrlist = NULL;
		return pthis;
		}
	if(!(pother->m_pinstrlist))
		{
		return pthis;
		}
	CInstrList__CatAndFree(pthis->m_pinstrlist,pother->m_pinstrlist);
	return pthis;
	}


/*//////////////////////////////////////////////////////////////////////
// class CStringServer
*/

CLASS_CONSTRUCTOR(CStringServer)
	{
	pthis->m_isz = 0;
	return pthis;
	}

char* CStringServer__SzStoreSz(CStringServer* pthis, char* szin)
	{
	char* sznew;
	sznew = strcpy(pthis->m_rgrgsz[pthis->m_isz],szin);
	pthis->m_isz = (pthis->m_isz + 1) % MAX_STRINGSERVER_STRINGS;
	return sznew;
	}


/*///////////////////////////////////////////////////////////
// class STRINGTEMP
*/

CLASS_CONSTRUCTOR(TEMPSTRING)
	{
	*pthis = NULL;
	return pthis;
	}

CLASS_DESTRUCTOR(TEMPSTRING)
	{
	return pthis;
	}

TEMPSTRING* TEMPSTRING__GetKey(TEMPSTRING* pthis)
	{
	return pthis;
	}

void TEMPSTRING__Assign(TEMPSTRING* pthis, TEMPSTRING* pother)
	{
	*pthis = *pother;
	}

BOOLFLAG TEMPSTRING__FEquivalent(TEMPSTRING* pthis, TEMPSTRING* pother)
	{
	return *pthis == *pother;
	}

LIST_TEMPLATE_DEFINITION(CTEMPLIST,TEMPSTRING,TEMPSTRING);	
