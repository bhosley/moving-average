#pragma once
#include <vector>
class MovingAverage
{
public:
	MovingAverage();
	MovingAverage(float initialValue);
	MovingAverage(float i[]);
	MovingAverage(float initialValue, float i[]);
	MovingAverage(float i[], float initialValue);
	~MovingAverage();
	float getValue();
	float getNewValue();
	virtual void newValue();
	void addValue(float f);
	void changeValue(int i, float f);
protected:
	float currentValue;
	int y;
	std::vector<int> yVals;
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