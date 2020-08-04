#pragma once
#include <vector>
class MovingAverage
{
public:
	MovingAverage();
	MovingAverage(float i[], int initialValue);
	~MovingAverage();
	float getValue();
	float getNewValue();
	virtual void newValue();
	void addValue(float f);
	void changeValue(int i, float f);
protected:
	void init(float i[], int initialValue = 0);
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