#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
    return x * exp(-x) + pow(x, 3) + 1;
}

int main()
{
    double x0;
    double x1;
    double eps = 1e-6;
    double Dx;
    int i = 0;
    double p, q, x2;

    cout << "x0: ";
    cin >> x0;
    cout << "x1: ";
    cin >> x1;
    
    
    do {
        p = x0 * f(x1) - x1 * f(x0);
        q = f(x1) - f(x0);
        x2 = p / q;
        Dx = fabs(x2 - x1);
        x0 = x1;
        x1 = x2;
        i++;
    } while (Dx > eps);
    cout << x1;
}