#include "stdafx.h"
#include "RandomNumberGenerator.h"


double CRandomNumberGenerator::getRandomDouble()
{
	return mRealDistribution(mRandomEngine);
}

CRandomNumberGenerator::CRandomNumberGenerator(double min, double max)
	: mRandomDevice(), mRandomEngine(mRandomDevice()), mRealDistribution(min, max)
{
}


CRandomNumberGenerator::~CRandomNumberGenerator()
{
}
