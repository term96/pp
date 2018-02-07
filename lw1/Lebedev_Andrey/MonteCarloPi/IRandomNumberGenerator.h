#pragma once
class IRandomNumberGenerator
{
public:
	virtual double getRandomDouble() = 0;
	virtual ~IRandomNumberGenerator() {};
};

