#include <sstream>
#include <vector>
#include <complex>
#include <cmath>

void polyroot (std::string fileName)
{
  // parse the file fileName
  // check for existence
  // good luck with this
  std::vector <double> coef;

  // call helper_algo
  auto allRoots = helper_algo (coef);

  // and display that shit.
};

std::vector<std::complex> helper_algo (std::vector <double>);
