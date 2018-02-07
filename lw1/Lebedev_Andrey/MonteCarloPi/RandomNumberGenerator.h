#pragma once
#include "IRandomNumberGenerator.h"

class RandomNumberGenerator : public IRandomNumberGenerator
{
public:
	double getRandomDouble();

	RandomNumberGenerator(double min, double max);
	~RandomNumberGenerator();

private:
	std::random_device mRandomDevice;
	std::mt19937 mRandomEngine;
	std::uniform_real_distribution<> mRealDistribution;
};

