/*/////////////////////////////////////////////
// regalloc.h
// this file declares classes for register allocation
// here are the classes:
// 1. CPhysReg
// 2. CVirtReg
// 3. CRegTable
*/

#if !defined(_REGALLOCH)
#define _REG_ALLOCH

#include "std.h"
#include "stdtype.h"

typedef struct _CVirtReg
	{
	int m_idphysreg;	/* index of physical register in reg table*/
	int m_idvirtreg;	/* register id */
	int m_cboffset;	/* location for storage in stack */
	int m_ffloat;
	int m_fShared;
	} CVirtReg;

CLASS_CONSTRUCTOR(CVirtReg);
CLASS_DESTRUCTOR(CVirtReg);

int CVirtReg__GetID(CVirtReg* pthis);
int CVirtReg__GetPhysID(CVirtReg* pthis);
void CVirtReg__SetPhysReg(CVirtReg* pthis, int idphysreg);
int CVirtReg__GetStackOffset(CVirtReg* pthis);
void CVirtReg__StoreReg(CVirtReg* pthis, int cboffset);

typedef int REGKEY;
typedef REGKEY* PREGKEY;

typedef CVirtReg* PVIRTREG;
CLASS_CONSTRUCTOR(PVIRTREG);
CLASS_DESTRUCTOR(PVIRTREG);


LIST_TEMPLATE_DECLARATION(CRegList,PVIRTREG,REGKEY);

#define REGTABLESIZE 32

HASHTABLE_TEMPLATE_DECLARATION(CVirtRegStore,CVirtReg,REGKEY);

typedef struct _CPhysReg
	{
	int m_idreg;
	int m_idvirtreg;
	CRegList m_reglist;
	} CPhysReg;

CLASS_CONSTRUCTOR(CPhysReg);
CLASS_DESTRUCTOR(CPhysReg);

int CPhysReg__GetID(CPhysReg* pthis);
CVirtReg* CPhysReg__GetCurrentOwner(CPhysReg* pthis);
BOOLFLAG CPhysReg__FSetOwner(CPhysReg* pthis, CVirtReg* pvirt);
void CPhysReg__RemoveUser(CPhysReg* pthis, int idvirtreg);
void CPhysReg__SaveReg(CPhysReg* pthis, int cboffset);

#define MAX_INTREG 16
#define MAX_FLOATREG 14
#define MAX_VIRTREG 65535

typedef struct _CRegTable
	{
	CPhysReg m_genreg[MAX_INTREG];
	CPhysReg m_floatreg[MAX_FLOATREG];
	CVirtRegStore m_tblreg;
	int m_cgenreg;
	int m_cfpreg;
	int m_curintreg;
	int m_curfloatreg;
	int m_curvirtreg;
	int m_cbtempstack;
	int m_calloced;
	} CRegTable;

CLASS_CONSTRUCTOR(CRegTable);
CLASS_DESTRUCTOR(CRegTable);

int CRegTable__RegAlloc(CRegTable* pthis, int idvirt);
void CRegTable__RegFree(CRegTable* pthis, int idvirt);
int CRegTable__CGetGenRegCount(CRegTable* pthis);
int CRegTable__CGetFloatRegCount(CRegTable* pthis);
CPhysReg* CRegTable__GetPhysReg(CRegTable* pthis, int idphys, BOOLFLAG ffloat);
CVirtReg* CRegTable__GetVirtReg(CRegTable* pthis, int idvirtreg);
int CRegTable__RealRegFromPhysID(CRegTable* pthis, int idphysreg, BOOLFLAG);
int CRegTable__RealRegFromVirtID(CRegTable* pthis, int idvirt);
CPhysReg* CRegTable__PhysRegFromVirt(CRegTable* pthis, CVirtReg* vreg);
void CRegTable__Reset(CRegTable* pthis);
int CRegTable__RegRequest(CRegTable* pthis, BOOLFLAG ffloat);

#define REGMAX 0x0fffffff

#define REGADDR 0x10000000
#define REGZERO 0x40000000
#define REGTEMP 0x00000000
#define REGFLOAT 0x20000000
#define REGINVALID 0x50000000
#define REGGLOBAL 0x60000000
#define REGRETURNADDR 0x30000000
#define INTCALLREG 0xafffffff
#define FLOATCALLREG 0xbfffffff
#define RETURNREG 0xcfffffff
#define FLOATRETURNREG 0x8fffffff
#define REGFRAME 0xdfffffff
#define REGSTACK 0xefffffff
#define REGSAVE 0x90000000

#define STACKITEMSIZE 4

#endif /* defined(_REGALLOC_H) */