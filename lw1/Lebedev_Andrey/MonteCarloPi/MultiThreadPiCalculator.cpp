#include "stdafx.h"
#include "MultiThreadPiCalculator.h"

CMultiThreadPiCalculator::CMultiThreadPiCalculator(size_t iterationsNumber, size_t threadsNumber)
	: CSingleThreadPiCalculator(iterationsNumber)
	, mThreadsNumber(threadsNumber)
	, mProgressData(iterationsNumber)
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

	HANDLE progressThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) &showProgress, &mProgressData, 0, NULL);
	WaitForMultipleObjects(mThreadsNumber, threads, true, INFINITE);
	WaitForSingleObject(progressThread, INFINITE);
	CloseHandle(progressThread);

	for (size_t i = 0; i < mThreadsNumber; i++)
	{
		CloseHandle(threads[i]);
	}

	return 4. * mProgressData.getDotsInsideCircleNumber() / mIterationsNumber;
}
