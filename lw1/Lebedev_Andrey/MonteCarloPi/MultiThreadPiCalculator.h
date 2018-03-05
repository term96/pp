#pragma once
#include "SingleThreadPiCalculator.h"
class CMultiThreadPiCalculator :
	public CSingleThreadPiCalculator
{
public:
	CMultiThreadPiCalculator(size_t iterationsNumber, size_t threadsNumber, double circleRadius);

	double getPi() override;

private:
	const size_t mThreadsNumber;
};

