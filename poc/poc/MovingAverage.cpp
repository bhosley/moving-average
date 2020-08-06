#include "MovingAverage.h"
#include <stdlib.h>
#include <vector>
#include <math.h>

MovingAverage::MovingAverage(float f) { init(f); }
void MovingAverage::init(float f) { currentValue = f; x++; }
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
float MovingAverage::addValue(float f)
{
	yVals.push_back(f);
	y++;
	return currentValue;
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

SimpleMovingAverage::SimpleMovingAverage() {}
SimpleMovingAverage::SimpleMovingAverage(float f) { init(f); }
float SimpleMovingAverage::addValue(float f)
{
	x++;
	currentValue = currentValue + ((f - previousValue) / x);
	previousValue = currentValue;
	return currentValue;
}

/*--------------------Cumulative-Moving-Average--------------------*/

CumulativeMovingAverage::CumulativeMovingAverage() {}
CumulativeMovingAverage::CumulativeMovingAverage(float f) { init(f); }
float CumulativeMovingAverage::addValue(float f)
{
	// Arithmetic mean of accumulating values
	x++;
	//currentValue = ( f + (x - 1) * currentValue) / (x);
	currentValue = currentValue + ((f - currentValue) / (x));
	return currentValue;
}

/*---------------------Weighted-Moving-Average---------------------*/

WeightedMovingAverage::WeightedMovingAverage() {}
WeightedMovingAverage::WeightedMovingAverage(float f) { init(f); }
float WeightedMovingAverage::addValue(float f)
{
	// Arithmetic mean in which earlier values have higher weight
	x++;
	currentValue = ((currentValue * x) + f) / (x);
	return currentValue;
}

/*-------------------Exponential-Moving-Average--------------------*/

ExponentialMovingAverage::ExponentialMovingAverage() {}
ExponentialMovingAverage::ExponentialMovingAverage(float f) { init(f); }
float ExponentialMovingAverage::addValue(float f)
{
	currentNumerator = currentNumerator + (f * pow( a,x ));
	currentDenominator = currentDenominator + pow( a,x );
	currentValue = currentNumerator / currentDenominator;
	x++;
	return currentValue;
}