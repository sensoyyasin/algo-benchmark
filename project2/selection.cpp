#include "main.hpp"

void selectionSort(vector<int> &arr, int size)
{
	int i = 0;
	while (i < size)
	{
		int j = i + 1;
		int bestMinIndex = i;
		while (j < size)
		{
			if (arr[j] < arr[bestMinIndex])
				bestMinIndex = j;
			j += 1;
		}
		swap(arr[i], arr[bestMinIndex]); // find min index and put zero.
		i += 1;
	}
}
