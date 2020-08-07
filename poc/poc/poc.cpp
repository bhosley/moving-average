//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip> 
using namespace std;

#include "MovingAverage.h"
float a[] = { 0, 7, 10, 9, 7.1, 7.5, 7.4, 12, 15, 10, 0, 3, 3.5, 4, 1, 7, 1 };
//float a[] = { 1, 1, 1, 1, 1, 1, 1, 1 };
int currentIndex = 0;
int lenA = sizeof(a) / sizeof(a[0]);

int main()
{
	cout << "Please press enter for new MA Test.";
	MovingAverage ma;
	RandomMovingAverage rma;
	SimpleMovingAverage sma;
	CumulativeMovingAverage cma;
	WeightedMovingAverage wma;
	ExponentialMovingAverage ema;

	while (true)
	{
		cin.get();
		
		currentIndex = (currentIndex + rand() % 2 + 1) % lenA;
		ma.addValue(a[currentIndex]);
		rma.addValue(a[currentIndex]);
		sma.addValue(a[currentIndex]);
		cma.addValue(a[currentIndex]);
		wma.addValue(a[currentIndex]);
		ema.addValue(a[currentIndex]);

		cout << left
			<< "MA:  " << setw(6) << ma.getValue()
			<< "RMA: " << setw(10) << rma.getValue()
			<< "SMA: " << setw(10) << sma.getValue()
			<< "CMA: " << setw(10) << cma.getValue()
			<< "WMA: " << setw(10) << wma.getValue()
			<< "EMA: " << setw(10) << ema.getValue();
	}
	return 0;
}