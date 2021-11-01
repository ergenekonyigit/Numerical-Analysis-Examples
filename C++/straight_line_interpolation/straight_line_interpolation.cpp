
// Include header files

#include <iostream>
using namespace std;

int main()
{
    int i;

    int n = 4;                     // n is the no. of data points
    double x[4] = {0, 2, 5, 7};    // observed x cordinate or experimental x cordinates
    double y[4] = {-1, 5, 12, 20}; //observed y cordinate or experimental y cordinates

    // Initialize all the variables
    // float* x = new float[n];  //  observed x cordinate or experimental x cordinates
    // float* y = new float[n]; // observed y cordinate or experimental y cordinates
    float *yc = new float[n];    // y co-ordinate of best line
    float *error = new float[n]; // modular  difference  btw the observed y co-ordinate and exp y co-ordinate
    float sumX = 0;              // SumX = sum of all observed x
    float sumY = 0;              // SumY = sum of all observed y
    float sumX2 = 0;             //  SumX2 = sum of all observed x squared
    float sumXY = 0;             // // SumXY = sum of all observed x times  sum of all observed y
    float a = 0;                 // here a is the slope best fit line
    float b = 0;                 //  b is the intercept of best fit line

    // variables needed for cal. of coef co-relation

    float Ybar, Sy = 0, S = 0, cc;

    /* Loop for entering data points
          
       for (int i= 0; i<n; i++){
           cout<<"Enter "<<i<<"th value for x:- ";
           cin>> x[i];
           cout<<"Enter "<<i<<"th value for y:- ";
           cin>>y[i];
           cout <<"Value stored"<<endl;
    } */

    for (i = 0; i < n; i++)
    {
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + (x[i] * y[i]);
        sumX2 = sumX2 + (x[i] * x[i]);
    }
    // The equation of best fit line ---> y = ax+b
    // here a intercept and b is the intercept

    a = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    b = (sumY - a * sumX) / n;

    cout << "Slope -> " << a << endl;
    cout << "Intercept -> " << b << endl;

    cout << "Equation is -> y = " << a << "x + " << b << "\n\n";

    // loop for correlation coefficient

    for (i = 0; i < n; i++)
    {
        Sy = Sy + pow((y[i] - Ybar), 2);
        S = S + pow((y[i] - (b + a * x[i])), 2);
    }

    cc = sqrt((Sy - S) / Sy);
    cout << "corelation coefficient is : " << cc << endl;

    // loop for the final table that  shows  error and yc

    for (i = 0; i < n; i++)
    {
        yc[i] = (a * x[i]) + b;
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