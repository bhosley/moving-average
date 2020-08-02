#pragma once
class MovingAverage
{
public:
	MovingAverage();
	MovingAverage(float f);
	~MovingAverage();
	float getValue();
	float getNewValue();
	virtual void newValue();
protected:
	float currentValue;
	int y;
private:
};
class RandomMovingAverage : public MovingAverage
{
public:
	void newValue() override;
private:
};
