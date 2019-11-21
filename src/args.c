#include <args.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


STATUS ArgsCreateContext(
  OUT LPARGS_CONTEXT *pContext,
  IN  INT            ArgC,
  IN  LPCSZ          *ArgV)
{
  LPARGS_CONTEXT this;
  LPVOID memory = calloc(1, sizeof(ARGS_CONTEXT));
  if (memory == NULL) {
      return EXIT_FAILURE;
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
  return EXIT_SUCCESS;
}


STATUS ArgsCloseContext(
  IN OUT LPARGS_CONTEXT *pContext)
{
  if (pContext == NULL) {
    return EXIT_FAILURE;
  }

  free(*pContext);
  *pContext = NULL;
  return EXIT_SUCCESS;
}


STATUS ArgsAddArgument(
  IN OUT PARGS_CONTEXT   Context,
  IN     LPARGUMENT_DESC Descriptor)
{
  LPARGUMENT_DESC *pDesc = &Context->_Arguments;

  while (*pDesc) {
    pDesc = &(*pDesc)->_Next;
  }
  *pDesc = Descriptor;
  return EXIT_SUCCESS;
}


STATUS ArgsParseArguments(
           IN OUT PARGS_CONTEXT Context,
  OPTIONAL    OUT PUINT         pCount)
{
  LPARGUMENT_DESC arg = Context->_Arguments;

  while (arg) {
    PSZ type =
      (arg->Flags & 0xF) == ARGS_TYPE_BOOL ? "bool" :
      (arg->Flags & 0xF) == ARGS_TYPE_STRING ? "string" :
      (arg->Flags & 0xF) == ARGS_TYPE_INT ? "int" :
      (arg->Flags & 0xF) == ARGS_TYPE_FLOAT ? "float" :
      "unknown";
    
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

  return EXIT_SUCCESS;
}
