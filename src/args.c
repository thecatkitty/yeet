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


STATUS ArgsCreateContext(
  OUT LPARGS_CONTEXT *pContext,
  IN  INT            ArgC,
  IN  LPCSZ          *ArgV)
{
  STATUS status = EXIT_SUCCESS;
  LPARGS_CONTEXT this;
  LPVOID memory = calloc(1, sizeof(ARGS_CONTEXT));
  if (memory == NULL) {
      status = EXIT_FAILURE;
      goto ArgsCreateContextEnd;
  }

  *pContext = memory;

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
  return status;
}


STATUS ArgsCloseContext(
  IN OUT LPARGS_CONTEXT *pContext)
{
  STATUS status = EXIT_SUCCESS;

  if (pContext == NULL) {
    status = EXIT_FAILURE;
    goto ArgsCloseContextEnd;
  }

  free(*pContext);
  *pContext = NULL;

ArgsCloseContextEnd:
  return EXIT_SUCCESS;
}


STATUS ArgsAddArgument(
  IN OUT PARGS_CONTEXT   Context,
  IN     LPARGUMENT_DESC Descriptor)
{
  STATUS status = EXIT_SUCCESS;
  LPARGUMENT_DESC *pDesc = &Context->_Arguments;

  while (*pDesc) {
    pDesc = &(*pDesc)->_Next;
  }
  *pDesc = Descriptor;

ArgsAddArgumentEnd:
  return status;
}


STATUS ArgsParseArguments(
           IN OUT PARGS_CONTEXT Context,
  OPTIONAL    OUT PUINT         pCount)
{
  STATUS status = EXIT_SUCCESS;
  LPARGUMENT_DESC arg = Context->_Arguments;

  while (arg) {
    PSZ type =
      ARGS_IS_TYPE(arg, ARGS_TYPE_BOOL) ? "bool" :
      ARGS_IS_TYPE(arg, ARGS_TYPE_STRING) ? "string" :
      ARGS_IS_TYPE(arg, ARGS_TYPE_INT) ? "int" :
      ARGS_IS_TYPE(arg, ARGS_TYPE_FLOAT) ? "float" :
      NULL;

    if (type == NULL) {
      status = EXIT_FAILURE;
      goto ArgsParseArgumentsEnd;
    }
    
    printf(
      "%s\t%s\t%c\t%d\t%s\t%s\n",
      type,
      arg->Full ? arg->Full : "",
      arg->Shorthand ? arg->Shorthand : ' ',
      arg->NumArgs,
      arg->Description,
      arg->Placeholder ? arg->Placeholder : "");

    arg = arg->_Next;
  }

ArgsParseArgumentsEnd:
  return status;
}
