#include <args.h>

#include <stdlib.h>


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
  this->ProgramName = ArgV[0];
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
