//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip> 
using namespace std;

#include "MovingAverage.h"
float a[] = { 0, 7, 10, 9, 7.1, 7.5, 7.4, 12, 15, 10, 0, 3, 3.5, 4, 1, 7, 1 };

// Simple moving average plot
int currentDataPoint = 0;
float simple_moving_average_previous = 0;
int NUM_Y_VALUES = 17;

float simple_moving_average() {
	uint32_t startingValue = currentDataPoint;
	uint32_t endingValue = (currentDataPoint + 1) % NUM_Y_VALUES;
	float simple_moving_average_current = simple_moving_average_previous +
		(a[startingValue]) / NUM_Y_VALUES -
		(a[endingValue]) / NUM_Y_VALUES;

	currentDataPoint + rand() % 2 + 1;
	currentDataPoint = currentDataPoint % NUM_Y_VALUES;

	simple_moving_average_previous = simple_moving_average_current;
	return simple_moving_average_current;
}

int main()
{
	cout << "Please press enter for new MA Test.";
	MovingAverage ma;
	RandomMovingAverage rma = RandomMovingAverage();
	SimpleMovingAverage sma = SimpleMovingAverage();
	CumulativeMovingAverage cma = CumulativeMovingAverage();
	WeightedMovingAverage wma = WeightedMovingAverage();
	ExponentialMovingAverage ema = ExponentialMovingAverage();

	for (float f : a) {
		rma.addValue(f);
		sma.addValue(f);
		cma.addValue(f);
		wma.addValue(f);
		ema.addValue(f);
	}

	while (true)
	{
		cin.get();
		cout << left
			<< "MA:  " << setw(6) << ma.getNewValue()
			<< "RMA: " << setw(10) << rma.getNewValue()
			<< "SMA: " << setw(10) << sma.getNewValue()
			<< "CMA: " << setw(10) << cma.getNewValue()
			<< "WMA: " << setw(10) << wma.getNewValue()
			<< "EMA: " << setw(10) << ema.getNewValue()
			//<< "Classic: " << setw(8) << simple_moving_average()
			;
	}
	return 0;
}