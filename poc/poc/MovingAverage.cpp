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

//RandomMovingAverage::RandomMovingAverage() {}
//RandomMovingAverage::~RandomMovingAverage() {}

void RandomMovingAverage::newValue()
{
	float firstValue = rand() % 10 + 1;			// random(1, 10);
	float secondValue = rand() % 10 + 1;		// random(1, 10);
	currentValue = currentValue + 
		firstValue / y - secondValue / y;
}