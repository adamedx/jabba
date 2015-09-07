/*/////////////////////////////////////////////////////////
// jabbamain.c
//
//
//
*/

#include "std.h"
#include "symio.h"
#include "jabba.h"

// for gnu implementations */
void* alloca(unsigned size);

void done(int faction)
	{
	exit(-1);
	}

char program_name[] = "semantic";

/* flex's definitions */
int yywrap()
	{
	return 1;
	}

void yyerror(char* msg)
	{
	CSemantics__IncrementErrors(g_psem);
	printf("--%s line %d: at %s\n",msg,g_psem->m_clines,yytext);
	}


/*//////////////////////////////////////
// main()
// The big one -- basically just 
// tells the scanner to go
*/
int main(int argc, char* argv[])
	{
	int ifile = 0;
	CHeap theHeap;	/* memory stuff */
	CSemantics Semantics;
	CFStream fstm;	/* current input stream */

	CALL_CONSTRUCTOR(CHeap,&theHeap);
	CALL_CONSTRUCTOR(CSemantics,&Semantics);
	CALL_CONSTRUCTOR(CFStream, &fstm);
	
	CFStream__SetFromStdlibFile(&fstm,stdin);

	CSemantics__Intro(&Semantics);

	yydebug = fFalse;
	if(argc >= 2)
		{
		if(yydebug = strcmp(argv[1],"-d") == 0)
			{
			ifile++;
			}
		}

	while(ifile++ < (argc - ((argc >1) ? 1 : 0)))
		{
		if(argc > 1)
			{
			if(!CFStream__FOpen(&fstm,argv[ifile],CFStream__read))
				{
				fprintf(stderr,"Unable to open input file %s\n", argv[ifile]);
				continue;
				}
			}

		/* set buffer to current file */
		yyin = CFStream__FPGetStdlibFile(&fstm);

		printf("\t.data\n__endline__:\t.asciiz\t\"\\n\"\n\t.text\n");
		printf("__copystart:    # routine to copy BIG types\n"
			"\tlw      $a3,0($a1)\n"
			"\tsw      $a3,0($a0)\n"
			"\taddi    $a0,$a0,-4\n"
			"\taddi    $a1,$a1,-4\n"
			"\taddi    $a2,$a2,-4\n"
			"__copy:\n"
			"\tbgtz    $a2,__copystart\n"
			"\tjr      $ra\n");

		yyparse();	/* get busy */

		if(argc > 1)
			{
			CFStream__FClose(&fstm);
			}
		}
	
	CSemantics__Exit(&Semantics);

	fclose(stdout);

	CALL_DESTRUCTOR(CFStream,&fstm);
	CALL_DESTRUCTOR(CSemantics,&Semantics);
	CALL_DESTRUCTOR(CHeap,&theHeap);	
	return 0;
	}
