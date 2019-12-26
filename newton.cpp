#include <iostream>
#include <cmath>
//#include "Vector.hpp"
#include "error.hpp"
using namespace std;
typedef double (*pfn) (double);

double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
{
  double xn = xp - (1/fd(xp))*f(xp);
  unsigned int k=0;
  while (    ((abs(xn-xp)) > delta) && ((abs(f(xn)))  > epsilon)      )
  {
    k += 1;
    if (k<=n_max) return newton(xn, f, fd, delta, epsilon, n_max);
    else error ("Too Many Iterations");
  }
  return xn;
}
