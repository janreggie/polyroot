#include <iostream>
#include <chrono>
#include "polyroot.h"

int main(int argc, char** argv)
{

const std::string help_msg = "\
polyroot: Determine all complex roots of an arbitrary polynomial.\n\
Copyright (c) 2018 under BSD 3-Clause, janreggie, jriaghan, sangjeona.\n \
\n\
Usage:\n\
./polyroot file.txt\n\
\n\
Read the README for more information.\n\
";

  if (argc == 1)
  {
    // display help message or something
    std::cout << help_msg;

    std::string filename;
    std::cout << "filename: ";
    std::cin >> filename;
    polyroot(filename);

  }

  polyroot(argv[1]);
  return 0;
}
