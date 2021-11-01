

//Backward Derivative
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

  // Generating Backward Difference Table
  for (int col = 1; col < n; col++)
  {
    for (int row = n - 1; row >= 0; row--)
    {
      y[row * n + col] = y[row * n + (col - 1)] - y[(row - 1) * n + (col - 1)];
    }
  }

  // Display the header
  cout << endl
       << "**************************";
  cout << endl
       << "Backward DIFFERENCE TABLE";
  cout << endl
       << "**************************" << endl;
  cout << endl
       << "" << endl;
  ;

  // Displaying Backward Difference Table

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
    for (j = 0; j <= i; j++)
    {
      cout << "\t"
           << "|" << y[i * n + j];
    }
    cout << endl;
  }

  // Now ask the user for a value of x
  cout << "Enter a value  of x at which you want to calculate the derivate: ";
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

  if (k > 0)
    cout << "Note that this is only guaranteed to work for the last/second last value of x in the series." << endl;

  // Calculate the value of dy/dx

  float fact = 1;

  float dydx = 0;
  for (int i = 1; i <= k; i++)
  {
    dydx += y[k * n + i] / i;
  }

  dydx /= h;

  cout << "dy/dx at x = " << x_user << " is " << dydx;

  // Finished successfully

  return 0;
}
