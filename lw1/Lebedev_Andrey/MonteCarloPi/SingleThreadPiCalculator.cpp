#include "stdafx.h"
#include "SingleThreadPiCalculator.h"

const double CSingleThreadPiCalculator::CIRCLE_RADIUS = 1.;

CSingleThreadPiCalculator::CSingleThreadPiCalculator(size_t iterationsNumber)
	: mIterationsNumber(iterationsNumber)
{
}

double CSingleThreadPiCalculator::getPi()
{
	IRandomNumberGenerator * numberGenerator = new CRandomNumberGenerator(-CIRCLE_RADIUS, CIRCLE_RADIUS);
	size_t dotsInsideCircle = 0;

	for (size_t i = 0; i < mIterationsNumber; i++) 
	{
		if (isRandomDotInsideCircle(numberGenerator))
		{
			++dotsInsideCircle;
		}
	}

	delete numberGenerator;
	return 4. * dotsInsideCircle / mIterationsNumber;
}

bool CSingleThreadPiCalculator::isRandomDotInsideCircle(IRandomNumberGenerator * numberGenerator)
{
	double x = numberGenerator->getRandomDouble();
	double y = numberGenerator->getRandomDouble();
	return x * x + y * y <= CIRCLE_RADIUS * CIRCLE_RADIUS;
}
