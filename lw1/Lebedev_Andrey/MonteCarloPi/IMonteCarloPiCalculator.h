#pragma once

class IMonteCarloPiCalculator
{
public:
	virtual double getPi() = 0;
	virtual ~IMonteCarloPiCalculator() = default;
};
