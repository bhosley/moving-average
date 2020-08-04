#include "MovingAverage.h"
#include <stdlib.h>
#include <vector>

MovingAverage::MovingAverage() { float a[] = { 0.0f }; init(a); }
MovingAverage::MovingAverage(float i[], int initialValue ) { init(i, initialValue); }
void MovingAverage::init(float i[], int initialValue )
{
	currentValue = initialValue;
	y = sizeof(i) / sizeof(i[0]);
	yVals.assign(i, i + 1);
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
	short startingValue = currentIndex;
	short endingValue = (currentIndex + 1) % y;
	currentValue = currentValue +
		(yVals[startingValue]) / y -
		(yVals[endingValue]) / y;

	currentIndex++;
	currentIndex = currentIndex % y;
}

/*---------------------Weighted-Moving-Average---------------------*/
/*-------------------Exponential-Moving-Average--------------------*/