#pragma once
#include "SingleThreadPiCalculator.h"

class CMultiThreadPiCalculator :
	public CSingleThreadPiCalculator
{
public:
	CMultiThreadPiCalculator(size_t iterationsNumber, size_t threadsNumber);

	double getPi() override;

private:
	struct ProgressData {
		ProgressData(size_t totalIterationsNumber)
			: totalIterationsNumber(totalIterationsNumber)
		{
		}

		void incrementDotsInsideCircleNumber() {
			InterlockedIncrement(&dotsInsideCircleNumber);
		}

		void incrementIterationsNumber() {
			InterlockedIncrement(&iterationsNumber);
		}

		size_t getDotsInsideCircleNumber() {
			return dotsInsideCircleNumber;
		}

		size_t getIterationsNumber() {
			return iterationsNumber;
		}

		const size_t totalIterationsNumber;
	private:
		volatile size_t dotsInsideCircleNumber = 0;
		volatile size_t iterationsNumber = 0;
	};

	struct ThreadData {
		ThreadData(size_t iterationsNumber, ProgressData * progressData)
			: iterationsNumber(iterationsNumber)
			, progressData(progressData)
		{
		}

		const size_t iterationsNumber;
		ProgressData * progressData;
	};

	static DWORD calculate(ThreadData * threadData);
	static DWORD updateProgress(ProgressData * progressData);

	const size_t mThreadsNumber;
	ProgressData mProgressData;
};
