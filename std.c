/*//////////////////////////////////////////*/
/* std.c									*/

#include <assert.h>
#include "std.h"

/* globals */
#if defined(_WINDOWS)
CRITICAL_SECTION g_crsMemCount;			  
#endif

ERRORREF g_LastError;
int HEAPCHECK;

/* static member intialization */

int CHeap__m_cblocks = 0;

#if !defined(_UNIX) && !defined(_STRICT_ANSI_C)
void AssertFSz(BOOLFLAG fAssertion, int nline, char* szFile, char* szMsg)
	{
	if (!fAssertion)
		{
		char szAssertBuf[MAXASSERTBUF];
		char szTempBuf[MAXTEMPBUF];

		_itoa(nline,szTempBuf,10);
		strcpy(szAssertBuf,"Assertion Failure in line ");
		szTempBuf[MAXTEMPBUF - 1]= '\0';
		strcat(szAssertBuf,szTempBuf);
		strcat(szAssertBuf," of file ");
		szFile[_MAX_PATH -1] = '\0';
		strcat(szAssertBuf,szFile);

		if (szMsg)
			{
			szMsg[MAXASSERTBUF / 2] = '\0';
			strcat(szAssertBuf,"\n");
			strcat(szAssertBuf,szMsg);
			}

		strcat(szAssertBuf,"\n");
#if !defined(_CONSOLE)
		strcat(szAssertBuf,"Press OK to continue, Cancel to Debug");
		if (MessageBox(
			NULL,
			szAssertBuf,
			"Assertion Failure",
			MB_APPLMODAL | MB_ICONSTOP | MB_OKCANCEL) == IDCANCEL)
			{
			DebugBreak();
			}
#else /* !defined(_CONSOLE) */
		printf("%s\n",szAssertBuf);

		DebugBreak();

#endif /* defined(_CONSOLE) */
		}
	}
#endif /* !defined(_UNIX) && !defined(_STRICT_ANSI_C) */

CLASS_CONSTRUCTOR(CHeap)
	{
	AssertStd(!CHeap__m_cblocks);

	INITIALIZE_CRITICAL_SECTION(&g_crsMemCount);
	
	return pthis;
	}

CLASS_DESTRUCTOR(CHeap)
	{
#if defined _DEBUG
	printf("%d objects not freed\n",CHeap__m_cblocks);
#endif
	AssertStdSz(!CHeap__m_cblocks,"Some memory objects have not been freed!");
	return pthis;
	}

void* CHeap__malloc(size_t cb)
	{
#if defined(_DEBUG)
	void* pv;
#if defined(_MEMDUMPALLOC)
	FILE* fp;
#endif /* defined (_MEMDUMP) */
#endif /* defined(_DEBUG) */

	AssertStd(cb);
#if defined(_DEBUG)
	pv = 
#else /* defined(_DEBUG) */
	return
#endif /* defined(_DEBUG) */
		malloc(cb);
#if defined(_MEMDUMPALLOC)
	fp = fopen("mem.txt","a+");
	fprintf(fp,"%p\n",pv);
	fclose(fp);
#endif /* defined(_MEMDUMP) */
#if defined(_DEBUG)
	AssertStd((BOOLFLAG)pv);
	if (pv)
		{
		CHeap__m_cblocks++;
		}
	HEAPCHECK +=(int)pv;
	return pv;
#endif /* defined(_DEBUG) */
	
	}

	
void CHeap__free(void* pv)
	{
#if defined(_DEBUG)
#if defined (_MEMDUMPFREE)
	FILE* fp;
#endif /* defined (_MEMDUMP) */
#endif
	free(pv);

#if defined(_DEBUG)
#if defined(_MEMDUMPFREE)
	fp = fopen("mem.txt","a+");
	fprintf(fp,"%p\n",pv);
	fclose(fp);
#endif	
	if(pv)CHeap__m_cblocks--;
	HEAPCHECK -=(int)pv;
#endif /* defined(_DEBUG) */
	}

void* CHeap__realloc(void* pv, size_t cb)
	{
	AssertStd((BOOLFLAG)pv);
	return realloc(pv,cb);
	}

ERRORREF StdGetLastError()
	{
	return g_LastError;
	}


