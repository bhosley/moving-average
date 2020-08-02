#pragma once
class MovingAverage
{
public:
	MovingAverage();
	~MovingAverage();
	float getValue();
	float getNewValue();
	void newValue();
private:

};
class RandomMovingAverage : public MovingAverage
{
public:
	RandomMovingAverage();
	~RandomMovingAverage();

private:

};

RandomMovingAverage::RandomMovingAverage()
{
}

RandomMovingAverage::~RandomMovingAverage()
{
}