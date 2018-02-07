#include "stdafx.h"
#include "SingleThreadPiCalculator.h"
#include "IRandomNumberGenerator.h"
#include "RandomNumberGenerator.h"

double SingleThreadPiCalculator::getPi()
{
	IRandomNumberGenerator* numberGenerator = new RandomNumberGenerator(-mCircleRadius, mCircleRadius);
	double x;
	double y;
	unsigned long long dotsInsideCircle = 0;

	for (int i = 0; i < mIterationsNumber; i++) 
	{
		x = numberGenerator->getRandomDouble();
		y = numberGenerator->getRandomDouble();
		if (x * x + y * y <= mCircleRadius * mCircleRadius)
		{
			++dotsInsideCircle;
		}
	}

	delete numberGenerator;
	return 4. * dotsInsideCircle / mIterationsNumber;
}

SingleThreadPiCalculator::SingleThreadPiCalculator(unsigned long long iterationsNumber, double circleRadius)
	: mIterationsNumber(iterationsNumber), mCircleRadius(circleRadius)
{
}

SingleThreadPiCalculator::~SingleThreadPiCalculator()
{
}
