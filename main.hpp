#ifndef MAIN_HPP
#define MAIN_HPP

#include <random>
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>

#define YELLOW  "\033[33m"
#define RED    "\033[36m"
#define GREEN	"\033[32m"
#define RESET   "\033[0m"

using namespace std;

void bubbleSort(vector<int> &arr, int n);
void insertionSort(vector<int> &arr, int size);
void merge(vector<int> &arr, int l, int m, int r);
void mergeSort(vector<int> &arr, int start, int end);
int selectAndReArrange(vector<int> &arr, int low, int high);
void quickSort(vector<int> &arr, int start, int end);
int selectAndReArrange(vector<int> &arr, int low, int high, int pivotValue);
int medianOfFive(vector<int> &arr, int start);
void quickSortMedian(vector<int> &arr, int start, int end);
void selectionSort(vector<int> &arr, int size);
void quickSortMedianOfThree(vector<int> &arr, int start, int end);
int medianOfThree(vector<int> &arr, int low, int high);
int selectAndReArrange2(vector<int> &arr, int low, int high, int pivotValue);


#endif
