#include "main.hpp"

int selectAndReArrange(vector<int> &arr, int low, int high)
{
    int i = low;
    int j = low;
    int k = high;

    int pivotIndex = low + rand() % (high - low + 1);
    int pivotValue = arr[pivotIndex];

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

void quickSort(vector<int> &arr, int start, int end)
{
    if (end > start)
    {
        int pivot = selectAndReArrange(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
