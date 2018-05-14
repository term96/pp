#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

void compareAndExchange(int * array, int left, int right)
{
	if (array[left] > array[right])
	{
		int tempNum = array[left];
		array[left] = array[right];
		array[right] = tempNum;
	}
}

void printArray(int * array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

void printVector(std::vector<int> & vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}

void batcherSort(int * array, int size)
{
	int t, p, q, r, d;
	t = static_cast<int>(ceil(log2(size)));
	p = static_cast<int>(pow(2, t - 1));
	while (p > 0)
	{
		q = static_cast<int>(pow(2, t - 1));
		r = 0;
		d = p;
		while (q >= p)
		{
			for (int i = 0; i < size - d; i++)
			{
				if ((i & p) == r)
				{
					compareAndExchange(array, i, i + d);
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
	for (int size = 1; size <= 10; size++)
	{
		std::vector<int> vector;
		int * array = new int[size];
		for (int i = 0; i < size; i++)
		{
			vector.push_back(rand());
			array[i] = vector[i];
		}

		std::cout << "Vector: ";
		printVector(vector);

		std::cout << "Array:  ";
		printArray(array, size);

		std::sort(vector.begin(), vector.end());
		batcherSort(array, size);

		std::cout << "Vector: ";
		printVector(vector);

		std::cout << "Array:  ";
		printArray(array, size);

		for (int i = 0; i < size; i++)
		{
			if (vector[i] != array[i])
			{
				std::cout << "Error\n";
			}
		}

		delete[] array;
		std::cout << '\n';
	}
}

int main()
{
    return 0;
}
