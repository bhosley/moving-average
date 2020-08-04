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
	void addValue(float f);
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
};
class WeightedMovingAverage : public MovingAverage
{
public:
	void newValue() override;
private:
};
class ExponentialMovingAverage : public MovingAverage
{
public:
	void newValue() override;
private:
};