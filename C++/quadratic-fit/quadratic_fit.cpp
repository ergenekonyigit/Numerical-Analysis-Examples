// include header files
// question : y = 1.5-1.14x + 0.6x^2

#include <iostream>
using namespace std;

int main()
{
    int i;

    int n = 5;                             // n is the number of data set
    double x[5] = {0, 1, 2, 3, 4};         // observed x cordinate or experimental x cordinates
    double y[5] = {1, 1.8, 1.3, 2.5, 6.5}; // observed y cordinate or experimental y cordinates

    // Initialize all the variables

    // float* x = new float[n];  //  observed x cordinate or experimental x cordinates
    // float* y = new float[n]; // observed y cordinate or experimental y cordinates
    float *yc = new float[n];    // y co-ordinate of best fit curve
    float *error = new float[n]; // modular  difference  btw the observed y co-ordinate and exp y co-ordinate
    float sumX = 0;              // SumX = sum of all observed x
    float sumY = 0;              // SumY = sum of all observed y
    float sumX2 = 0;             //  SumX2 = sum of all observed x squared
    float sumX3 = 0;             //  SumX3 = sum of all observed x cubed
    float sumX4 = 0;             //  SumX2 = sum of all observed x powered 4
    float sumYX2 = 0;            // SumYX2 = sum of all observed Y co. times all observed x squared
    float sumXY = 0;             // // SumXY = sum of all observed x times  sum of all observed y

    // best fit curve is given by : yc = c + bx + ax²

    float a = 0;
    float b = 0;
    float c = 0;

    /* Loop for entering data points
          
       for (int i= 0; i<n; i++){
           cout<<"Enter "<<i<<"th value for x:- ";
           cin>> x[i];
           cout<<"Enter "<<i<<"th value for y:- ";
           cin>>y[i];
           cout <<"Value stored"<<endl;
    } */

    for (int i = 0; i < n; i++)
    {
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + (x[i] * y[i]);
        sumX2 = sumX2 + (x[i] * x[i]);
        sumX3 = sumX3 + (x[i] * x[i] * x[i]);
        sumX4 = sumX4 + (x[i] * x[i] * x[i] * x[i]);
        sumYX2 = sumYX2 + (y[i] * x[i] * x[i]);
    }

    // Calculating coef of the best fit curve
    // Reference for formula used : https://bit.ly/3yGarx1

    // Variables needed only for calculation of coef

    float s_xx = (sumX2) - (sumX * sumX / n);
    float s_xy = sumXY - sumX * sumY / n;
    float s_xx2 = (sumX3) - ((sumX) * (sumX2) / n);
    float s_x2y = (sumYX2) - ((sumX2) * (sumY) / n);
    float s_x2x2 = (sumX4) - ((sumX2 * sumX2) / n);

    a = (s_x2y * s_xx - s_xy * s_xx2) / (s_xx * s_x2x2 - s_xx2 * s_xx2);
    b = (s_xy * s_x2x2 - s_x2y * s_xx2) / (s_xx * s_x2x2 - s_xx2 * s_xx2);
    c = (sumY / n) - (b * sumX / n) - (a * sumX2 / n);

    cout << "constant -> " << c << endl;
    cout << "coef of x  -> " << b << endl;
    cout << "coef of x2  -> " << a << endl;

    cout << "Equation is -> y = " << c << "+ " << b << "x + " << a << "x^2\n\n";

    // loop for the final table showing error and yc

    for (int i = 0; i < n; i++)
    {
        yc[i] = (a + b * x[i]) + c * (x[i] * x[i]);
        error[i] = fabs(y[i] - yc[i]);
    }
    cout << "x\t\t"
         << "y\t\t"
         << "yc\t\t"
         << "error" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t\t" << y[i] << "\t\t" << yc[i] << "\t\t" << error[i] << endl;
    }
}