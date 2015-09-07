# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

!IF "$(CFG)" == ""
CFG=jabba - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to jabba - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "jabba - Win32 Release" && "$(CFG)" != "jabba - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "jabba.mak" CFG="jabba - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "jabba - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "jabba - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "jabba - Win32 Debug"
RSC=rc.exe
CPP=cl.exe

!IF  "$(CFG)" == "jabba - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\jabba.exe"

CLEAN : 
	-@erase ".\Release\jabba.exe"
	-@erase ".\Release\jabbamain.obj"
	-@erase ".\Release\symio.obj"
	-@erase ".\Release\stdtype.obj"
	-@erase ".\Release\jabba.obj"
	-@erase ".\parser.tab.h"
	-@erase ".\Release\regalloc.obj"
	-@erase ".\Release\std.obj"
	-@erase ".\Release\lex.yy.obj"
	-@erase ".\lex.yy.c"
	-@erase ".\Release\parser.tab.obj"
	-@erase ".\parser.tab.c"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE"\
 /Fp"$(INTDIR)/jabba.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/jabba.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"LIBC"
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo\
 /subsystem:console /incremental:no /pdb:"$(OUTDIR)/jabba.pdb" /machine:I386\
 /nodefaultlib:"LIBC" /out:"$(OUTDIR)/jabba.exe" 
LINK32_OBJS= \
	".\alloca.obj" \
	"$(INTDIR)/jabbamain.obj" \
	"$(INTDIR)/symio.obj" \
	"$(INTDIR)/stdtype.obj" \
	"$(INTDIR)/jabba.obj" \
	"$(INTDIR)/regalloc.obj" \
	"$(INTDIR)/std.obj" \
	".\allocate.obj" \
	"$(INTDIR)/lex.yy.obj" \
	"$(INTDIR)/parser.tab.obj"

"$(OUTDIR)\jabba.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "jabba - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\jabba.exe"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\parser.tab.c"
	-@erase ".\lex.yy.c"
	-@erase ".\parser.tab.h"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\jabba.exe"
	-@erase ".\Debug\regalloc.obj"
	-@erase ".\Debug\symio.obj"
	-@erase ".\Debug\stdtype.obj"
	-@erase ".\Debug\std.obj"
	-@erase ".\Debug\parser.tab.obj"
	-@erase ".\Debug\lex.yy.obj"
	-@erase ".\Debug\jabbamain.obj"
	-@erase ".\Debug\jabba.obj"
	-@erase ".\Debug\jabba.ilk"
	-@erase ".\Debug\jabba.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE"\
 /Fp"$(INTDIR)/jabba.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/jabba.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"LIBC"
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib\
 advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo\
 /subsystem:console /incremental:yes /pdb:"$(OUTDIR)/jabba.pdb" /debug\
 /machine:I386 /nodefaultlib:"LIBC" /out:"$(OUTDIR)/jabba.exe" 
LINK32_OBJS= \
	".\alloca.obj" \
	"$(INTDIR)/regalloc.obj" \
	"$(INTDIR)/symio.obj" \
	"$(INTDIR)/stdtype.obj" \
	"$(INTDIR)/std.obj" \
	"$(INTDIR)/parser.tab.obj" \
	".\allocate.obj" \
	"$(INTDIR)/lex.yy.obj" \
	"$(INTDIR)/jabbamain.obj" \
	"$(INTDIR)/jabba.obj"

"$(OUTDIR)\jabba.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "jabba - Win32 Release"
# Name "jabba - Win32 Debug"

!IF  "$(CFG)" == "jabba - Win32 Release"

!ELSEIF  "$(CFG)" == "jabba - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\parser.y

!IF  "$(CFG)" == "jabba - Win32 Release"

# Begin Custom Build - Generating Parser
InputDir=.
InputPath=.\parser.y
InputName=parser

BuildCmds= \
	C:\data\source\yacc\BISON-A2.6\bison.exe -d -v -t $(InputName).y \
	

"$(InputDir)\parser.tab.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\parser.tab.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "jabba - Win32 Debug"

# Begin Custom Build - Generating Parser
InputDir=.
InputPath=.\parser.y
InputName=parser

BuildCmds= \
	C:\data\source\yacc\BISON-A2.6\bison.exe -d -v -t $(InputName).y \
	

"$(InputDir)\parser.tab.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"$(InputDir)\parser.tab.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\std.c
DEP_CPP_STD_C=\
	".\std.h"\
	

"$(INTDIR)\std.obj" : $(SOURCE) $(DEP_CPP_STD_C) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\parser.tab.c
DEP_CPP_PARSE=\
	".\jabba.h"\
	".\std.h"\
	".\stdtype.h"\
	".\regalloc.h"\
	

"$(INTDIR)\parser.tab.obj" : $(SOURCE) $(DEP_CPP_PARSE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jabbamain.c
DEP_CPP_JABBA=\
	".\std.h"\
	".\symio.h"\
	".\jabba.h"\
	".\stdtype.h"\
	".\regalloc.h"\
	

"$(INTDIR)\jabbamain.obj" : $(SOURCE) $(DEP_CPP_JABBA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\jabba.c
DEP_CPP_JABBA_=\
	".\jabba.h"\
	".\parser.tab.h"\
	".\std.h"\
	".\stdtype.h"\
	".\regalloc.h"\
	

"$(INTDIR)\jabba.obj" : $(SOURCE) $(DEP_CPP_JABBA_) "$(INTDIR)"\
 ".\parser.tab.h"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\symio.c
DEP_CPP_SYMIO=\
	".\symio.h"\
	".\std.h"\
	

"$(INTDIR)\symio.obj" : $(SOURCE) $(DEP_CPP_SYMIO) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\alloca.obj

!IF  "$(CFG)" == "jabba - Win32 Release"

!ELSEIF  "$(CFG)" == "jabba - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\allocate.obj

!IF  "$(CFG)" == "jabba - Win32 Release"

!ELSEIF  "$(CFG)" == "jabba - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\lexer.l

!IF  "$(CFG)" == "jabba - Win32 Release"

# Begin Custom Build - Lexical Analysis
InputDir=.
InputPath=.\lexer.l

"$(InputDir)\lex.yy.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   c:\data\source\flex\flex.exe $(InputPath)

# End Custom Build

!ELSEIF  "$(CFG)" == "jabba - Win32 Debug"

# Begin Custom Build - Lexical Analysis
InputDir=.
InputPath=.\lexer.l

"$(InputDir)\lex.yy.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   c:\data\source\flex\flex.exe $(InputPath)

# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\lex.yy.c
DEP_CPP_LEX_Y=\
	".\jabba.h"\
	".\parser.tab.h"\
	".\std.h"\
	".\stdtype.h"\
	".\regalloc.h"\
	

"$(INTDIR)\lex.yy.obj" : $(SOURCE) $(DEP_CPP_LEX_Y) "$(INTDIR)"\
 ".\parser.tab.h"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\stdtype.c
DEP_CPP_STDTY=\
	".\stdtype.h"\
	".\std.h"\
	

"$(INTDIR)\stdtype.obj" : $(SOURCE) $(DEP_CPP_STDTY) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\regalloc.c
DEP_CPP_REGAL=\
	".\regalloc.h"\
	".\std.h"\
	".\stdtype.h"\
	

"$(INTDIR)\regalloc.obj" : $(SOURCE) $(DEP_CPP_REGAL) "$(INTDIR)"


# End Source File
# End Target
# End Project
################################################################################
