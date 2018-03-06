#include "stdafx.h"
#include "SingleThreadPiCalculator.h"

const double CSingleThreadPiCalculator::CIRCLE_RADIUS = 1.;

CSingleThreadPiCalculator::CSingleThreadPiCalculator(size_t iterationsNumber)
	: mIterationsNumber(iterationsNumber)
{
}

double CSingleThreadPiCalculator::getPi()
{
	ProgressData progressData(mIterationsNumber);
	ThreadData * threadData = new ThreadData(mIterationsNumber, &progressData);

	HANDLE progressThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)& showProgress, &progressData, 0, NULL);
	calculate(threadData);
	WaitForSingleObject(progressThread, INFINITE);
	CloseHandle(progressThread);

	return 4. * progressData.getDotsInsideCircleNumber() / mIterationsNumber;
}

bool CSingleThreadPiCalculator::isRandomDotInsideCircle(IRandomNumberGenerator * numberGenerator)
{
	double x = numberGenerator->getRandomDouble();
	double y = numberGenerator->getRandomDouble();
	return x * x + y * y <= CIRCLE_RADIUS * CIRCLE_RADIUS;
}

DWORD CSingleThreadPiCalculator::calculate(ThreadData * threadData)
{
	IRandomNumberGenerator * numberGenerator = new CRandomNumberGenerator(-CIRCLE_RADIUS, CIRCLE_RADIUS);

	for (size_t i = 0; i < threadData->iterationsNumber; i++)
	{
		if (isRandomDotInsideCircle(numberGenerator))
		{
			threadData->progressData->incrementDotsInsideCircleNumber();
		}
		threadData->progressData->incrementIterationsNumber();
	}

	delete numberGenerator;
	delete threadData;
	return 0;
}

DWORD CSingleThreadPiCalculator::showProgress(ProgressData * progressData)
{
	std::streamsize precision = std::cout.precision();
	std::cout.precision(0);
	std::cout << std::fixed;
	while (progressData->getIterationsNumber() < progressData->totalIterationsNumber)
	{
		std::cout << progressData->getIterationsNumber() << '/' << progressData->totalIterationsNumber 
			<< " [" << 100. * progressData->getIterationsNumber() / progressData->totalIterationsNumber << "%]\r";
	}

	std::cout << std::setw(50) << '\r';
	std::cout.precision(precision);
	return 0;
}