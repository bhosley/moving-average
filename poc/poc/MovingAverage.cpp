#include "MovingAverage.h"
#include <stdlib.h>
#include <vector>

MovingAverage::MovingAverage() { float a[] = { 0.0f }; init(a, 0); }
void MovingAverage::init(float a[], int initialValue)
{
	currentValue = initialValue;
	y = sizeof(a) / sizeof(a[0]);
	yVals.assign(a, a + y);
}

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
void MovingAverage::addValue(float f)
{
	yVals.push_back(f);
	y++;
}
void MovingAverage::changeValue(int i, float f)
{
	yVals[i] = f;
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
	currentValue = currentValue +
				(yVals[currentIndex]) / y -
				(yVals[(currentIndex + 1) % y]) / y;
	currentIndex = (currentIndex + rand() % 2 + 1) % y;
}

/*---------------------Weighted-Moving-Average---------------------*/
/*-------------------Exponential-Moving-Average--------------------*/