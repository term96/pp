#include "stdafx.h"
#include "RandomNumberGenerator.h"


double RandomNumberGenerator::getRandomDouble()
{
	return mRealDistribution(mRandomEngine);
}

RandomNumberGenerator::RandomNumberGenerator(double min, double max)
	: mRandomDevice(), mRandomEngine(mRandomDevice()), mRealDistribution(min, max)
{
}


RandomNumberGenerator::~RandomNumberGenerator()
{
}
