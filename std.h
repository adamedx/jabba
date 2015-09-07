/*////////////////////////////////////
// std.h
// Adam Edwards
// adame@engin.umich.edu
// Student
// standard defintions for my projects
*/

#if !defined(_STD_H)
#define _STD_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(_STRICT_ANSI_C)
#include <windows.h>
#endif /* !defined(_STRICT_ANSI_C) */

/* macros */
#define fTrue (1==1)
#define fFalse (1!=1)

#if defined(_DEBUG)
#define MAXASSERTBUF (_MAX_PATH + 1024)
#define MAXTEMPBUF 32
#else
#define MAXASSERTBUF 0
#define MAXTEMPBUF 0
#endif

#if defined(_UNIX) || defined(_STRICT_ANSI_C)
#define AssertStd(x) assert(x)
#define AssertStdSz(x,y) assert(x)
#else /* defined(_UNIX) || defined(_STRICT_ANSI_C) */

#if defined(_DEBUG)
#define AssertStd(x)	\
{				\
    AssertFSz((x),__LINE__,__FILE__,NULL);	\
}
#else /* defined(_DEBUG) */
#define AssertStd(x)
#endif	/* defined(_DEBUG)*/


#if defined(_DEBUG)
#define AssertStdSz(x,y)	\
{                                       \
    AssertFSz((x),__LINE__,__FILE__,(y));	\
}
#else	/* defined(_DEBUG) */
#define AssertStdSz(x,y)
#endif	/* defined(_DEBUG) */
#endif /* defined(_UNIX) */

#if defined(_WINDOWS)
#define ENTER_CRITICAL_SECTION(x) EnterCriticalSection(x)
#define INITIALIZE_CRITICAL_SECTION(x) InitializeCriticalSection(x)
#define LEAVE_CRITICAL_SECTION(x) LeaveCriticalSection(x)
#else /* defined(_WINDOWS) */
#define ENTER_CRITICAL_SECTION(x)
#define INITIALIZE_CRITICAL_SECTION(x)
#define LEAVE_CRITICAL_SECTION(x)
#endif /* defined(_WINDOWS) */


/*/////////////////////////////////////////////////
// abstracting memory allocation to my memory
// routines.  This allows me to keep count of
// allocated blocks and eventually do other things
// like magic cookies...
*/
#define STDMALLOC(x)	CHeap__malloc((x))
#define STDFREE(x)	CHeap__free((x))
#define STDREALLOC(x,y) CHeap__realloc((x),(y))

#define NEWOBJECT(x) CALL_CONSTRUCTOR(x,STDMALLOC(sizeof(x)))
#define NEWOBJECT_WITH_ARGS(x,z)	\
    CALL_GENERIC_CONSTRUCTOR(STDMALLOC(x*sizeof(x)*z))
#define DELETEOBJECT(x,y) STDFREE(CALL_DESTRUCTOR(x,y))

#define ERRORREF_NOERROR 0
#define RESET_LASTERROR g_LastError = ERRORREF_NOERROR
#define SET_LASTERROR(x) g_LastError = (x)


/* constructor/destructor macros*/
/* designed to mimic C++ as much as possible...*/

#define CLASS_CONSTRUCTOR(x)	void* x##__##x(x * pthis)
#define CLASS_GENERIC_CONSTRUCTOR(x) void* x##__##x##pv(x * pthis,void* pvargs)
#define CLASS_DESTRUCTOR(x) void* x##__Destructor(x * pthis)
#define CALL_CONSTRUCTOR(x,y)	x##__##x(y)
#define CALL_GENERIC_CONSTRUCTOR(x,y,z)	x##__##x##pv(y,z)
#define CALL_DESTRUCTOR(x,y) x##__Destructor(y)

/* typedefs */
typedef int BOOLFLAG;
typedef int ERRORREF;

/* prototypes */
void AssertFSz(BOOLFLAG fAssertion, int iline, char* szFile, char* szMsg);

/* classes */

/* class CHeap */

/*/////////////////////////////////////////////////
// class CHeap
// This class abstracts memory allocation -- all
// requests for dynamic memory should go through
// this.  In debug, it keeps track of allocated
// blocks.  When you exit, it asserts if you
// haven't freed everything or you've freed too
// much.
*/
typedef struct _CHeap
    {
    int dummy;
    } CHeap;

/* public */
/* non-static methods */
CLASS_CONSTRUCTOR(CHeap);
CLASS_DESTRUCTOR(CHeap);

/* static methods */
void* CHeap__malloc(size_t cb);
void CHeap__free(void* pv);
void* CHeap__realloc(void* pv, size_t cb);

/* private */
/* static members */
extern int CHeap__m_cblocks;

/* end class CHeap */

/* globals */
extern ERRORREF g_LastError;
extern int HEAPCHECK;
/* prototypes */
ERRORREF StdGetLastError();
#endif /* !defined(_STD_H) */
