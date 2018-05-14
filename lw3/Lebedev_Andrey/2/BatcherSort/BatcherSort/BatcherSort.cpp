#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

void compareAndExchange(std::vector<int> & vector, size_t left, size_t right)
{
	if (vector[left] > vector[right])
	{
		int tempNum = vector[left];
		vector[left] = vector[right];
		vector[right] = tempNum;
	}
}

void printVector(std::vector<int> & vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}

void batcherSort(std::vector<int> & vector)
{
	int t, p, q, r, d;
	t = static_cast<int>(ceil(log2(vector.size())));
	p = static_cast<int>(pow(2, t - 1));
	while (p > 0)
	{
		q = static_cast<int>(pow(2, t - 1));
		r = 0;
		d = p;
		while (q >= p)
		{
			for (size_t i = 0; i < vector.size() - d; i++)
			{
				if ((i & p) == r)
				{
					compareAndExchange(vector, i, i + d);
				}
			}
			d = q - p;
			q = q / 2;
			r = p;
		}
		p = p / 2;
	}
}

void test()
{
	srand(time(NULL));
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
		batcherSort(vectorForBatcher);

		std::cout << "Sort:    ";
		printVector(vectorForSort);

		std::cout << "Batcher: ";
		printVector(vectorForBatcher);

		for (int i = 0; i < size; i++)
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
