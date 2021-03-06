#ifndef _ARGS_H_
#define _ARGS_H_

#include <error.h>
#include <platform.h>


#define ARGS_STATUS_FACILITY 0x701

#define ARGS_STATUS_CODE_UNKNOWN_TYPE 0x1000


#define ARGS_TYPE_BOOL    0
#define ARGS_TYPE_STRING  1
#define ARGS_TYPE_INT     3
#define ARGS_TYPE_FLOAT   4

#define ARGS_NUM_OPTIONAL  0
#define ARGS_NUM_ANY      -1
#define ARGS_NUM_ONE_MORE -2


typedef struct _ARGUMENT_DESC {
  IN LPVOID  Destination;
  IN INT     Flags;
  IN LPCSZ   Full OPTIONAL;
  IN char    Shorthand OPTIONAL;
  IN INT     NumArgs OPTIONAL;
  IN LPCSZ   Description;
  IN LPCSZ   Placeholder OPTIONAL;

  struct _ARGUMENT_DESC FAR *_Next;
} ARGUMENT_DESC, NEAR *PARGUMENT_DESC, FAR *LPARGUMENT_DESC;

typedef struct _ARGS_CONTEXT {
     OUT PCSZ ProgramName;
  IN     PCSZ Usage OPTIONAL;
  IN     PCSZ Description OPTIONAL;
  IN     PCSZ Epilog OPTIONAL;
  IN     PCSZ PrefixChars OPTIONAL;
  IN OUT BOOL Help;

  INT             _ArgC;
  LPCSZ           *_ArgV;
  LPARGUMENT_DESC _Arguments;
} ARGS_CONTEXT, NEAR *PARGS_CONTEXT, FAR *LPARGS_CONTEXT;

typedef struct _ARGS_LIST {
    LPCVOID               Value;
    struct _ARGS_LIST FAR *Next;
} ARGS_LIST, NEAR *PARGS_LIST, FAR *LPARGS_LIST;


STATUS
ArgsCreateContext(
  OUT LPARGS_CONTEXT *pContext,
  IN  INT            ArgC,
  IN  LPCSZ          *ArgV);

STATUS
ArgsCloseContext(
  IN OUT LPARGS_CONTEXT *pContext);

STATUS
ArgsAddArgument(
  IN OUT PARGS_CONTEXT   Context,
  IN     LPARGUMENT_DESC Descriptor);

STATUS
ArgsParseArguments(
  IN OUT PARGS_CONTEXT Context,
     OUT PUINT         pCount OPTIONAL);

#endif
