#include <args.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ARGS_IS_TYPE( \
  Descriptor, \
  Type) \
( \
  ((Descriptor)->Flags & 0xF) == (Type) \
)


STATUS
ArgsCreateContext(
  OUT LPARGS_CONTEXT *pContext,
  IN  INT            ArgC,
  IN  LPCSZ          *ArgV)
{
  LPARGS_CONTEXT this;
  STATUS         Status = STATUS_SUCCESS;
  LPVOID         Memory = calloc(1, sizeof(ARGS_CONTEXT));
  if (Memory == NULL) {
      Status = MAKE_ERROR(ARGS_STATUS_FACILITY, STATUS_CODE_BAD_ALLOC);
      goto ArgsCreateContextEnd;
  }

  *pContext = Memory;

  this = *pContext;

  this->ProgramName = strrchr(ArgV[0], '\\');
  if (this->ProgramName == NULL) {
    this->ProgramName = ArgV[0];
  }
  this->ProgramName++;

  this->Help = TRUE;

  this->_ArgC = ArgC;
  this->_ArgV = ArgV;

ArgsCreateContextEnd:
  return Status;
}


STATUS
ArgsCloseContext(
  IN OUT LPARGS_CONTEXT *pContext)
{
  STATUS Status = STATUS_SUCCESS;

  if (pContext == NULL) {
    Status = MAKE_ERROR(ARGS_STATUS_FACILITY, STATUS_CODE_NULL_REFERENCE);
    goto ArgsCloseContextEnd;
  }

  free(*pContext);
  *pContext = NULL;

ArgsCloseContextEnd:
  return Status;
}


STATUS
ArgsAddArgument(
  IN OUT PARGS_CONTEXT   Context,
  IN     LPARGUMENT_DESC Descriptor)
{
  STATUS          Status = STATUS_SUCCESS;
  LPARGUMENT_DESC *pDesc = &Context->_Arguments;

  while (*pDesc) {
    pDesc = &(*pDesc)->_Next;
  }
  *pDesc = Descriptor;

ArgsAddArgumentEnd:
  return Status;
}


STATUS
ArgsParseArguments(
  IN OUT PARGS_CONTEXT Context,
     OUT PUINT         pCount OPTIONAL)
{
  STATUS          Status = STATUS_SUCCESS;
  LPARGUMENT_DESC Arg = Context->_Arguments;

  while (Arg) {
    PSZ type =
      ARGS_IS_TYPE(Arg, ARGS_TYPE_BOOL) ? "bool" :
      ARGS_IS_TYPE(Arg, ARGS_TYPE_STRING) ? "string" :
      ARGS_IS_TYPE(Arg, ARGS_TYPE_INT) ? "int" :
      ARGS_IS_TYPE(Arg, ARGS_TYPE_FLOAT) ? "float" :
      NULL;

    if (type == NULL) {
      Status = MAKE_ERROR(ARGS_STATUS_FACILITY, ARGS_STATUS_CODE_UNKNOWN_TYPE);
      goto ArgsParseArgumentsEnd;
    }
    
    printf(
      "%s\t%s\t%c\t%d\t%s\t%s\n",
      type,
      Arg->Full ? Arg->Full : "",
      Arg->Shorthand ? Arg->Shorthand : ' ',
      Arg->NumArgs,
      Arg->Description,
      Arg->Placeholder ? Arg->Placeholder : "");

    Arg = Arg->_Next;
  }

ArgsParseArgumentsEnd:
  return Status;
}
