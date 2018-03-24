#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <functional>
#include <cassert>

std::vector<std::complex <double> > helper_algo
(std::vector <double> coefs)
{
  // first, assert whether the function is "vaild"
  // i.e. the n'th coefficient is not zero
  assert(*coefs.rbegin() != 0);
  // Create a reduced function i.e. whose leading coefficient is one.
  // Note that the function takes in complex and returns complex!
  std::function <std::complex<double> (std::complex<double>) > fxnReduced
  = [coefs] (std::complex<double> x) -> std::complex<double>
  {
    std::complex <double> ret (0,0);
    for (int i = 0; i < coefs.size(); ++i)
    {
      ret += (coefs.at(i) * std::pow(x, i));
    }
    ret /= *(coefs.rbegin());
    return ret;
  };

  // Our initial roots (as prescribed by Wikipe-tan's article)
  std::vector< std::complex<double> > rootList(coefs.size()-1);
  for (int i = 0; i < rootList.size(); ++i)
    rootList.at(i) = std::pow(std::complex<double>(0.4, 0.9), i+1);

  // Now do some fixed point iteration
  // do_stuff.png
};

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

