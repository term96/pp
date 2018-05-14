#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
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

	for (size_t size = 1; size <= 10; size++)
	{
		std::vector<int> vectorForSort;
		std::vector<int> vectorForBatcher;
		for (size_t i = 0; i < size; i++)
		{
			vectorForSort.push_back(rand());
			vectorForBatcher.push_back(vectorForSort[i]);
		}

		std::cout << "Sort:    ";
		printVector(vectorForSort);

		std::cout << "Batcher: ";
		printVector(vectorForBatcher);

		std::sort(vectorForSort.begin(), vectorForSort.end());
		batcherAlgorithm.sort(vectorForBatcher);

		std::cout << "Sort:    ";
		printVector(vectorForSort);

		std::cout << "Batcher: ";
		printVector(vectorForBatcher);

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
