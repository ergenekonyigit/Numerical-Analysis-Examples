// Root of the equation is 1.1618

#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;

//// Define a fn whose root you want to calculate
double f(double x)
{
	double a = pow(x, 2) - x - 1;
	return a;
}
// Write f(x) as x = g(x) and reduce the degree of the fn in terms of g(x)
double g(double x)
{
	double a = pow(x, -1) + 1;
	return a;
}

int main()
{
	int step = 1, max_iterations;
	float x_initial, x1, accuracy;

	//Setting precision and writing floating point values in fixed-point notation.

	cout << setprecision(6) << fixed;

	// Read the input data
	cout << "Enter initial guess: ";
	cin >> x_initial;

	cout << "Enter the desired value of accuracy (up to how many decimal places) ";
	cin >> accuracy;

	cout << "Enter maximum iteration: ";
	cin >> max_iterations;

	// Implementing Fixed Point Iteration

	cout << endl
		 << "**************************" << endl;
	cout << "Fixed Point Iteration Method" << endl;
	cout << "**************************" << endl;
	do
	{
		x1 = g(x_initial);
		cout << "Iteration-" << step << ":\t x1 = " << setw(10) << x1 << " and f(x1) = " << setw(10) << f(x1) << endl;

		step = step + 1;

		if (step > max_iterations)
		{
			cout << "Fn not Not Convergent." << endl;
			cout << "max number of iterations reached"
				 << " " << max_iterations << endl;
			cout << "The best root is"
				 << " " << x1;

			exit(0);
		}

		x_initial = x1;

	} while (fabs(f(x1)) > accuracy);

	cout << endl
		 << "Root is " << x1;

	return (0);
}