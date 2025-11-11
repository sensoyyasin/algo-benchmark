#include "main.hpp"
/*
- Best Case: The scenario where the algorithm performs the fastest.
- Average Case: The expected performance of the algorithm under typical conditions.
- Worst Case: The scenario where the algorithm takes the longest time.
*/

bool isSorted(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            return false;
    return true;
}

// Sıralama algoritmalarını test eden fonksiyon
void testAllSorts(vector<int> &v, int size)
{
    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(copy, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Bubble Sort - Duration: " << duration.count() << " seconds" << endl;
    }

    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        insertionSort(copy, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Insertion Sort - Duration: " << duration.count() << " seconds" << endl;
    }

    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        mergeSort(copy, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Merge Sort - Duration: " << duration.count() << " seconds" << endl;
    }

    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        quickSort(copy, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Quick Sort - Duration: " << duration.count() << " seconds" << endl;
    }

    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        quickSortMedian(copy, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Quick Sort with Median Duration: " << duration.count() << " seconds" << endl;
    }

    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        quickSortMedianOfThree(copy, 0, size - 1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Quick Sort with Median Of Three Duration: " << duration.count() << " seconds" << endl;
    }

    {
        auto copy = v;
        auto start = chrono::high_resolution_clock::now();
        selectionSort(copy, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        if (isSorted(copy, size))
            cout << "Selection Sort - Duration: " << duration.count() << " seconds" << endl;
    }
}

int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10000);

    int size = 10000;
    vector<int> v(size);

    //  Average Case
    for (int i = 0; i < size; i++)
        v[i] = dist(mt);

    cout << YELLOW << "Average Case (Random Data) " << RESET << std::endl;
    testAllSorts(v, size);

    //  Best Case
    iota(v.begin(), v.end(), 1);
    cout << GREEN << "\nBest Case (Already Sorted) " << RESET << std::endl;
    testAllSorts(v, size);

    // Worst case
    iota(v.begin(), v.end(), 1);
    reverse(v.begin(), v.end());
    cout << RED << "\nWorst Case (Reverse Sorted) " << RESET << std::endl;
    testAllSorts(v, size);

    return 0;
}
