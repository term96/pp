#include "stdafx.h"
#include "MultiThreadPiCalculator.h"

CMultiThreadPiCalculator::CMultiThreadPiCalculator(size_t iterationsNumber, size_t threadsNumber)
	: CSingleThreadPiCalculator(iterationsNumber)
	, mThreadsNumber(threadsNumber)
{
}

double CMultiThreadPiCalculator::getPi()
{
	std::vector<size_t> iterationsPerThread(mThreadsNumber, mIterationsNumber / mThreadsNumber);
	size_t currentThread = 0;
	size_t remainder = mIterationsNumber % mThreadsNumber;
	for (size_t i = 0; i < remainder; i++)
	{
		iterationsPerThread[currentThread]++;
		currentThread++;
	}

	HANDLE * threads = new HANDLE[mThreadsNumber];
	for (size_t i = 0; i < mThreadsNumber; i++)
	{
		ThreadData * threadData = new ThreadData(iterationsPerThread[i], &mProgressData);
		threads[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) &calculate, threadData, 0, NULL);
	}

	WaitForMultipleObjects(mThreadsNumber, threads, true, INFINITE);
	for (size_t i = 0; i < mThreadsNumber; i++)
	{
		CloseHandle(threads[i]);
	}

	return 4. * mProgressData.getValue() / mIterationsNumber;
}

DWORD CMultiThreadPiCalculator::calculate(ThreadData * threadData)
{
	IRandomNumberGenerator * numberGenerator = new CRandomNumberGenerator(-CIRCLE_RADIUS, CIRCLE_RADIUS);

	for (size_t i = 0; i < threadData->iterationsNumber; i++)
	{
		if (isRandomDotInsideCircle(numberGenerator))
		{
			threadData->progressData->increment();
		}
	}

	delete numberGenerator;
	delete threadData;
	return 0;
}
