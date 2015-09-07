/*//////////////////////////
// regalloc.c
*/

#include "regalloc.h"

CLASS_CONSTRUCTOR(CVirtReg)
	{
	pthis->m_idphysreg = REGINVALID;
	pthis->m_idvirtreg = 0;
	pthis->m_cboffset = 0;
	pthis->m_ffloat = fFalse;
	pthis->m_fShared = fFalse;
	return pthis;
	}

CLASS_DESTRUCTOR(CVirtReg)
	{
	return pthis;
	}

BOOLFLAG REGKEY__FEquivalent(REGKEY* pthis, REGKEY* pother)
	{
	return *pthis == *pother;
	}

REGKEY* CVirtReg__GetKey(CVirtReg* pthis)
	{
	return &(pthis->m_idvirtreg);
	}

void CVirtReg__Assign(CVirtReg* pthis, CVirtReg* pother)
	{
	*pthis = *pother;
	}

int CVirtReg__GetID(CVirtReg* pthis)
	{
	return pthis->m_idvirtreg;
	}

int CVirtReg__GetPhysID(CVirtReg* pthis)
	{
	return pthis->m_idphysreg;
	}

void CVirtReg__SetPhysReg(CVirtReg* pthis, int idphysreg)
	{
	pthis->m_idphysreg = idphysreg;
	}

int CVirtReg__GetStackOffset(CVirtReg* pthis)
	{
	return pthis->m_cboffset;
	}

void CVirtReg__StoreReg(CVirtReg* pthis, int cboffset)
	{
	pthis->m_cboffset = cboffset;
	}



CLASS_CONSTRUCTOR(PVIRTREG)
	{
	*pthis = NULL;
	return pthis;
	}

CLASS_DESTRUCTOR(PVIRTREG)
	{
	return pthis;
	}

REGKEY* PVIRTREG__GetKey(PVIRTREG* pthis)
	{
	return &((*pthis)->m_idvirtreg);
	}

void PVIRTREG__Assign(PVIRTREG* pthis, PVIRTREG* pother)
	{
	*pthis = *pother;
	}

int CVirtRegStore__HashFunc(CVirtRegStore* pthis, REGKEY* pkey)
	{
	return *pkey % pthis->m_size;
	}

LIST_TEMPLATE_DEFINITION(CRegList,PVIRTREG,REGKEY);


HASHTABLE_TEMPLATE_DEFINITION(CVirtRegStore,CVirtReg,REGKEY);

CLASS_CONSTRUCTOR(CRegTable)
	{
	int i,j;
	int ctblsize = REGTABLESIZE;

	CALL_GENERIC_CONSTRUCTOR(CVirtRegStore,&(pthis->m_tblreg),&ctblsize);

	for(i = 0; i < MAX_INTREG;i++)
		{
		CALL_CONSTRUCTOR(CPhysReg,&(pthis->m_genreg[i]));
		pthis->m_genreg[i].m_idreg = i;
		}

	for(j = 0; j < MAX_FLOATREG;j++)
		{
		CALL_CONSTRUCTOR(CPhysReg,&(pthis->m_floatreg[j]));
		pthis->m_floatreg[j].m_idreg = j;
		}

	pthis->m_cgenreg = MAX_INTREG;
	pthis->m_cfpreg = MAX_FLOATREG;
	pthis->m_curintreg = 0;
	pthis->m_curfloatreg = 0;
	pthis->m_cbtempstack = 0;
	pthis->m_curvirtreg = 0;
	pthis->m_calloced = 0;
	return pthis;
	}

CLASS_DESTRUCTOR(CRegTable)
	{
	int i,j;
	CALL_DESTRUCTOR(CVirtRegStore,&(pthis->m_tblreg));

	for(i = 0; i < MAX_INTREG;i++)
		{
		CALL_DESTRUCTOR(CPhysReg,&(pthis->m_genreg[i]));
		}

	for(j = 0; j < MAX_FLOATREG;j++)
		{
		CALL_DESTRUCTOR(CPhysReg,&(pthis->m_floatreg[j]));
		}
	return pthis;
	}

int CRegTable__RegAlloc(CRegTable* pthis, int idvirtreg)
	{
	int idphysreg;
	CPhysReg* rgregvec;
	CVirtReg* pnew = CVirtRegStore__Find(&(pthis->m_tblreg),&idvirtreg);
;	pthis->m_calloced++;

	if(pnew->m_ffloat)
		{
		idphysreg = pthis->m_curfloatreg;
		rgregvec = 	pthis->m_floatreg;
		pthis->m_curfloatreg = (pthis->m_curfloatreg + 1) % MAX_FLOATREG;
		}
	else
		{
		idphysreg = pthis->m_curintreg;
		rgregvec = pthis->m_genreg;
		pthis->m_curintreg = (pthis->m_curintreg + 1) % MAX_INTREG;
		}

	if(CPhysReg__FSetOwner(&(rgregvec[idphysreg]),pnew))
		{
		pnew->m_cboffset = pthis->m_cbtempstack;
		pthis->m_cbtempstack+= STACKITEMSIZE;
		pnew->m_fShared = fTrue;
		}
	pnew->m_idphysreg = idphysreg;
	return idphysreg;	
	}

