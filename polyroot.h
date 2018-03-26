#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <stdlib.h>

std::vector<std::complex <double> > helper_algo (std::vector <double>)
{
  return {};
};

void polyroot (std::string fileName)
{
  // parse the file fileName

  std::string line;
  std::ifstream myfile;
  std::vector <std::string> p_data;

  // check for existence of txt file
  myfile.open(fileName);
  if (myfile.fail())
  {
    std::cout << "File " << fileName << " does not exist.\n";
    exit(2);
  }

  // store parsed data into a vector of double
  std::vector <double> coefs;  // coefficients
  std::vector < std::complex<double> > roots;  // all roots
  int deg;  // degree
  double icoeff;
  myfile >> deg;
  if (deg < 0)
  {
    std::cout << "Invalid degree.\n";
    exit(1);
  }

  for (int i = 0; i<=deg; i++)
  {
    myfile>>icoeff;
    coefs.push_back(icoeff);
  }


  // call helper_algo
  roots = helper_algo (coef);

  // and display that shit.
};

