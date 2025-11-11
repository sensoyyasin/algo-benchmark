#include "main.hpp"

void insertionSort(vector<int> &arr, int size)
{
	int i = 1;
	while (i < size)
	{
		int j = i;
		while (j > 0)
		{
			if (arr[j - 1] > arr[j])
				swap(arr[j], arr[j - 1]);
			else
				break;
			j -= 1;
		}
		i += 1;
	}
}
