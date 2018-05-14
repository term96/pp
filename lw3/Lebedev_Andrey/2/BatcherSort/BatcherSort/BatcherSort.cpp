#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "BatcherAlgorithm.h"

inline void printVector(std::vector<int> const & vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "Use: batchersort.exe <input file name>\n";
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Failed to open file\n";
		return 1;
	}

	std::vector<int> vector;
	int num;
	while (file >> num)
	{
		vector.push_back(num);
	}

	CBatcherAlgorithm batcherAlgorithm;
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
	batcherAlgorithm.sort(vector);
	std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();
	long long timeElapsedInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

	std::cout << "Algorithm work time: " << timeElapsedInMs << "ms\n" << "Result: ";
	printVector(vector);

	return 0;
}
