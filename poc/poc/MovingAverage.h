#pragma once
#include <vector>
class MovingAverage
{
public:
	MovingAverage();
	MovingAverage(int initialValue);
	MovingAverage(int initialValue, float i[]);
	~MovingAverage();
	float getValue();
	float getNewValue();
	virtual void newValue();
	void addValue(float f);
	void changeValue(int i, float f);
//
	void init(int initialValue, float i[]);
	float currentValue;
	int y;
	std::vector<int> yVals;
	int currentIndex = 0;
protected:
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