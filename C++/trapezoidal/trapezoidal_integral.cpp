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
  float lower_limit, upper_limit, I = 0.0, sum = 0, step_size;
  int i, num_intervals;

  cout << "******************************************************" << endl;
  cout << "TRAPEZOIDAL RULE" << endl;
  cout << "******************************************************" << endl;

  cout << "Enter lower limit of integration: ";
  cin >> lower_limit;
  cout << "Enter upper limit of integration: ";
  cin >> upper_limit;
  cout << "Enter number of intervals: ";
  cin >> num_intervals;

  // Calculation

  // Finding step size
  step_size = (upper_limit - lower_limit) / num_intervals;

  // Printing the table
  cout << "******************************************************" << endl;
  cout << setw(2) << "i+1" << setw(20) << "lower_limit+i*h" << setw(30) << "f(lower_limit+i*h)" << endl;
  cout << "******************************************************" << endl;

  for (i = 0; i <= num_intervals; i++)
  {
    print_num(i, 2);
    print_num(lower_limit + i * step_size, 20);
    print_num(f(lower_limit + i * step_size), 20);
    cout << endl;
  }

  // Finding Integration Value

  for (i = 1; i <= num_intervals - 1; i++)
  {
    sum = sum + f(lower_limit + (i * step_size));
  }
  I = step_size * (f(lower_limit) + 2 * sum + f(upper_limit)) / 2;

  // Final answer

  cout << endl
       << "Required value of integration is: " << I;

  return 0;
}