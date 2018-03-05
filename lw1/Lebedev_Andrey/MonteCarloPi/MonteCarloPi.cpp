#include "stdafx.h"
#include "IMonteCarloPiCalculator.h"
#include "SingleThreadPiCalculator.h"
#include "MultiThreadPiCalculator.h"

int main(int argc, char** argv)
{
	const char * helpText = "Использование: montecarlopi.exe <кол-во итераций> <кол-во потоков>";
	const double circleRadius = 1.;
	SetConsoleOutputCP(1251);

	IMonteCarloPiCalculator* piCalculator;
	size_t iterationsNumber;
	size_t threadsNumber;

	if (argc == 2 && argv[1] == "--help")
	{
		std::cout << helpText << std::endl;
		return 0;
	}
	else if (argc == 3)
	{
		iterationsNumber = std::atoi(argv[1]);
		threadsNumber = std::atoi(argv[2]);
		piCalculator = threadsNumber == 1
			? new CSingleThreadPiCalculator(iterationsNumber, circleRadius)
			: new CMultiThreadPiCalculator(iterationsNumber, threadsNumber, circleRadius);
	}
	else
	{
		std::cout << helpText << std::endl;
		return 1;
	}

	std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
	double pi = piCalculator->getPi();
	std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();
	long long timeElapsedInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

	std::cout << "PI = " << pi << '\n'
		<< "Время вычисления: " << timeElapsedInMs << "мс" << std::endl;
	delete piCalculator;
	return 0;
}

