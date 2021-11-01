//bisection method
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x)
{
  double a = pow(x, 3) - 2 * x - 5.0;
  return a;
}

int main()
{
  double lower_limit, upper_limit, mid_point, accuracy, f_lower, f_upper, f_mid;

  // Read the input data
  cout << "Enter the desired value of accuracy (up to how many decimal places) ";
  cin >> accuracy;

  // We use a loop to check we get a range that encloses a root
  cout << "Enter the initial guesses:" << endl;
  bool limits_valid = false;
  while (!limits_valid)
  {
    // Read the limits and accuracy
    cout << "(First) lower limit = ";
    cin >> lower_limit;
    cout << "(Second) upper limit = ";
    cin >> upper_limit;

    // Check the limits have been entered in the correct order
    if (lower_limit > upper_limit)
    {
      double x = lower_limit;
      lower_limit = upper_limit;
      upper_limit = x;
    }

    // Check the limits enclose a root. If they do exit the loop
    f_lower = f(lower_limit);
    f_upper = f(upper_limit);
    if (f_lower * f_upper < 0)
    {
      limits_valid = true;
    }
    else
    {
      // Warn the user that the limits do not enclose a root
      cout << "The limits " << lower_limit << " and " << upper_limit << " do not enclose a root:" << endl;
      cout << "f(" << lower_limit << ") = " << f_lower << endl;
      cout << "f(" << upper_limit << ") = " << f_upper << endl;
      cout << "You need to choose different limits." << endl
           << endl;
    }
  }

  // Do the bisection
  cout << "Data in tabular form" << endl;
  cout << "------------------------------------------------------------------" << endl;
  cout << "low\t\thigh\t\tmid\t\tf(mid)" << endl;
  cout << "------------------------------------------------------------------" << endl;

  // Keep going until the size of the range is equal to or less than the
  // required accuracy
  while (fabs(lower_limit - upper_limit) >= accuracy)
  {
    mid_point = (lower_limit + upper_limit) / 2.0;
    f_lower = f(lower_limit);
    f_upper = f(upper_limit);
    f_mid = f(mid_point);
    cout << lower_limit << setprecision(6) << "\t\t" << upper_limit << setprecision(6)
         << "\t\t" << mid_point << setprecision(6) << "\t\t" << f_mid << setprecision(6) << endl;

    if (f_mid == 0)
    {
      cout << "The root of the equation is " << mid_point;
      break;
    }

    if (f_lower * f_mid > 0)
    {
      lower_limit = mid_point;
    }
    else if (f_lower * f_mid < 0)
    {
      upper_limit = mid_point;
    }
  }

  cout << "------------------------------------------------------------------" << endl;
  cout << "The root of the equation is " << mid_point;

  return 0;
}