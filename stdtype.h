/*///////////////////////////////////
// stdtype.h					   
// Standard type templates
// Adam Edwards
// adame@engin.umich.edu
// Student
*/

#error Fix CopyFrom
// yo! -- fix copyfrom -- it has a bug in it
// when setting the current pointer -- don't
// set it to the other's current -- set it to
// the newly inserted node when the other's 
// current node is the same as its original current
// at the end, you still must restore the original
// current of the old list


#if !defined(_STDTYPE_H)
#define _STDTYPE_H

#include "std.h"

/*//////////////////////////////////////////////
// The following macros are designed to 
// simulate C++ templates.  They prevent me
// from having to write several linked lists
// over and over again, etc.
*/

/*//////////////////////////////////////////
// The LIST_TEMPLATE macros generate a
// cursor based list.  List operations, such
// as ItemGet and Delete take place at the
// current position, wherever the cursor
// is at.  
*/

/*//////////////////////////////////////////////
// The Hash table template creates a hashtable
// with a specifiable size.  This hash table
// uses chaining (in fact, it uses the 
// LIST_TEMPLATE macro to make its chains)
*/


typedef struct _NOKEY
	{
	int dummy;
	} NOKEY;

#define LIST_TEMPLATE_DECLARATION(y,x,k)	\
\
typedef struct _CNODE##y##x \
	{	\
	x item;	\
	struct _CNODE##y##x * pnext;	\
	struct _CNODE##y##x * pprev;	\
	} CNODE##y##x;	\
\
typedef CNODE##y##x * PNODE##y##x;	\
typedef struct __##y	\
	{	\
	PNODE##y##x phead;	\
	PNODE##y##x pcurrent;	\
	int m_citems;	\
	} y ;	\
