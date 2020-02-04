#include <args.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

INT
main(
  IN INT ArgC,
  IN PSZ *ArgV)
{
  STATUS         Status;
  LPARGS_CONTEXT Args;
  ARGUMENT_DESC  ArgDesc;
  BOOL           HelpFlag;

  Status = ArgsCreateContext(&Args, ArgC, ArgV);
  if (STATUS_ERROR(Status)) {
    goto mainEnd;
  }

  memset(&ArgDesc, 0, sizeof(ARGUMENT_DESC));
  HelpFlag            = FALSE;
  ArgDesc.Destination = &HelpFlag;
  ArgDesc.Flags       = ARGS_TYPE_BOOL;
  ArgDesc.Full        = "help";
  ArgDesc.Shorthand   = 'h';
  ArgDesc.Description = "Shows help";

  Status = ArgsAddArgument(Args, &ArgDesc);
  if (STATUS_ERROR(Status)) {
    goto mainEnd;
  }

  Status = ArgsParseArguments(Args, NULL);
  if (STATUS_ERROR(Status)) {
    goto mainEnd;
  }

  Status = ArgsCloseContext(&Args);

mainEnd:
  return STATUS_ERROR(Status) ? Status : 0;
}
