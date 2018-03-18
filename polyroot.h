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
  while (myfile.fail())
  {
    std::cout<<"Error opening file."<<std::endl;
    std::cout<<"Please enter a valid filename: ";
    std::cin>>fileName;
    if(fileName == "exit") break;
    myfile.open(fileName);
  }
  
  // store parsed data into a vector of double
  std::vector <double> coef;
  int deg, icoeff;
  myfile >> deg;
  if (deg < 0)
  {
    std::cout<<"You have entered an invalid input file.";
    exit(1);
  }
  
  for (int i = 0; i<=deg; i++)
  {
    myfile>>icoeff;
    coef.push_back(icoeff);
  }
 

  // call helper_algo
  auto allRoots = helper_algo (coef);

  // and display that shit.
};

