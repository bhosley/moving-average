#pragma once
#include <vector>

class MovingAverage
{
public:
	MovingAverage();
	MovingAverage(float f);
	~MovingAverage();
	float getValue();
	float getNewValue();
	virtual void newValue();
	virtual float addValue(float f);
	void changeValue(int i, float f);
	int x = 0;
protected:
	void init(float a[], int initialValue);
	void init(float f);
	float currentValue;
	int y;
	std::vector<float> yVals;
	int currentIndex = 0;
private:
};

class RandomMovingAverage : public MovingAverage
{
public:
	void newValue() override;
private:
};
class SimpleMovingAverage : public MovingAverage 
{
public:
	void newValue() override;
private:
};
class CumulativeMovingAverage : public MovingAverage
{
public:
	CumulativeMovingAverage();
	CumulativeMovingAverage(float f);
	float addValue(float f) override;
private:
};
class WeightedMovingAverage : public MovingAverage
{
public:
	WeightedMovingAverage(float f);
	float addValue(float f) override;
private:
};
class ExponentialMovingAverage : public MovingAverage
{
public:
	ExponentialMovingAverage();
	ExponentialMovingAverage(float f);
	float addValue(float f) override;
	float a = 0.9f;
private:
	float currentDenominator = 0.0f;
	float currentNumerator = 0.0f;
};