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

  using namespace std::chrono;  // for time testing
  auto t0 = high_resolution_clock::now();
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
  auto t1 = high_resolution_clock::now();
  std::cout
    << "The algorithm took "
    << duration_cast<microseconds>(t1-t0).count()
    << " microseconds.\n";
  return 0;
}
