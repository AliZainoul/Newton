#include <iostream>
#include <cmath>
using namespace std;

#include "error.hpp"
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

pfn j=hprime;
double jprime(double x){return 0;};


// cout << "the name of this function is: " << __func__ << endl;

int main ()
{
int d = 1000;
double delta,epsilon;
delta = 0.000001;
epsilon = 0.000001;

cout << "*** *** *** *** ***" << "\n";

cout << "Test of Function r :"<< "\n";
cout << " Value x_newton " <<newton(5, r, rprime, delta, epsilon, d) << "\n";
cout << " Value r(x_newton) " <<r(newton(5, r, rprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function f :"<< "\n";
cout << " Value x_newton " << newton(1.5, f, fprime, delta, epsilon, d) << "\n";
cout << " Value f(x_newton)  " <<f(newton(1.5, f, fprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function g :"<< "\n";
cout << " Value x_newton " <<newton(2, g, gprime, delta, epsilon, d) << "\n";
cout << " Value g(x_newton)  " <<g(newton(2, g, gprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function p :"<< "\n";
cout << " Value x_newton " <<newton(9999, p, pprime, delta, epsilon, d) << "\n";
cout << " Value p(x_newton)  " <<p(newton(9999, p, pprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function q :"<< "\n";
cout << " Value x_newton " <<newton(0.1, q, qprime, delta, epsilon, d) << "\n";
cout << " Value q(x_newton)  " <<q(newton(0.1, q, qprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function s :"<< "\n";
cout << " Value x_newton " <<newton(-0.1, s, sprime, delta, epsilon, d) << "\n";
cout << " Value s(x_newton)  " <<s(newton(-0.1, s, sprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function h :"<< "\n";
cout << " Value x_newton " <<newton(500, h, hprime, delta, epsilon, d) << "\n";
cout << " Value h(x_newton)  " <<h(newton(500, h, hprime, delta, epsilon, d)) << "\n";
getchar();

cout << "Test of Function j :"<< "\n";
cout << " Value x_newton " <<newton(500, j, jprime, delta, epsilon, d) << "\n";
cout << " Value j(x_newton)  " <<j(newton(500, j, jprime, delta, epsilon, d)) << "\n";
getchar();

return 0;
}
