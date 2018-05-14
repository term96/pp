#pragma once
#include <vector>

class CBatcherAlgorithm
{
public:
	void sort(std::vector<int> & vector) const;

private:
	void compareAndExchange(std::vector<int> & vector, size_t left, size_t right) const;
};