CLASS_CONSTRUCTOR(CNODE##y##x);	\
CLASS_DESTRUCTOR(CNODE##y##x);	\
\
CLASS_CONSTRUCTOR(y);	\
CLASS_DESTRUCTOR(y);	\
int y##__CItemsGet( y * pthis);	\
x * y##__ItemGet( y * pthis);	\
x * y##__InsertBefore( y * pthis, x * pitem);	\
x * y##__InsertAfter( y * pthis, x * pitem);	\
void y##__Delete( y * pthis);		\
BOOLFLAG y##__FIsEmpty( y * pthis);	 \
void y##__Rewind( y * pthis);	\
x * y##__Find( y * pthis, k * ptarget);	\
BOOLFLAG y##__FMoveNext( y * pthis);	\
BOOLFLAG y##__FMovePrevious( y * pthis);	\
void x##__Assign(x * pthis, x * other);	  \
void y##__CopyFrom(y * pthis, y * pother);	\
k * x##__GetKey(x * pthis);	\
BOOLFLAG k##__FEquivalent(k * pthis, k * pother);	\
void y##__Clear(y * pthis);

#define LIST_TEMPLATE_DEFINITION(y,x,k)	\
CLASS_CONSTRUCTOR(CNODE##y##x)	\
	{	\
	CALL_CONSTRUCTOR(x,&(pthis->item));  \
	return pthis;\
	}\
CLASS_DESTRUCTOR(CNODE##y##x)	\
	{	\
	CALL_DESTRUCTOR(x,&(pthis->item));		\
	return pthis;	\
	}	\
CLASS_CONSTRUCTOR(y)	\
	{	\
	pthis->phead = pthis ->pcurrent = NULL;	\
	pthis->m_citems = 0;	\
	return pthis;	\
	}	\
\
CLASS_DESTRUCTOR(y)	\
	{	\
	PNODE##y##x pcur;	\
	PNODE##y##x pprev;	\
	pcur = pthis->phead;	\
	while(pcur)	\
		{	\
		pprev = pcur;	\
		pcur = pcur->pnext;	\
		DELETEOBJECT(CNODE##y##x,pprev);\
		}		\
	return pthis;	\
	}\
\
int y##__CItemsGet( y * pthis)	\
	{	\
	return pthis->m_citems;	\
	}	\
\
x * y##__ItemGet( y * pthis)	\
	{	\
	return &(pthis->pcurrent->item);	\
	}	\
\
BOOLFLAG y##__FIsEmpty( y * pthis)	 \
	{	\
	AssertStd((pthis->m_citems==0)==(pthis->phead==NULL));	\
	return pthis->m_citems == 0;	\
	}	\
\
void y##__Rewind( y * pthis)	\
	{	\
	pthis->pcurrent=pthis->phead;	\
	}	\
\
x * y##__Find( y * pthis, k * ptarget)	\
	{	\
	PNODE##y##x pcur;	\
	pcur = pthis->pcurrent;	\
	while(pcur)	\
		{	\
		if(k##__FEquivalent(x##__GetKey(&(pcur->item)),ptarget))	\
			{	\
			pthis->pcurrent = pcur;	\
			return &(pcur->item);	\
			}	\
		pcur = pcur->pnext;	\
		}	\
	return NULL;	\
	}	\
\
BOOLFLAG y##__FMoveNext( y * pthis)	\
	{	\
	if(pthis->pcurrent)	\
		{	\
		if(pthis->pcurrent->pnext)	\
			{	\
			pthis->pcurrent = pthis->pcurrent->pnext;	\
			return fTrue;	\
			}	\
		}	\
	return fFalse;	\
	}	\
\
BOOLFLAG y##__FMovePrevious( y * pthis)	\
	{	\
	if(pthis->pcurrent)	\
		{	\
		if(pthis->pcurrent->pprev)	\
			{	\
			pthis->pcurrent = pthis->pcurrent->pprev;	\
			return fTrue;	\
			}	\
		}	\
	return fFalse;	\
	}	\
\
x * y##__InsertBefore( y * pthis, x * pitem)	\
	{	\
	PNODE##y##x pnew;	\
	pnew = (PNODE##y##x) NEWOBJECT(CNODE##y##x);	\
	x##__Assign(&(pnew->item),pitem);	\
	pnew->pnext = pnew->pprev = NULL;	\
\
	if (pthis->pcurrent)	\
		{	\
		if (pthis->pcurrent->pprev)	\
			{	\
			AssertStd((pthis->pcurrent->pprev->pnext == pthis->pcurrent));	\
			pthis->pcurrent->pprev->pnext=pnew;	\
			pnew->pprev=pthis->pcurrent->pprev;	\
			pthis->pcurrent->pprev=pnew;	\
			pnew->pnext=pthis->pcurrent;	\
			}	\
		else	\
			{	\
			pnew->pnext=pthis->pcurrent;	\
			pthis->pcurrent->pprev= pnew;	\
			pthis->phead = pnew;	\
			}	\
		}	\
	else	\
		{	\
		pthis->phead = pnew;	\
		}	\
	pthis->m_citems++;	\
	pthis->pcurrent=pnew;	\
	return &(pnew->item);	\
	}	 \
x * y##__InsertAfter( y * pthis, x * pitem)	\
	{	\
	PNODE##y##x pnew;	\
	pnew = (PNODE##y##x) NEWOBJECT(CNODE##y##x);	\
	x##__Assign(&(pnew->item),pitem);	\
	pnew->pnext = pnew->pprev = NULL;	\
\
	if (pthis->pcurrent)	\
		{	\
		if (pthis->pcurrent->pnext)	\
			{	\
			AssertStd((pthis->pcurrent->pnext->pprev == pthis->pcurrent));	\
			pthis->pcurrent->pnext->pprev=pnew;	\
			pnew->pnext=pthis->pcurrent->pnext;	\
			pthis->pcurrent->pnext=pnew;	\
			pnew->pprev=pthis->pcurrent;	\
			}	\
		else	\
			{	\
			pnew->pprev=pthis->pcurrent;	\
			pthis->pcurrent->pnext= pnew;	\
			}	\
		}	\
	else	\
		{	\
		pthis->phead = pnew;	\
		}	\
	pthis->m_citems++;	\
	pthis->pcurrent=pnew;	\
	return &(pnew->item);	\
	}	\
void y##__CopyFrom(y * pthis, y * pother)	\
	{	\
	PNODE##y##x pcur;	\
	CALL_DESTRUCTOR(y,pthis);	\
	CALL_CONSTRUCTOR(y,pthis);	\
	pcur = pother->pcurrent;	\
	y##__Rewind(pother);	\
	do	\
		{	\
		if (y##__FIsEmpty(pother))	\
			{	\
			break;	\
			}	\
		y##__InsertAfter(pthis,y##__ItemGet(pother));	\
		}while(y##__FMoveNext(pother));	\
	pother->pcurrent = pthis->pcurrent = pcur;	\
	}	\
void y##__Delete( y * pthis)	\
	{	\
	PNODE##y##x pnext,pprev,pheadtemp,pcurtemp;	\
	AssertStd((BOOLFLAG)pthis->pcurrent);	 \
	pnext=pthis->pcurrent->pnext;	\
	pprev=pthis->pcurrent->pprev;	\
	pheadtemp = pthis->phead;	\
	pcurtemp = pthis->pcurrent; \
	DELETEOBJECT(CNODE##y##x,pthis->pcurrent);	\
	if(pprev)	\
		{	\
		pprev->pnext=pnext;	\
		}	\
	if (pnext)	\
		{\
		pnext->pprev=pprev;	\
		pthis->pcurrent = pnext;	\
		}\
	else	\
		{\
		pthis->pcurrent = pprev;	\
		}\
	if(pheadtemp == pcurtemp)	\
		{	\
		pthis->phead = pthis->pcurrent;	\
		}	\
	pthis->m_citems--;	\
	}	\
\
void y##__Clear(y * pthis)	\
	{	\
	CALL_DESTRUCTOR(y,pthis);	\
	CALL_CONSTRUCTOR(y,pthis);	\
	}		



#define HASHTABLE_TEMPLATE_DECLARATION(n,x,k)	\
LIST_TEMPLATE_DECLARATION(_HASHLIST##n##x,x,k);	\
typedef struct _HASH##n##x 	\
	{		\
	_HASHLIST##n##x ** m_rgchains;	\
	int m_size;	\
	} n;	\
CLASS_GENERIC_CONSTRUCTOR(n);\
CLASS_DESTRUCTOR(n);\
int n##__HashFunc(n * pthis,k * pkey);	\
x * n##__Add(n * pthis,x * pitem);	\
BOOLFLAG n##__FRemove(n* pthis, k * pkey);	\
x * n##__Find(n * pthis, k * pitem);	\
void n##__CopyFrom(n * pthis, n * pother);	\
void n##__Clear(n * pthis);

#define HASHTABLE_TEMPLATE_DEFINITION(n,x,k)	\
LIST_TEMPLATE_DEFINITION(_HASHLIST##n##x,x,k)	\
CLASS_GENERIC_CONSTRUCTOR(n)	\
	{	\
	int i;	\
	i = pthis->m_size = *((int*) pvargs);	\
	pthis->m_rgchains = (_HASHLIST##n##x **) STDMALLOC(sizeof(_HASHLIST##n##x *) * pthis->m_size);	\
	while (--i>=0)	\
		{	\
		pthis->m_rgchains[i] = NEWOBJECT(_HASHLIST##n##x);	\
		}	\
	return pthis;	\
	}	\
		 \
CLASS_DESTRUCTOR(n)	\
	{	\
	int i;	\
	i = pthis->m_size;	\
	while (--i>=0)	\
		{	\
		DELETEOBJECT(_HASHLIST##n##x,pthis->m_rgchains[i]);	\
		}	\
	STDFREE(pthis->m_rgchains);	\
	return pthis;	\
	}	\
	\
x * n##__Add(n* pthis, x * pitem)	\
	{	\
	int iloc;	\
	iloc = n##__HashFunc(pthis,x##__GetKey(pitem));	\
	return _HASHLIST##n##x##__InsertAfter(pthis->m_rgchains[iloc],pitem);	\
	}	\
\
BOOLFLAG n##__FRemove(n* pthis, k * pkey)	\
	{	\
	int iloc;	\
	iloc = n##__HashFunc(pthis,pkey);	\
	_HASHLIST##n##x##__Rewind(pthis->m_rgchains[iloc]);	\
	if(_HASHLIST##n##x##__Find(pthis->m_rgchains[iloc],pkey))	\
		{	\
		_HASHLIST##n##x##__Delete(pthis->m_rgchains[iloc]);	\
		return fTrue;	\
		}	\
	return fFalse;	\
	}\
\
x * n##__Find(n * pthis, k * pkey)	\
	{	\
	x * pitem;	\
	int iloc;	\
	iloc = n##__HashFunc(pthis,pkey);		\
	_HASHLIST##n##x##__Rewind(pthis->m_rgchains[iloc]);	\
	if(_HASHLIST##n##x##__FIsEmpty(pthis->m_rgchains[iloc]))	\
		{	\
		return NULL;	\
		}	\
	while(!k##__FEquivalent(x##__GetKey(pitem = _HASHLIST##n##x##__ItemGet(pthis->m_rgchains[iloc])),pkey))	\
		{	\
		if(!_HASHLIST##n##x##__FMoveNext(pthis->m_rgchains[iloc]))	\
			{	\
			return NULL;	\
			}	\
		}	\
		\
	return pitem;	\
	}	\
\
void n##__CopyFrom(n * pthis, n * pother)	\
	{	\
	int i;	\
	n##__Clear(pthis);	\
	for(i=0;i<pthis->m_size;i++)	\
		{	\
		_HASHLIST##n##x##__CopyFrom(	\
			pthis->m_rgchains[i],	\
			pother->m_rgchains[i]);	\
		}	\
	}	\
\
void n##__Clear(n * pthis)	\
	{	\
	CALL_DESTRUCTOR(n,pthis);	\
	CALL_GENERIC_CONSTRUCTOR(n,pthis,&(pthis->m_size));	\
	}	

#endif /* !defined(_STDTYPE_H) */

