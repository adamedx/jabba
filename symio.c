/*///////////////////////////////////
// symio.c							
// Adam Edwards
// adame@engin.umich.edu
// Student
// File IO classes
*/

#include "symio.h"

CLASS_CONSTRUCTOR(CFStream)
	{
	pthis->pfile = NULL;
	return pthis;
	}

CLASS_DESTRUCTOR(CFStream)
	{
	return pthis;
	}

BOOLFLAG CFStream__FOpen(CFStream* pthis, char* szFile, char* pmode)
	{
	return (pthis->pfile = fopen(szFile,pmode)) != NULL;
	}

BOOLFLAG CFStream__FClose(CFStream* pthis)
	{
	return fclose(pthis->pfile) == 0;
	}

int CFStream__WGet(CFStream* pthis)
	{
	return fgetc(pthis->pfile);
	}

BOOLFLAG CFStream__FEof(CFStream* pthis)
	{
	return feof(pthis->pfile);
	}

BOOLFLAG CFStream__FError(CFStream* pthis)
	{
	return ferror(pthis->pfile);
	}

BOOLFLAG CFStream__FReadline(CFStream* pthis, char* pvBuf,int cbMax)
	{
	int ipos = 0;
	char chIn;

	cbMax--;		
	while(ipos < cbMax)
		{
		if ((chIn = CFStream__WGet(pthis)) == chNewline)
			{
			break;
			}

		if (CFStream__FEof(pthis))
			{
			break;
			}

		pvBuf[ipos++] = chIn;
		}

	pvBuf[ipos++] = chEndOfString;

	return fTrue;
	}

void CFStream__SetFromStdlibFile(CFStream* pthis, FILE* pfile)
	{
	pthis->pfile = pfile;
	}

FILE* CFStream__FPGetStdlibFile(CFStream* pthis)
	{
	return pthis->pfile;
	}


/* useful helper functions */


/*////////////////////////////////////////////////////////////
// Forces an Sz to fit into the specified width
// it places the padded or truncated Sz into szDest
*/
char* StretchSz(char* szSource, char* szDest, int nWidth)
	{
	int i;
	strncpy(szDest,szSource,nWidth);
	for(i = strlen(szSource);i<nWidth;i++)
		{
		szDest[i] = ' ';
		}
	szDest[nWidth] = '\0';
	
	return szDest;
	}

/*////////////////////////////////////////////////////////////
// Forces an integer to fit into a string of specified width
// it places the padded or truncated Sz into szDest
*/
char* StretchInt(int wSource, char* szDest, int nWidth)
	{
	int i;
	sprintf(szDest,"%d",wSource);
	for(i = strlen(szDest);i<nWidth;i++)
		{
		szDest[i] = ' ';
		}
	szDest[nWidth] = '\0';
	
	return szDest;
	}

/*/////////////////////////////////////////////////////////////////////////
// Forces an floating point nmber to fit into a string of specified width
// it places the padded or truncated Sz into szDest
*/

char* StretchFloat(double fpSource, char* szDest, int nWidth)
	{
	int i;
	sprintf(szDest,"%lf",fpSource);
	for(i = strlen(szDest);i<nWidth;i++)
		{
		szDest[i] = ' ';
		}
	szDest[nWidth] = '\0';
	
	return szDest;
	}

	
