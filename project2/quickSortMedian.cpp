#include "main.hpp"

int selectAndReArrange(vector<int> &arr, int low, int high, int pivotValue)
{
    int i = low;
    int j = low;
    int k = high;

    while (j <= k)
    {
        if (arr[j] < pivotValue)
        {
            std::swap(arr[j], arr[i]);
            i += 1;
            j += 1;
        }
        else if (arr[j] == pivotValue)
            j += 1;
        else
        {
            std::swap(arr[j], arr[k]);
            k -= 1;
        }
    }
    return i;
}

int medianOfFive(vector<int> &arr, int start)
{
    vector<int> temp(arr.begin() + start, arr.begin() + start + 5);
    sort(temp.begin(), temp.end());
	return temp[2];
}

int medianOfMedians(vector<int> &arr, int start, int end)
{
	int n = end - start + 1;
    int numMedians = (n + 4) / 5;
    vector<int> medians(numMedians);
	int i;

	for (i = 0; i < n / 5; i++)
		medians[i] = medianOfFive(arr, start + 5 * i);

	if (i * 5 < n)
	{
        vector<int> temp(arr.begin() + start + i * 5, arr.begin() + end + 1);
        sort(temp.begin(), temp.end());
		medians[i] = temp[temp.size() / 2];
		i += 1;
	}

	if (i == 1)
		return medians[0];
    else
	    return medianOfMedians(medians, 0, i - 1);
}

void quickSortMedian(vector<int> &arr, int start, int end)
{
    if (end > start)
    {
		int pivotValue = medianOfMedians(arr, start, end);
        int pi = selectAndReArrange(arr, start, end, pivotValue);

        quickSortMedian(arr, start, pi - 1);
        quickSortMedian(arr, pi + 1, end);
    }
}
