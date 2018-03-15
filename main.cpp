#include <iostream>
#include "polyroot.h"

int main(int argc, char** argv)
{
  // check argc
  if (argc == 1)
  {
    // display help message or something
    return 1;
  }
  polyroot(argv[1]);
  return 0;
}
