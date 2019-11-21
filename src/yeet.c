#include <args.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

INT main(
  IN INT ArgC,
  IN PSZ *ArgV)
{
  STATUS status;
  LPARGS_CONTEXT args;

  ARGUMENT_DESC argDesc;
  BOOL helpFlag;

  status = ArgsCreateContext(&args, ArgC, ArgV);
  if (STATUS_ERROR(status)) {
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
  if (STATUS_ERROR(status)) {
    goto mainEnd;
  }

  status = ArgsParseArguments(args, NULL);
  if (STATUS_ERROR(status)) {
    goto mainEnd;
  }

  status = ArgsCloseContext(&args);

mainEnd:
  return STATUS_ERROR(status) ? status : 0;
}
