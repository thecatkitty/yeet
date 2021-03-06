#ifndef _PLATFORM_H_
#define _PLATFORM_H_

typedef unsigned long        ULONG;
typedef ULONG                *PULONG;
typedef unsigned short       USHORT;
typedef USHORT               *PUSHORT;
typedef unsigned char        UCHAR;
typedef UCHAR                *PUCHAR;

#ifndef NULL
#define NULL                 0
#endif

#ifndef FALSE
#define FALSE                0
#endif

#ifndef TRUE
#define TRUE                 1
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifndef far
#define far
#define near
#endif
#define FAR                  far
#define NEAR                 near

#ifndef pascal
#define pascal               __stdcall
#define cdecl                __cdecl
#endif
#define PASCAL               pascal
#define CDECL                cdecl

#ifndef CONST
#define CONST                const
#endif

typedef unsigned long        DWORD;
typedef int                  BOOL;
typedef unsigned char        BYTE;
typedef unsigned short       WORD;
typedef float                FLOAT;
typedef void                 VOID;
typedef FLOAT                *PFLOAT;
typedef BOOL NEAR            *PBOOL;
typedef BOOL FAR             *LPBOOL;
typedef BYTE NEAR            *PBYTE;
typedef BYTE FAR             *LPBYTE;
typedef int NEAR             *PINT;
typedef int FAR              *LPINT;
typedef WORD NEAR            *PWORD;
typedef WORD FAR             *LPWORD;
typedef long FAR             *LPLONG;
typedef DWORD NEAR           *PDWORD;
typedef DWORD FAR            *LPDWORD;
typedef VOID FAR             *LPVOID;
typedef CONST VOID FAR       *LPCVOID;

typedef int                  INT;
typedef unsigned int         UINT;
typedef unsigned int         *PUINT;

typedef char NEAR            *PSZ;
typedef char FAR             *LPSZ;
typedef CONST char NEAR      *PCSZ;
typedef CONST char FAR       *LPCSZ;

#endif
