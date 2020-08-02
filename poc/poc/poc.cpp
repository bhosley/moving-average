//#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#include "MovingAverage.h"

int currentDataPoint = 0;
float simple_moving_average_previous = 0;

// Simple moving average plot
int NUM_Y_VALUES = 17;

float yValues[] = {
  0,
  7,
  10,
  9,
  7.1,
  7.5,
  7.4,
  12,
  15,
  10,
  0,
  3,
  3.5,
  4,
  1,
  7,
  1
};

// https://en.wikipedia.org/wiki/Moving_average#Simple_moving_average
float simple_moving_average() {
	uint32_t startingValue = currentDataPoint;
	uint32_t endingValue = (currentDataPoint + 1) % NUM_Y_VALUES;
	float simple_moving_average_current = simple_moving_average_previous +
		(yValues[startingValue]) / NUM_Y_VALUES -
		(yValues[endingValue]) / NUM_Y_VALUES;

	currentDataPoint++;
	currentDataPoint = currentDataPoint % NUM_Y_VALUES;

	simple_moving_average_previous = simple_moving_average_current;
	return simple_moving_average_current;
}

float random_moving_average_previous = 0;

// Same as simple moving average, but with randomly-generated data points.
float random_moving_average() {
	float firstValue = rand() % 10 + 1;			// random(1, 10);
	float secondValue = rand() % 10 + 1;		// random(1, 10);
	float random_moving_average_current = random_moving_average_previous +
		firstValue / NUM_Y_VALUES -
		secondValue / NUM_Y_VALUES;
	random_moving_average_previous = random_moving_average_current;

	return random_moving_average_current;
}


int main()
{
	cout << "Please press enter for new SMA value.";
	// int i;
	while (true)
	{
		cin.get();
		cout << "" << simple_moving_average();
	}	
	return 0;
}