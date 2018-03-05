#include "stdafx.h"
#include "IMonteCarloPiCalculator.h"
#include "SingleThreadPiCalculator.h"
#include "MultiThreadPiCalculator.h"

int main(int argc, char** argv)
{
	const char * helpText = "�������������: montecarlopi.exe <���-�� ��������> <���-�� �������>";
	const char * argCountError = "�������� ���������� ����������. ��������� � ���������� --help ��� ��������� ��������";
	const double circleRadius = 1.;
	SetConsoleOutputCP(1251);

	IMonteCarloPiCalculator* piCalculator;
	size_t iterationsNumber;
	size_t threadsNumber;

	if (argc == 2 && strcmp("--help", argv[1]) == 0)
	{
		std::cout << helpText << std::endl;
		return 0;
	}

	if (argc == 3)
	{
		iterationsNumber = std::atoi(argv[1]);
		threadsNumber = std::atoi(argv[2]);
		piCalculator = threadsNumber == 1
			? new CSingleThreadPiCalculator(iterationsNumber)
			: new CMultiThreadPiCalculator(iterationsNumber, threadsNumber);
	}
	else
	{
		std::cout << argCountError << std::endl;
		return 1;
	}

	std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
	double pi = piCalculator->getPi();
	std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();
	long long timeElapsedInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

	std::cout << "Calculation completed\n"
		<< "PI = " << pi << '\n'
		<< "����� ����������: " << timeElapsedInMs << "��" << std::endl;
	delete piCalculator;
	return 0;
}

