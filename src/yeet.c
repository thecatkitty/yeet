#include <args.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

INT main(
  IN INT ArgC,
  IN PSZ *ArgV)
{
  STATUS status = EXIT_SUCCESS;
  LPARGS_CONTEXT args;

  ARGUMENT_DESC argDesc;
  BOOL helpFlag;

  status = ArgsCreateContext(&args, ArgC, ArgV);
  if (status == EXIT_FAILURE) {
    goto mainEnd;
  }

  memset(&argDesc, 0, sizeof(ARGUMENT_DESC));
  helpFlag            = FALSE;
  argDesc.Destination = &helpFlag;
  argDesc.Flags       = ARGS_TYPE_BOOL;
  argDesc.Full        = "help";
  argDesc.Shorthand   = 'h';
  argDesc.Description = "Shows help";

  status = ArgsAddArgument(args, &argDesc);
  if (status == EXIT_FAILURE) {
    goto mainEnd;
  }

  status = ArgsParseArguments(args, NULL);
  if (status == EXIT_FAILURE) {
    goto mainEnd;
  }

  status = ArgsCloseContext(&args);

mainEnd:
  return status;
}
