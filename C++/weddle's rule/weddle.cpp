#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Define the fn whose integral you want to calculate
double f(double x)
{
  double a = 1 / (1 + pow(x, 2));
  return a;
}

// Set precision and intedentation

void print_num(float x, int width = 10, int precision = 5)
{
  cout << setw(width) << setprecision(precision) << x;
}

int main()
{

  // declare the variables
  float lower_limit, upper_limit, integration = 0.0, step_size, k, s0, s1, s2, s3, s4;
  int i, num_intervals;

  cout << "******************************************************" << endl;
  cout << "WEEDLE'S RULE" << endl;
  cout << "******************************************************" << endl;

  // Input
  cout << "Enter lower limit of integration: ";
  cin >> lower_limit;
  cout << "Enter upper limit of integration: ";
  cin >> upper_limit;
  cout << "Enter number of sub intervals: ";
  cin >> num_intervals;

  // only works when number of intervals is even

  if (num_intervals % 6 == 0)
  {
    num_intervals = num_intervals;

    // Finding step size
    step_size = (upper_limit - lower_limit) / num_intervals;

    // Printing the table

    cout << "******************************************************" << endl;
    cout << setw(2) << "S.NO" << setw(20) << "lower_limit+i*h" << setw(30) << "f(lower_limit+i*h)" << endl;
    cout << "******************************************************" << endl;

    for (i = 0; i <= num_intervals; i++)
    {
      print_num(i, 2);
      print_num(lower_limit + i * step_size, 20);
      print_num(f(lower_limit + i * step_size), 20);
      cout << endl;
    }

    // Finding Integration Value
    s0 = f(lower_limit) + f(upper_limit);

    for (i = 1; i <= num_intervals - 1; i = i + 6)
      s1 += 5 * (f(lower_limit + i * step_size) + f(lower_limit + (i + 4) * step_size));

    for (i = 3; i <= num_intervals - 3; i = i + 6)
      s2 += 6 * (f(lower_limit + i * step_size));

    for (i = 2; i <= num_intervals - 2; i = i + 6)
      s3 += (f(lower_limit + i * step_size) + f(lower_limit + (i + 2) * step_size));

    for (i = 6; i <= num_intervals - 6; i = i + 6)
      s4 += 2 * (f(lower_limit + i * step_size));

    integration = ((3 * step_size) / 10) * (s0 + s1 + s2 + s3 + s4);

    cout << endl
         << "Required value of integration is: " << integration;
  }
  else
  {

    cout << "Number of intervals  should be a multiple of 6 number." << endl;
  }

  return 0;
}
