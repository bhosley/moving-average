#pragma once
#include <vector>

class MovingAverage
{
public:
	MovingAverage();
	~MovingAverage();
	float getValue();
	float getNewValue();
	virtual void newValue();
	virtual float addValue(float f);
	void changeValue(int i, float f);
protected:
	void init(float a[], int initialValue);
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
	void newValue() override;
private:
	int x = 1;
};
class WeightedMovingAverage : public MovingAverage
{
public:
	float addValue(float f) override;
private:
	int x = 1;
};
class ExponentialMovingAverage : public MovingAverage
{
public:
	float addValue(float f) override;
	float a = 0.9f;
private:
	float currentDenominator = 0.0f;
	float currentNumerator = 0.0f;
	int x = 1;
};