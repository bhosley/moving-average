//#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int i;
	cout << "Please enter an integer value: ";
	cin >> i;
	cout << "The value you entered is " << i;
	cout << " and its double is " << i * 2 << ".\n";
	return 0;
}


/*
int currentDataPoint = 0;
int chance = LOW_STRIKE_LIKELIHOOD;

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

float simple_moving_average_previous = 0;
float random_moving_average_previous = 0;

float(*functionPtrs[10])(); //the array of function pointers
int NUM_FUNCTIONS = 2;

float callFunction(int index) {
	return (*functionPtrs[index])(); //calls the function at the index of `index` in the array
}


// https://en.wikipedia.org/wiki/Moving_average#Simple_moving_average
float simple_moving_average() {
	uint32_t startingValue = currentDataPoint;
	uint32_t endingValue = (currentDataPoint + 1) % NUM_Y_VALUES;
	float simple_moving_average_current = simple_moving_average_previous +
		(yValues[startingValue]) / NUM_Y_VALUES -
		(yValues[endingValue]) / NUM_Y_VALUES;

	simple_moving_average_previous = simple_moving_average_current;
	return simple_moving_average_current;
}


// Same as simple moving average, but with randomly-generated data points.
float random_moving_average() {
	float firstValue = random(1, 10);
	float secondValue = random(1, 10);
	float random_moving_average_current = random_moving_average_previous +
		firstValue / NUM_Y_VALUES -
		secondValue / NUM_Y_VALUES;
	random_moving_average_previous = random_moving_average_current;

	return random_moving_average_current;
}
*/