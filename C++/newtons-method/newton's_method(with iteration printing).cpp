// Newton-Raphson method
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//// Define a fn whose root you want to calculate
double f(double x)
{
  double a = pow(x, 3) - 2 * x - 5.0;
  return a;
}

// Calculate the value of the derivative df/dx
double df(double x)
{
  double a = 3 * x * x - 2;
  return a;
}

double new_estimate(double x)
{
  double x_new = x - f(x) / df(x);
  return x_new;
}

int main()
{
  double init_guess, accuracy;

  // Read the input data
  cout << "Enter the desired value of accuracy (up to how many decimal places) ";
  cin >> accuracy;

  // Read the limits and accuracy
  cout << "(First) initall guess = ";
  cin >> init_guess;
  double new_guess = new_estimate(init_guess);

  bool has_converged = false;
  int count = 0;

  int max_count;
  cout << "Max number of times you want to iterate"
       << " ";
  cin >> max_count;

  // Print the header

  cout << "Data in tabular form" << endl;
  cout << "SNO."
       << "\t\t"
       << "x1"
       << "\t\t"
       << "f(x1)" << endl;

  while (!has_converged && count < max_count)
  {
    // Find the next guess
    new_guess = new_estimate(init_guess);
    count++;
    // Print the new guess
    cout << count << "\t\t" << new_guess << setprecision(4) << "\t\t" << f(new_guess) << setprecision(4) << endl;

    // Check for convergence
    if (fabs(new_guess - init_guess) < accuracy)
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
    cout << "Root is"
         << " " << new_guess;
  }

  return 0;
}