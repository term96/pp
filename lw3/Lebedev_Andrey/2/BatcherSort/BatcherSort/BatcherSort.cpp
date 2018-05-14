#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include "BatcherAlgorithm.h"

void printVector(std::vector<int> const & vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}

void test()
{
	srand(time(NULL));
	CBatcherAlgorithm batcherAlgorithm;

	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
	long long timeElapsedInMs;

	for (size_t size = 1000; size <= 100000; size *= 10)
	{
		std::vector<int> vectorForSort;
		std::vector<int> vectorForBatcher;
		for (size_t i = 0; i < size; i++)
		{
			vectorForSort.push_back(rand());
			vectorForBatcher.push_back(vectorForSort[i]);
		}

		std::cout << size << " elements\n";

		startTime = std::chrono::high_resolution_clock::now();
		std::sort(vectorForSort.begin(), vectorForSort.end());
		endTime = std::chrono::high_resolution_clock::now();
		timeElapsedInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		std::cout << "Sort:    " << timeElapsedInMs << "ms\n";

		startTime = std::chrono::high_resolution_clock::now();
		batcherAlgorithm.sort(vectorForBatcher);
		endTime = std::chrono::high_resolution_clock::now();
		timeElapsedInMs = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
		std::cout << "Batcher: " << timeElapsedInMs << "ms\n";

		for (size_t i = 0; i < size; i++)
		{
			if (vectorForSort[i] != vectorForBatcher[i])
			{
				std::cout << "Error\n";
				return;
			}
		}

		std::cout << '\n';
	}
}

int main()
{
	test();
	return 0;
}
