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
		void increment() {
			InterlockedIncrement(&dotsInsideCircle);
		}

		size_t getValue() {
			return dotsInsideCircle;
		}

	private:
		volatile size_t dotsInsideCircle = 0;
	};

	struct ThreadData {
		ThreadData(size_t iterationsNumber, ProgressData * progressData)
			: iterationsNumber(iterationsNumber)
			, progressData(progressData)
		{
		}

		size_t iterationsNumber;
		ProgressData * progressData;
	};

	static DWORD calculate(ThreadData * threadData);

	const size_t mThreadsNumber;
	ProgressData mProgressData;
};


