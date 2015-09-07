/*///////////////////////////////////////
// symio.h	
// Adam Edwards
// adame@engin.umich.edu
// Student
// File IO classes
*/

#if !defined(_SYMIO_H)
#define _SYMIO_H

#include "std.h"

/* classes */

#define CFStream__read "r"
#define CFStream__write "w"
#define CFStream__append "a"
#define CFStream__readwrite_existing "r+"
#define CFStream__readwrite_destroy "w+"
#define CFStream__readappend_create "a+"

#define chNewline '\n'
#define chEndOfString '\0'


/* class CFStream */
typedef struct _CFStream
	{
	/* private */
	FILE* pfile;
	} CFStream;

/* public */
/* non-static methods */
CLASS_CONSTRUCTOR(CFStream);
CLASS_DESTRUCTOR(CFStream);

BOOLFLAG CFStream__FOpen(CFStream* pthis, char* szFile, char* pmode);
BOOLFLAG CFStream__FClose(CFStream* pthis);

int CFStream__WGet(CFStream* pthis);
BOOLFLAG CFStream__FEof(CFStream* pthis);
BOOLFLAG CFStream__FError(CFStream* pthis);
BOOLFLAG CFStream__FReadline(CFStream* pthis, char* pvBuf, int cbMax);

FILE* CFStream__FPGetStdlibFile(CFStream* pthis);
void CFStream__SetFromStdlibFile(CFStream* pthis, FILE* pfile);

size_t CFStream__CbWrite(
	CFStream* pthis,
	void* pvBuf,
	size_t cbitemsize,
	size_t cb);

size_t CFStream__CbRead(
	CFStream* pthis,
	void* pvBuf,
	size_t cbitemsize,
	size_t cb);

/* end class CFStream */


/* useful helper functions */
char* StretchSz(char* szSource, char* szDest, int nWidth);
char* StretchInt(int wSource, char* szDest, int nWidth);
char* StretchFloat(double fpSource, char* szDest, int nWidth);

#endif /* !defined(_SYMIO_H) */

