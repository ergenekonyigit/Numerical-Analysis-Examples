// question : https://prnt.sc/1rku1hm

#include <iostream>
using namespace std;
#include <math.h>

int main()
{
  int i;
  /*int n = 11; // n is the no. of data points
    double x[11] = {0,1,2,3,4,5,6,7,8,9,10};
    double y[11] = {2.75,3.26,4.10,6.01,6.77,8.13,10.37,10.94,15.72,17.61,23.64};*/

  int n = 5; // n is the no. of data points
  double x[5] = {1, 3, 5, 7, 9};
  double y[5] = {2.473, 6.4722, 18.427, 49.673, 135.026};

  // Initialize all the variables
  // float* x = new float[n];  //  observed x cordinate or experimental x cordinates
  // float* y = new float[n]; // observed y cordinate or experimental y cordinates

  double *yc = new double[n];    // y co-ordinate of best line
  double *error = new double[n]; // modular  difference  btw the observed y co-ordinate and exp y co-ordinate
  double sumX = 0;               // SumX = sum of all observed x
  double sumY = 0;               // SumY = sum of all observed y
  double sumX2 = 0;              //  SumX2 = sum of all observed x squared
  double sumXY = 0;              // // SumXY = sum of all observed x times  sum of all observed y
  double a = 0;                  // here a is the slope best fit line
  double b = 0;                  //  b is the intercept of best fit line

  /* Loop for entering data points
          
       for (int i= 0; i<n; i++){
           cout<<"Enter "<<i<<"th value for x:- ";
           cin>> x[i];
           cout<<"Enter "<<i<<"th value for y:- ";
           cin>>y[i];
           cout <<"Value stored"<<endl;
    } */

  // create arrays for log_x and log_y of size n for the input data points

  double *log_y = new double[n];

  // fill the log_x and log_y arrays using math.h

  for (i = 0; i < n; i++)
  {

    log_y[i] = log(y[i]);
  }

  /* variables needed for cal. of coef co-relation

    double Ybar , Sy = 0, S = 0, cc;
    Ybar = sumY/n;
    */
  for (i = 0; i < n; i++)
  {
    sumX = sumX + x[i];
    sumY = sumY + log_y[i];
    sumXY = sumXY + (x[i] * log_y[i]);
    sumX2 = sumX2 + (x[i] * x[i]);
  }
  // The equation of best fit line ---> y = ax+b
  // here a intercept and b is the intercept

  a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  b = (sumY - a * sumX) / n;

  double prefactor = exp(b);

  cout << "exponent -> " << a << endl;
  cout << "prefactor -> " << prefactor << endl;

  cout << "Equation is -> y = " << prefactor << "e ^ " << a << "x"
                                                               "\n\n";

  // loop for correlation coefficient
  /*
    for( i =0;i<n;i++)
    {
        Sy = Sy + pow((y[i]-Ybar),2);
        S = S + pow((y[i]-(b+ a*x[i])),2);
    }

    cc = sqrt((Sy-S)/Sy);
    cout<<"corelation coefficient is : "<<cc<<endl;
      */

  // loop for the final table that  shows  error and yc

  for (i = 0; i < n; i++)
  {

    yc[i] = prefactor * exp(x[i] * a);
    error[i] = fabs(y[i] - yc[i]);
  }
  cout << "x\t\t"
       << "y\t\t"
       << "yc\t\t"
       << "error" << endl;

  for (i = 0; i < n; i++)
  {
    cout << x[i] << "\t\t" << y[i] << "\t\t" << yc[i] << "\t\t" << error[i] << endl;
  }
}