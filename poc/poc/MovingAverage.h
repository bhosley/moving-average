#pragma once
class MovingAverage
{
public:
	MovingAverage();
	MovingAverage(float f);
	~MovingAverage();
	float getValue();
	float getNewValue();
	void newValue();
private:
	float currentValue;
};
class RandomMovingAverage : public MovingAverage
{
public:
	RandomMovingAverage();
	~RandomMovingAverage();
private:

};
