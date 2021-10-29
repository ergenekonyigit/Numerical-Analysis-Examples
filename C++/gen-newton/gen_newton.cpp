

//Gen-Newton-Raphson method
#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;

//// Define a fn whose root you want to calculate

double f(double x)
{
  double a = pow(x, 3) - pow(x, 2) - x + 1;
  return a;
}

// Calculate the value of the derivative df/dx
double df(double x)
{
  double a = 3 * x * x - 2 * x - 1;
  return a;
}

// Calculate the value of the derivative of derivate d^2f/dx^2

double ddf(double x)
{
  double a = 6 * x - 2;
  return a;
}

double new_estimate(double x)
{
  double x_new = x - 2 * f(x) / df(x);

  return x_new;
}

double compare_estimate(double x)
{
  double x_compare = x - df(x) / ddf(x);

  return x_compare;
}

int main()
{
  double init_guess, accuracy;

  // Read the input data
  cout << "Enter the desired value of accuracy (up to how many decimal places) ";
  cin >> accuracy;

  // Read the limits and accuracy
  cout << "(First) initial guess = ";
  cin >> init_guess;
  double new_guess;
  double compare_guess;

  bool has_converged = false;
  int count = 0;

  int max_count;
  cout << "Max number of times you want to iterate"
       << " ";
  cin >> max_count;

  // Print the header
  cout << endl
       << "**************************" << endl;
  cout << "Gen-Newton-Raphson method" << endl;
  cout << "**************************" << endl;
  cout << "" << endl;
  cout << "Data in tabular form" << endl;
  cout << "SNO."
       << "\t\t"
       << "x"
       << "\t\t"
       << "x'"
          "\t\t"
       << "f(x1)" << endl;

  while (!has_converged && count < max_count)
  {
    // Find the next guess
    new_guess = new_estimate(init_guess);
    compare_guess = compare_estimate(init_guess);
    count++;
    // Print the new guess
    cout << count << "\t\t" << new_guess << setprecision(4) << "\t\t" << compare_guess << setprecision(4) << "\t\t" << f(new_guess) << setprecision(4) << endl;

    // Check for convergence
    if (fabs(new_guess - compare_guess) < accuracy)
      has_converged = true;

    // Loop back to guess again
    init_guess = new_guess;
  }

  // Print the final root
  cout << "------------------------------------------------------------------" << endl;

  if (count < max_count)
  {
    cout << "The root of the equation is " << new_guess;
  }
  else
  {
    cout << "max number of iterations reached"
         << " " << max_count << endl;
    cout << "The best root is"
         << " " << new_guess;
  }

  return 0;
}