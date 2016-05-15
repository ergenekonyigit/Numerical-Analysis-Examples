#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
  return x * exp(-x) + pow(x, 3.0) + 1;
}

double df(double x) {
  return exp(-x) - x * exp(-x) + 3 * pow(x,2);
}

int main()
{
  cout << "x0: ";
  double x0;
  cin >> x0;
  double x1;
  double eps = 1e-6;
  double Dx;
  int i = 0;
  do {
    x1 = x0 - f(x0)/df(x0);
    Dx = fabs(x1 - x0);
    x0 = x1;
    i++;
  } while (Dx > eps);
  cout << x1;
}
