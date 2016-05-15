#include <stdio.h>
#include <math.h>

double f(double x) {
  return x * exp(-x) + pow(x, 3) + 1;
}

double df(double x) {
  return exp(-x) - x * exp(-x) + 3 * pow(x,2);
}

int main()
{
  double x0;
  double x1;
  double eps = 1e-6;
  double Dx;
  int i = 0;
  
  printf("x0: ");
  scanf("%d", &x0);
  do {
    x1 = x0 - f(x0) / df(x0);
    Dx = fabs(x1 - x0);
    x0 = x1;
    i++;
  } while (Dx > eps);
  printf("%f\n", x1);
}
