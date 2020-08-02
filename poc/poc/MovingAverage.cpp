#include "MovingAverage.h"

MovingAverage::MovingAverage() { currentValue = 0; }
MovingAverage::MovingAverage(float f) { currentValue = f; }
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
	currentValue = currentValue++;
}



RandomMovingAverage::RandomMovingAverage()
{
}

RandomMovingAverage::~RandomMovingAverage()
{
}