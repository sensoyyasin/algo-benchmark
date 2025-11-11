#include "main.hpp"

int selectAndReArrange2(vector<int> &arr, int low, int high, int pivotValue)
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

int medianOfThree(vector<int> &arr, int low, int high) {
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
		swap(arr[low], arr[mid]);
    if (arr[mid] > arr[high])
		swap(arr[mid], arr[high]);
    if (arr[low] > arr[mid])
		swap(arr[low], arr[mid]);

    return arr[mid];
}

void quickSortMedianOfThree(vector<int> &arr, int start, int end)
{
    if (end > start)
    {
		int pivotValue = medianOfThree(arr, start, end);
        int pi = selectAndReArrange2(arr, start, end, pivotValue);

        quickSortMedianOfThree(arr, start, pi - 1);
        quickSortMedianOfThree(arr, pi + 1, end);
    }
}
