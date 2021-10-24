#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;

// Define the fn whose integral you want to calculate
double f(double x)
{
 double a=1/(1+pow(x,2));
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
  float lower_limit, upper_limit, integration=0.0, step_size, k;
  int i, num_intervals;

  cout<< "******************************************************" << endl;
  cout<<"1/3 SIMPSON'S RULE"<<endl;
  cout<< "******************************************************" << endl;

 // Input
   cout<<"Enter lower limit of integration: ";
   cin>>lower_limit;
   cout<<"Enter upper limit of integration: ";
   cin>>upper_limit;
   cout<<"Enter number of sub intervals: ";
   cin>>num_intervals;

   // only works when number of intervals is even
    

 if (num_intervals%2 == 0){
    num_intervals=num_intervals;
  }
  else
  {
    
    cout<<"number of intervals  should be an even number."<<endl;
    num_intervals=num_intervals+1;
    cout<<"Number of intervals is:" <<num_intervals<<endl;
  }

    // Finding step size
    step_size = (upper_limit - lower_limit)/num_intervals;

  // Printing the table

    cout<< "******************************************************" << endl;
    cout<<setw(2)<<"S.NO"<<setw(20)<<"lower_limit+i*h"<<setw(30)<<"f(lower_limit+i*h)"<<endl;
    cout<< "******************************************************" << endl;

    for(i=0;i<=num_intervals;i++)
    {
      print_num(i,2);
      print_num(lower_limit + i*step_size, 20);
      print_num(f(lower_limit+i*step_size), 20);
      cout << endl;
    }

    // Finding Integration Value
    integration = f(lower_limit) + f(upper_limit);

    for(i=1; i< num_intervals; i++)
    {
      k = lower_limit + i*step_size;

      if(i%2==0)
      {
        integration = integration + 2 * (f(k));
      }
      else
      {
        integration = integration + 4 * (f(k));
      }
    }

    integration = integration * step_size/3;

    cout<< endl <<"Required value of integration is: "<< integration;
  
 
    return 0;
  
}


