#include "MovingAverage.h"
#include <stdlib.h>

MovingAverage::MovingAverage() { currentValue = 0; y = 1; }
MovingAverage::MovingAverage(float f) { currentValue = f; y = 1; }
MovingAverage::~MovingAverage() {}

float MovingAverage::getValue()
{
	return currentValue;
}
float MovingAverage::getNewValue()
{
	newValue();
	return currentValue;
}
void MovingAverage::newValue() 
{
	currentValue++;
}

/*----------------------Random-Moving-Average----------------------*/

void RandomMovingAverage::newValue()
{
	float firstValue = rand() % 10 + 1;			// random(1, 10);
	float secondValue = rand() % 10 + 1;		// random(1, 10);
	currentValue = currentValue + 
		firstValue / y - secondValue / y;
}

/*----------------------Simple-Moving-Average----------------------*/

void SimpleMovingAverage::newValue()
{
	short startingValue = currentValue;
	short endingValue = (currentIndex + 1) % y;
	currentValue = currentValue +
		(yValues[startingValue]) / y -
		(yValues[endingValue]) / y;

	currentIndex++;
	currentIndex = currentIndex % y;
}

/*---------------------Weighted-Moving-Average---------------------*/
/*-------------------Exponential-Moving-Average--------------------*/