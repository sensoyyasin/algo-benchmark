#include "main.hpp"

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    int i = 0;

    while (i < n1)
    {
        L[i] = arr[l + i];
        i += 1;
    }

    int j = 0;
    while (j < n2)
    {
        R[j] = arr[m + 1 + j];
        j += 1;
    }

    i = 0;
    j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i += 1;
            k += 1;
        }
        else if (L[i] >= R[j])
        {
            arr[k] = R[j];
            j += 1;
            k += 1;
        }
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i += 1;
        k += 1;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
