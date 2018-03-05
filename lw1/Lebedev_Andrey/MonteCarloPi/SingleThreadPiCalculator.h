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
	static void showProgress(size_t done, size_t total);

	static const double CIRCLE_RADIUS;
	const size_t mIterationsNumber;
};

