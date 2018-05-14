#include "stdafx.h"
#include "BatcherAlgorithm.h"

void CBatcherAlgorithm::sort(std::vector<int>& vector) const
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

void CBatcherAlgorithm::compareAndExchange(std::vector<int> & vector, size_t left, size_t right) const
{
	if (vector[left] > vector[right])
	{
		int tempNum = vector[left];
		vector[left] = vector[right];
		vector[right] = tempNum;
	}
}