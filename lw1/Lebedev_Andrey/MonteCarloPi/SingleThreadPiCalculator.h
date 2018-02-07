#pragma once
#include "IMonteCarloPiCalculator.h"

class SingleThreadPiCalculator : public IMonteCarloPiCalculator
{
public:
	double getPi();

	SingleThreadPiCalculator(unsigned long long iterationsNumber, double circleRadius);
	~SingleThreadPiCalculator();

private:
	const unsigned long long mIterationsNumber;
	const double mCircleRadius;
};

