
//forward difference
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
  cout << "Enter a value of x near x[0] i.e. near " << x[0] << ": ";
  float x_int;
  cin >> x_int;

  // Calculate the value of y

  float p = (x_int - x[0]) / h;
  float p_term = p;
  float fact = 1;
  float y_int = y[0];

  for (i = 1; i < n; i++)
  {
    // Add the current term
    y_int += p_term * y[i] / fact;

    // Multiply by p - i to get the new p_term
    p_term *= p - i;
    fact *= i + 1;
  }

  cout << "y[" << x_int << "] = " << y_int;

  // Finished successfully

  return 0;
}