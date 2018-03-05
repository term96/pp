#pragma once
#include "IRandomNumberGenerator.h"

class CRandomNumberGenerator : public IRandomNumberGenerator
{
public:
	double getRandomDouble();

	CRandomNumberGenerator(double min, double max);
	~CRandomNumberGenerator();

private:
	std::random_device mRandomDevice;
	std::mt19937 mRandomEngine;
	std::uniform_real_distribution<> mRealDistribution;
};

