#include <iostream>
#include <cmath>
using namespace std;

#include "error.hpp"
//#include "Vector.hpp"
#include "newton.hpp"

typedef double (*pfn) (double);

double f(double x){return (1/x) - pow(2,x);};
double fprime(double x){return ((-1/(2*x) ) -exp(x*log(2)));};

double g(double x){return (pow(2,(-x)) + exp(x) + 2 * cos(x) - 6);};
double gprime(double x){return ( exp(-x*log(2)) + exp(x) - 2 * sin(x) );};

double p(double x){return (x+1);};
double pprime(double x){return 1;};

double q(double x){return (x*x)-1;};
double qprime(double x){return (2*x);};

double r(double x){return (x*x*x)-(5*x*x)+(3*x)+7;};
double rprime(double x){return (3*x*x)-(10*x)+(3);};

double s(double x){return 1-(x*x);};
double sprime(double x){return (-2*x);};

double h(double x){return x;};
double hprime(double x){return 1;};
double jprime(double x){return 0;};




// cout << "the name of this function is: " << __func__ << endl;

int main ()
{
cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function f :"<< "\n";
cout << newton(1.5, f, fprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function g :"<< "\n";
cout << newton(2, g, gprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function p :"<< "\n";
cout << newton(9999, p, pprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function q :"<< "\n";
cout << newton(0.1, q, qprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function r :"<< "\n";
cout << newton(5, r, rprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function s :"<< "\n";
cout << newton(-0.1, s, sprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function h :"<< "\n";
cout << newton(500, h, hprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";

cout << "*** *** *** *** ***" << "\n";
cout << "Test of Function j :"<< "\n";
cout << newton(500, hprime, jprime, 0.000001, 0.000001, 1000000) << "\n";
cout << "*** *** *** *** ***" << "\n";
}
