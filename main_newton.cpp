#include <iostream>
#include <cmath>
using namespace std;

#include "error.hpp"
//#include "Vector.hpp"
#include "newton.hpp"

typedef double (*pfn) (double);

double p(double x){return (x*x)-1;};
double pprime(double x){return (2*x);};

double q(double x){return (x*x*x)-(5*x*x)+(3*x)+7;};
double qprime(double x){return (3*x*x)-(10*x)+(3);};



// cout << "the name of this function is: " << __func__ << endl;

int main ()
{
cout << "*** *** *** *** ***" << "\n";
cout << "Test of polynom p :"<< "\n";
cout << newton(0.5, p, pprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of polynom q :"<< "\n";
cout << newton(5, q, qprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

}
