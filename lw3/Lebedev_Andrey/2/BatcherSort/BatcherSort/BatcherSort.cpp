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

int main()
{
	return 0;
}
