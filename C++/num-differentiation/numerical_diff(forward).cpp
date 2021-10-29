//forward derivative
#include <iostream>
using namespace std;

int main()
{
  int i, j, n;

  // Input Section
  cout << "Enter number of data points: ";
  cin >> n;

  // Allocate the arrays
  float *x = new float[n];
  float *y = new float[n * n];

  // Get the first x
  cout << "Enter the lowest value of x i.e. x[0]: ";
  cin >> x[0];

  // And get the spacing
  cout << "Enter the spacing, h: ";
  float h;
  cin >> h;

  for (int i = 1; i < n; i++)
    x[i] = x[0] + i * h;

  // Input the y values
  for (i = 0; i < n; i++)
  {
    cout << "x[" << i << "] = " << x[i] << ": y[" << i << "] = ";
    cin >> y[i * n];
  }

  // Generating Forward Difference Table

  for (i = 1; i < n; i++)
  {
    for (j = 0; j < n - i; j++)
    {
      y[j * n + i] = y[(j + 1) * n + (i - 1)] - y[j * n + (i - 1)];
    }
  }

  // Display the header
  cout << endl
       << "**************************";
  cout << endl
       << "FORWARD DIFFERENCE TABLE";
  cout << endl
       << "**************************" << endl;
  cout << endl
       << "" << endl;
  ;

  // Displaying Forward Difference Table

  cout << "-------------------------------------------" << endl;

  cout << "X"
       << "\t"
       << "   "
       << "Y";
  for (int i = 0; i < n - 1; i++)
    cout << "\t"
         << " "
         << "y" << i + 1;
  cout << endl;

  cout << "-------------------------------------------" << endl;
  for (i = 0; i < n; i++)
  {
    cout << x[i];
    for (j = 0; j < n - i; j++)
    {
      cout << "\t"
           << "|" << y[i * n + j];
    }
    cout << endl;
  }

  // Now ask the user for a value of x

  cout << "Enter a value of x: ";
  float x_user;
  cin >> x_user;

  // Check this is one of the entered values

  int k;
  for (k = 0; k < n; k++)
    if (x[k] == x_user)
      break;

  if (k == n)
  {
    cout << "The value entered is not one of the entered values of x" << endl;
    return 2;
  }

  // Calculate the value of dy/dx

  float dydx = 0;
  int sign = 1;

  for (int i = 2; i <= n - k; i++)
  {
    dydx += sign * y[k * n + i - 1] / (i - 1);
    sign *= -1;
  }

  dydx /= h;

  cout << "dy/dx at x = " << x_user << " is " << dydx;

  // Finished successfully

  return 0;
}