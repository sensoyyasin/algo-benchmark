#include "main.hpp"

void bubbleSort(vector<int> &arr, int n)
{
    int i = n;
    while (i > 0)
    {
        bool isSwapped = false;
        int j = 0;
        while (j < i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
            j += 1;
        }
        if (!isSwapped)
            break;
        i -= 1;
    }
}
