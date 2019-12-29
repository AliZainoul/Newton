#include <iostream>
#include <cmath>
//#include "Vector.hpp"
#include "error.hpp"
using namespace std;
typedef double (*pfn) (double);

bool root(pfn f, double xp)
{
  if (f(xp)==0.0) return true;
  else return false;
};

bool divisionbyzero(pfn fd, double xp)
{
if (fd(xp)==0.0) return true;
else return false;
};

bool haveWeFoundSolution(double xp, double xn)
{
if (xn==xp) return false;
else return true;
};
double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
{
  //cout << divisionbyzero(fd,xp);
  if (root(f,xp)) return xp;
  if (!divisionbyzero(fd, xp))
  {
    double xn = xp - (f(xp)/fd(xp));
    while (    ((abs(xn-xp)) > delta) && ((abs(f(xn)))  > epsilon)     )
    {
      return newton(xn, f, fd, delta, epsilon, n_max-1);
    }
    if (haveWeFoundSolution(xp,xn)) return xn;
    else {error("Method Diverge");}
  }
  else {error("Divisiong By Zero Occurs");}
}

/*
double newton(double xp, pfn f, pfn fd, double delta, double epsilon, int n_max)
{
  bool haveWeFoundSolution = false;
  double xn ;
  for (unsigned int k=0; k<=n_max; k++)
  {
    double y=f(xp);
    double yprime=fd(xp);
    if ((abs(yprime))  < epsilon ) error ("Denominator too small.");
    double xn = xp - (y/yprime);
    if ((abs(xn-xp)) < delta)
    {
      haveWeFoundSolution = true;
      break;
    }
    xp = xn;
  }
  if (haveWeFoundSolution) {cout << "The Method has converged ?" << haveWeFoundSolution << "\n";}
  else error ("Method did not converge or too Many Iterations");
  return xn;
}*/

//var = (k<=n_max) ? 30 : 40;
