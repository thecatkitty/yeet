SOURCE_DIR  = src
INCLUDE_DIR = inc
OBJECT_DIR  = obj
OUTPUT_DIR  = out
PROJECT_NAME = yeet


!IF !DEFINED(TARGETOS) && ("$(OS)" == "Windows_NT")
!MESSAGE Autodetected target OS: Windows
TARGETOS = win
!ELSE IF !DEFINED(TARGETOS)
!MESSAGE Autodetected target OS: DOS
TARGETOS = dos
!ELSEIF "$(TARGETOS)" == "win"
!MESSAGE Selected target OS: Windows
!ELSEIF "$(TARGETOS)" == "dos"
!MESSAGE Selected target OS: DOS
!ELSE
!ERROR `$(TARGETOS)` is an unknown target OS! `win` and `dos` available.
!ENDIF
OBJS = $(OBJECT_DIR)\$(TARGETOS)

!IF "$(TARGETOS)" == "win"
OUTPUT_FILE = $(PROJECT_NAME).exe
CC          = cl
LINK        = cl
CFLAGS      = /nologo /c /I$(INCLUDE_DIR)\ /Fo$(OBJS)\#
LFLAGS      = /nologo /Fe$(OUTPUT_DIR)\win\$(OUTPUT_FILE)

!ELSEIF "$(TARGETOS)" == "dos"
OUTPUT_FILE = $(PROJECT_NAME).exe
CC          = wcc
LINK        = wcl
CFLAGS      = -zq -bt=dos -i=$(INCLUDE_DIR)\ -fo$(OBJS)\#
LFLAGS      = -zq -l=dos -fe=$(OUTPUT_DIR)\dos\$(OUTPUT_FILE)

!ENDIF


build : dirs $(OUTPUT_DIR)\$(TARGETOS)\$(OUTPUT_FILE)


$(OUTPUT_DIR)\$(TARGETOS)\$(OUTPUT_FILE) : \
		$(OBJS)\yeet.obj \
		$(OBJS)\args.obj
	$(LINK) $(LFLAGS) $**

{$(SOURCE_DIR)\}.c{$(OBJECT_DIR)\$(TARGETOS)\}.obj::
	$(CC) $(CFLAGS) $<


dirs : $(OBJECT_DIR)\$(TARGETOS) $(OUTPUT_DIR)\$(TARGETOS)


$(OBJECT_DIR)\$(TARGETOS) : $(OBJECT_DIR)
	-mkdir $@

$(OUTPUT_DIR)\$(TARGETOS) : $(OUTPUT_DIR)
	-mkdir $@

$(OUTPUT_DIR) $(OBJECT_DIR) :
	-mkdir $@


clean :
	-rmdir /s /q $(OUTPUT_DIR) $(OBJECT_DIR) 2> nul
