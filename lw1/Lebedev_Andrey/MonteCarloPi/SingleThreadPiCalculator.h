#pragma once
#include "IMonteCarloPiCalculator.h"
#include "IRandomNumberGenerator.h"
#include "RandomNumberGenerator.h"

class CSingleThreadPiCalculator : public IMonteCarloPiCalculator
{
public:
	CSingleThreadPiCalculator(size_t iterationsNumber, double circleRadius);

	double getPi() override;

protected:
	bool isRandomDotInsideCircle(IRandomNumberGenerator * numberGenerator) const;

	const size_t mIterationsNumber;
	const double mCircleRadius;
};

