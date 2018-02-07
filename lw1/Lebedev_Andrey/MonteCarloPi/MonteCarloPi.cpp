#include "stdafx.h"
#include "IMonteCarloPiCalculator.h"
#include "SingleThreadPiCalculator.h"

int main(int argc, char** argv)
{
	SetConsoleOutputCP(1251);
	IMonteCarloPiCalculator* piCalculator;
	unsigned long long iterationsNumber;
	const double circleRadius = 1.;

	if (argc == 2)
	{
		iterationsNumber = strtoull(argv[1], nullptr, 10);
		piCalculator = new SingleThreadPiCalculator(iterationsNumber, circleRadius);
	}
	else
	{
		std::cout << "Неверное количество входных параметров\n"
			<< "MonteCarloPi.exe <кол-во итераций>"
			<< std::endl;
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

