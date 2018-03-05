#include "stdafx.h"
#include "SingleThreadPiCalculator.h"

CSingleThreadPiCalculator::CSingleThreadPiCalculator(size_t iterationsNumber, double circleRadius)
	: mIterationsNumber(iterationsNumber), mCircleRadius(circleRadius)
{
}

double CSingleThreadPiCalculator::getPi()
{
	IRandomNumberGenerator * numberGenerator = new CRandomNumberGenerator(-mCircleRadius, mCircleRadius);
	size_t dotsInsideCircle = 0;

	for (int i = 0; i < mIterationsNumber; i++) 
	{
		if (isRandomDotInsideCircle(numberGenerator))
		{
			++dotsInsideCircle;
		}
	}

	delete numberGenerator;
	return 4. * dotsInsideCircle / mIterationsNumber;
}

bool CSingleThreadPiCalculator::isRandomDotInsideCircle(IRandomNumberGenerator * numberGenerator) const
{
	double x = numberGenerator->getRandomDouble();
	double y = numberGenerator->getRandomDouble();
	return x * x + y * y <= mCircleRadius * mCircleRadius;
}
