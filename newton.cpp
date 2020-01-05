#include <iostream>
#include <cmath>
#include "error.hpp"
using namespace std;
typedef double (*pfn) (double);

bool root(pfn f, double x)
{
  if (f(x)==0.0) return true;
  else return false;
};


bool Solution(double xp, double xn, pfn fd, double delta, double epsilon)
{
if (((abs(fd(xp)))<epsilon) || ((abs(xn-xp))<=delta)) return true;
else return false;
};



double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
{
  double fxp,fdxp,xn;
  if ((1/epsilon)*(f(xp+epsilon)-f(xp))==0.0)
  error("Constant Functions do no admit roots.");
  if (root(f,xp)) return xp;
  if (!root(fd,xp))
  for (unsigned int k=1;k<=n_max;k++)
  {
    fxp = f(xp);
    fdxp = fd(xp);
    if (((abs(fdxp))<epsilon)) error("Denominator too small;");
    else xn = xp - (f(xp)/fd(xp));
    if (Solution(xp, xn, fd, delta, epsilon)) return xn;
    else xp = xn;
  }
  else error("Division By Zero occurs.");
  error("Too many interations or diverging method; please try with another guess");
};
