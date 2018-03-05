#pragma once
#include "IMonteCarloPiCalculator.h"
#include "IRandomNumberGenerator.h"
#include "RandomNumberGenerator.h"

class CSingleThreadPiCalculator : public IMonteCarloPiCalculator
{
public:
	CSingleThreadPiCalculator(size_t iterationsNumber);

	double getPi() override;

protected:
	static bool isRandomDotInsideCircle(IRandomNumberGenerator * numberGenerator);

	static const double CIRCLE_RADIUS;
	const size_t mIterationsNumber;
};

