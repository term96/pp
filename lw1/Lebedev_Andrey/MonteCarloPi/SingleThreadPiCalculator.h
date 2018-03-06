#pragma once
#include "IMonteCarloPiCalculator.h"
#include "IRandomNumberGenerator.h"
#include "RandomNumberGenerator.h"

class CSingleThreadPiCalculator : public IMonteCarloPiCalculator
{
public:
	CSingleThreadPiCalculator(size_t iterationsNumber);

	double getPi() override;

protected:
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

	static bool isRandomDotInsideCircle(IRandomNumberGenerator * numberGenerator);
	static DWORD calculate(ThreadData * threadData);
	static DWORD showProgress(ProgressData * progressData);

	static const double CIRCLE_RADIUS;
	const size_t mIterationsNumber;
};

