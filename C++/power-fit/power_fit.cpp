// question : y = 3x^1.5
#include <iostream>
using namespace std;
#include <math.h>

int main()
{
    int i;

    int n = 6; // n is the no. of data points
    double x[6] = {1, 2, 3, 4, 5, 6};
    double y[6] = {2.98, 7.26, 11.75, 22.72, 27.20, 38.57};

    // Initialize all the variables
    // float* x = new float[n];  //  observed x cordinate or experimental x cordinates
    // float* y = new float[n]; // observed y cordinate or experimental y cordinates 1
    double *yc = new double[n];    // y co-ordinate of best line
    double *error = new double[n]; // modular  difference  btw the observed y co-ordinate and exp y co-ordinate
    double sumX = 0;               // SumX = sum of all observed x
    double sumY = 0;               // SumY = sum of all observed y
    double sumX2 = 0;              //  SumX2 = sum of all observed x squared
    double sumXY = 0;              // // SumXY = sum of all observed x times  sum of all observed y
    double a = 0;                  // here a is the slope best fit line
    double b = 0;                  //  b is the intercept of best fit line

    /*for (int i= 0; i<n; i++){
           cout<<"Enter "<<i<<"th value for x:- ";
           cin>> x[i];
           cout<<"Enter "<<i<<"th value for y:- ";
           cin>>y[i];
           cout <<"Value stored"<<endl;
    }*/

    // create arrays for log_x and log_y of size n for the input data points

    double *log_x = new double[n];
    double *log_y = new double[n];

    // fill the log_x and log_y arrays using math.h

    for (i = 0; i < n; i++)
    {

        log_x[i] = log(x[i]);
        log_y[i] = log(y[i]);
    }

    /* variables needed for cal. of coef co-relation

    double Ybar , Sy = 0, S = 0, cc;
    Ybar = sumY/n;
    */
    for (i = 0; i < n; i++)
    {
        sumX = sumX + log_x[i];
        sumY = sumY + log_y[i];
        sumXY = sumXY + (log_x[i] * log_y[i]);
        sumX2 = sumX2 + (log_x[i] * log_x[i]);
    }
    // The equation of best fit line ---> y = ax+b
    // here a intercept and b is the intercept

    a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / n;

    double prefactor = exp(b);

    cout << "exponent -> " << a << endl;
    cout << "prefactor -> " << prefactor << endl;

    cout << "Equation is -> y = " << prefactor << "x ^ " << a << "\n\n";

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

        yc[i] = prefactor * pow(x[i], a);
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