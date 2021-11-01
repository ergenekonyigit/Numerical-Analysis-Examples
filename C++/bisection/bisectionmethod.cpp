#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

/* 
Usage: ./bisectionmethod a b n-steps
*/

double a, b, stepcount;

std::vector<double> list;

double f(double x)
{
	return x * exp(-x) + pow(x, 3.0) + 1;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Incorrect Usage. See .cpp file for usage information\n";
		exit(0);
	}
	else
	{
		a = atof(argv[1]);
		b = atof(argv[2]);
		stepcount = atof(argv[3]);
	}
	list.push_back(a);

	for (int i = 1; i <= stepcount; ++i)
	{
		double mid = (a + b) / 2;
		list.push_back(mid);
		if (f(mid) * f(a) <= 0)
		{
			b = mid;
		}
		else
		{
			a = mid;
		}
	}

	for (int i = 0; i < list.size(); ++i)
	{
		std::cout << list[i] << std::endl;
		;
	}
	return 0;
}