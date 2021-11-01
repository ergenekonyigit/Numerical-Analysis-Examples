
#include <iostream>
#include <cmath>
using namespace std;

// Required accuracy

double req_accuracy = 0.001;

// Function to solve

double f(double x)
{
  return x * x * x - 2 * x - 5;
}

// Function to find the root using bisection

double bisection(double lower_limit, double upper_limit)
{
  if (abs(upper_limit - lower_limit) < req_accuracy)
    return lower_limit;

  double f_lower = f(lower_limit);
  double f_upper = f(upper_limit);

  if (f_lower * f_upper > 0)
  {
    cout << ("No root: The function values at the initial state should be opposite sign.");
    return 0;
  }
  double mid = (upper_limit + lower_limit) / 2;
  double f_mid = f(mid);

  if (f_lower * f_mid < 0)
    return bisection(lower_limit, mid);
  else
    return bisection(mid, upper_limit);
}

int main()
{
  double lower_limit, upper_limit;

  // Prompt the user for the lower and upper limit

  cout << "Enter the lower limit: ";
  cin >> lower_limit;

  cout << "Enter the upper limit: ";
  cin >> upper_limit;

  if (lower_limit == upper_limit)
  {
    cout << "The limits cannot be identical" << endl;
    return 0;
  }

  if (lower_limit > upper_limit)
  {
    double x = lower_limit;
    lower_limit = upper_limit;
    upper_limit = x;
  }

  cout << "Using limits " << lower_limit << " to " << upper_limit << endl;

  // Use bisection() to find the root

  double root = bisection(lower_limit, upper_limit);

  cout << "Root found at " << root << endl;
  // Finished

  return 0;
}