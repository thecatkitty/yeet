#include <args.h>

#include <stdio.h>
#include <stdlib.h>

INT main(
  IN INT ArgC,
  IN PSZ *ArgV)
{
  STATUS status;
  LPARGS_CONTEXT args;

  status = ArgsCreateContext(&args, ArgC, ArgV);
  if (status == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }

  puts("Hello, World!");

  status = ArgsCloseContext(&args);
  if (status == EXIT_FAILURE) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
