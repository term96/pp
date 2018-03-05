#include "stdafx.h"
#include "MultiThreadPiCalculator.h"

CMultiThreadPiCalculator::CMultiThreadPiCalculator(size_t iterationsNumber, size_t threadsNumber, double circleRadius)
	: CSingleThreadPiCalculator(iterationsNumber, circleRadius)
	, mThreadsNumber(threadsNumber)
{
}

double CMultiThreadPiCalculator::getPi()
{
	return 0.0;
}