void CRegTable__RegFree(CRegTable* pthis, int idvirt)
	{
	CVirtReg* poldreg;
	CPhysReg* poldphys;
	BOOLFLAG fSuccess;
	
	pthis->m_calloced--;

	poldreg = CVirtRegStore__Find(&(pthis->m_tblreg),&idvirt);
	if(poldreg->m_ffloat)
		{
		poldphys = &(pthis->m_floatreg[CVirtReg__GetPhysID(poldreg)]);
		}
	else
		{
		poldphys = &(pthis->m_genreg[CVirtReg__GetPhysID(poldreg)]);
		}

	CPhysReg__RemoveUser(poldphys,idvirt);
	fSuccess = CVirtRegStore__FRemove(&(pthis->m_tblreg),&idvirt);
	AssertStd(fSuccess);
	}
	

int CRegTable__CGetGenRegCount(CRegTable* pthis)
	{
	return pthis->m_cgenreg;
	}

int CRegTable__CGetFloatRegCount(CRegTable* pthis)
	{
	return pthis->m_cfpreg;
	}

CPhysReg* CRegTable__GetPhysReg(CRegTable* pthis, int idphys, BOOLFLAG ffloat)
	{
	if(ffloat)
		{
		return &(pthis->m_floatreg[idphys]);
		}
	else
		{
		return &(pthis->m_genreg[idphys]);
		}
	}

CVirtReg* CRegTable__GetVirtReg(CRegTable* pthis, int idvirt)
	{
	return CVirtRegStore__Find(&(pthis->m_tblreg),&idvirt);
	}


int CRegTable__RealRegFromPhysID(CRegTable* pthis, int idphys, BOOLFLAG ffloat)
	{
	if(!ffloat)
		{
		AssertStd(idphys >=0 && idphys <= 15);

		if(idphys > 7)
			{
			return REGSAVE | idphys % 8;
			}
		else
			{
			return REGTEMP | idphys;
			}
		}
	else
		{
		AssertStd(idphys >=0 && idphys <= 14);
		return REGFLOAT | (2 * idphys + 2 + (idphys >= 5)? 2 : 0);
		}
	}

int CRegTable__RealRegFromVirtID(CRegTable* pthis, int idvirt)
	{
	CVirtReg* pvreg;
	pvreg = CVirtRegStore__Find(&(pthis->m_tblreg),&idvirt);

	return CRegTable__RealRegFromPhysID(pthis,
		CVirtReg__GetPhysID(pvreg),pvreg->m_ffloat);
	}

int CRegTable__RegRequest(CRegTable* pthis, BOOLFLAG ffloat)
	{
	CVirtReg vrnew;
	CVirtReg* pnew;
	int idvirtreg;
	
	CALL_CONSTRUCTOR(CVirtReg,&vrnew);
	idvirtreg = pthis->m_curvirtreg;
	pthis->m_curvirtreg = (pthis->m_curvirtreg + 1) % MAX_VIRTREG;

	vrnew.m_idvirtreg = idvirtreg;
	vrnew.m_ffloat = ffloat;
		
	pnew = CVirtRegStore__Add(&(pthis->m_tblreg),&vrnew);
	CALL_DESTRUCTOR(CVirtReg,&vrnew);
	
	return idvirtreg;
	}


void CRegTable__Reset(CRegTable* pthis)
	{
	CALL_DESTRUCTOR(CRegTable,pthis);
	CALL_CONSTRUCTOR(CRegTable,pthis);
	}

CLASS_CONSTRUCTOR(CPhysReg)
	{
	pthis->m_idreg = 0;
	pthis->m_idvirtreg = 0;
	CALL_CONSTRUCTOR(CRegList,&(pthis->m_reglist));
	return pthis;
	}

CLASS_DESTRUCTOR(CPhysReg)
	{
	CALL_DESTRUCTOR(CRegList,&(pthis->m_reglist));
	return pthis;
	}

int CPhysReg__GetID(CPhysReg* pthis)
	{
	return pthis->m_idreg;
	}

CVirtReg* CPhysReg__GetCurrentOwner(CPhysReg* pthis)
	{
	return *(CRegList__ItemGet(&(pthis->m_reglist)));
	}

BOOLFLAG CPhysReg__FSetOwner(CPhysReg* pthis, CVirtReg* pvirt)
	{
	int fShared = fFalse;

	if(CRegList__CItemsGet(&(pthis->m_reglist)))
		{
		(*(CRegList__ItemGet(&(pthis->m_reglist))))->m_fShared = fTrue;
		fShared = fTrue;
		}
	CRegList__InsertAfter(&(pthis->m_reglist),&pvirt);

	return fShared;
	}

void CPhysReg__RemoveUser(CPhysReg* pthis, int idvirtreg)
	{
	CVirtReg* pvirtfound;
	pvirtfound = *(CRegList__ItemGet(&(pthis->m_reglist)));
	AssertStd(pvirtfound && pvirtfound->m_idvirtreg == idvirtreg);
	CRegList__Delete(&(pthis->m_reglist));
	}

