#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <string>
#include <functional>
#include <cassert>
#include <algorithm>

std::vector<std::complex <double> > helper_algo
(const std::vector <double> & coefs)
{
  unsigned int n = coefs.size() - 1;  // degree
  double precision = 1e-6;  // the algo's precision
  /*
  This root-finding method is described by Guggenheimer's
  "Initial Approximations in Durand-Kerner's Root-Finding Method".
  https://doi.org/10.1007/BF01935059
  Certain semantics may be off here.
  */

  // Assert that neither a0 nor an is zero
  assert(coefs[0] * coefs[n] != 0);

  // Copy coefs, but reverse it.
  std::vector<double> rcoefs (coefs);
  std::reverse(std::begin(rcoefs), std::end(rcoefs));

  // Now create a lambda expression for the function
  std::function< std::complex<double>(std::complex<double>) > p
  = [rcoefs](std::complex<double> z)
  {
    std::complex<double> ans (0,0);
    for (unsigned int i = 0; i < rcoefs.size(); ++i)
      ans += rcoefs.at(i) * std::pow(z, (rcoefs.size() - 1 - i));
    return ans;
  };

  // Now determine our r0
  std::vector<double> u;  // step 1a
  for (unsigned int i = 1; i <= n; ++i)
    if (rcoefs[i] != 0)
      u.push_back(1.0 / (2 * std::pow(std::abs(rcoefs[i]/rcoefs[0]) , 1/i)));
  std::vector<double> v;  // step 1b
  for (unsigned int j = 0; j < n; ++j)
    if (rcoefs[j] != 0)
      v.push_back(1.0 / (2 * std::pow(std::abs(rcoefs[j]/rcoefs[n]), 1/(n-j))));
  double uAve = std::accumulate(u.begin(), u.end(), 0) / u.size();  // step 2
  double vAve = std::accumulate(v.begin(), v.end(), 0) / v.size();
  auto it = u.begin();  // removal of the "offshoot" u_i and v_i
  for (auto itTmp = u.begin(); itTmp != u.end(); ++itTmp)
    if (std::abs(*it - uAve) < std::abs(*itTmp - uAve))
      it = itTmp;
  u.erase(it);
  it = v.begin();
  for (auto itTmp = v.begin(); itTmp != v.end(); ++itTmp)
    if (std::abs(*it - vAve) < std::abs(*itTmp - vAve))
      it = itTmp;
  v.erase(it);
  uAve = std::accumulate(u.begin(), u.end(), 0) / u.size();
  vAve = std::accumulate(v.begin(), v.end(), 0) / v.size();
  double r0 = (uAve + vAve) / 2.0;

  // Now create a vector for our roots
  std::vector< std::complex<double> > roots(n+1);
  for (unsigned int k = 0; k <= n; ++k)
    roots[k] = r0 * std::exp(2*M_PI*k*std::complex<double>(0,1)/double(n));

  // Now, time for some fixed-point fucking iteration.
  while (true)  // >inb4 infinite loop
  {
    double lol = 0;  // our maximum difference; ran out of identifiers lol
    for (unsigned int k = 0; k <= n; ++k)  // implement the fixed point iteration
    {
      // find the denominator (long-ass expression in the paper)
      std::complex<double> denom = rcoefs[0];
      for (unsigned int l = 0; l <= n; ++l)
        if (l != k)
          denom *= (roots[k] - roots[l]);
      roots[k] = roots[k] - p(roots[k]) / denom;
      // and lol's one-liner if statement
      lol = ((std::abs(p(roots[k])/denom) > lol) ? std::abs(p(roots[k])/denom) : lol);
    }
    // and break if lol is less than our precision
    if (lol < precision)
      break;
  }
  return roots;
};

void polyroot (std::string fileName)
{
  // parse the file fileName
  // check for existence
  // good luck with this
  std::vector <double> coefs;  // coefficients
  std::vector <std::complex<double> > roots;  // all roots
  int deg;  // degree
  // and now the fucking lambda function (if only we had Haskell)
  std::function < std::complex<double> (std::complex<double>) > f
  = [coefs] (std::complex<double> x)
  {
    std::complex<double> ans (0,0);
    for (unsigned int i = 0; i < coefs.size(); ++i)
      ans += coefs.at(i) * std::pow(x, i);
    return ans;
  };

  // call helper_algo
  roots = helper_algo (coefs);

  // and display that shit.

  std::cout.precision(6);  // for precision
  std::cout << "Polynomial:\n";
  for (int x = deg; x >= 0; --x)
    std::cout << coefs[x] << " x^" << x <<"\n";

  std::cout << "Roots:\n";
  for (auto & x: roots)
    std::cout << x << '\n';

  std::cout << "Evaluating polynomial at identified roots:\n";
  for (auto & x: roots)
    std::cout << "f" << x << " = " << f(x) << std::endl;

};

