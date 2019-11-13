typedef unsigned long        ULONG;
typedef ULONG                *PULONG;
typedef unsigned short       USHORT;
typedef USHORT               *PUSHORT;
typedef unsigned char        UCHAR;
typedef UCHAR                *PUCHAR;
typedef char                 *PSZ;

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
typedef FLOAT                *PFLOAT;
typedef BOOL near            *PBOOL;
typedef BOOL far             *LPBOOL;
typedef BYTE near            *PBYTE;
typedef BYTE far             *LPBYTE;
typedef int near             *PINT;
typedef int far              *LPINT;
typedef WORD near            *PWORD;
typedef WORD far             *LPWORD;
typedef long far             *LPLONG;
typedef DWORD near           *PDWORD;
typedef DWORD far            *LPDWORD;
typedef void far             *LPVOID;
typedef CONST void far       *LPCVOID;

typedef int                  INT;
typedef unsigned int         UINT;
typedef unsigned int         *PUINT;
