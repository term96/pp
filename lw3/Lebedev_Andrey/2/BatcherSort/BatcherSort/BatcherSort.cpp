#include "stdafx.h"
#include <math.h>
#include <iostream>

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
			printArray(array, size);
			d = q - p;
			q = q / 2;
			r = p;
		}
		p = p / 2;
	}
}

int main()
{
	const int size = 16;
	int array[size] = { 503, 87, 512, 61, 908, 170, 897, 275, 653, 426, 154, 509, 612, 677, 765, 703 };

	printArray(array, size);
	batcherSort(array, size);
    return 0;
}
