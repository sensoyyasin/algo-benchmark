# Sorting Algorithms Performance Analysis

This project evaluates and compares the execution time of several sorting algorithms under different input conditions (average-case, best-case, and worst-case).

## Implemented Sorting Algorithms
- Bubble Sort  
- Insertion Sort  
- Selection Sort  
- Merge Sort  
- Quick Sort  
- Quick Sort (Median Pivot)  
- Quick Sort (Median-of-Three Pivot)

---

## Build & Run
Make sure you are in the same directory as the `Makefile`, then run:
-> make

This will compile all .cpp files into .o object files.
Link them into an executable named final.
Run the program

-> ./final

Clean Build Files

make clean



## Project Overview

Analyzing an algorithm means predicting the resources it requires, primarily computational time. Sorting algorithms are typically evaluated in terms of best-case, average-case, and worst-case running times. Common complexity classes include:
Complexity	Meaning

O(n)	Linear growth

O(n log n)	Efficient for large datasets

O(n²)	Quadratic growth, impractical for large n

## Algorithm Summaries

### 1. Insertion Sort
Efficient for small datasets. Iteratively grows a sorted output list by inserting elements in their correct positions.

**Time Complexity:**
- Best Case: O(n)  
- Average Case: O(n²)  
- Worst Case: O(n²)  

**Mathematical Analysis:**
- Outer loop runs `i` from 1 to n-1 → n-1 iterations  
- Inner loop comparisons (best case, array already sorted):  
$$\sum_{i=1}^{n-1} 1 = n-1$$  
- Inner loop comparisons (worst case, array reverse sorted):  
$$\sum_{i=1}^{n-1} i = \frac{n(n-1)}{2}$$  

**Observation:**  
Although Quick Sort has O(n log n) complexity, constant factors (recursive calls, pivot selection, partitioning) make it slower than Insertion Sort for small n (e.g., 10–50 elements).

---

### 2. Merge Sort
Divide-and-conquer algorithm: split → recursively sort → merge.

**Time Complexity:**
- Best, Average, Worst Case: O(n log n)  

**Mathematical Analysis:**
- Recurrence relation:  
$$T(n) = 2T(n/2) + n$$  
- Levels of recursion: $$\log_2 n$$  
- Total work:  
$$T(n) = n + n + \dots + n = n \log_2 n$$  

**Observation:**  
Merge Sort is consistent and efficient for large datasets.

---

### 3. Quick Sort
Divide-and-conquer with pivot selection.

**Time Complexity:**
- Best Case: O(n log n)  
- Average Case: O(n log n)  
- Worst Case: O(n²)  

**Mathematical Analysis:**
- Best case recurrence:  
$$T(n) = 2T(n/2) + n \implies O(n \log n)$$  
- Worst case recurrence:  
$$T(n) = T(n-1) + n \implies \sum_{k=1}^{n} k = \frac{n(n+1)}{2} \implies O(n^2)$$  

**Pivot Selection Variants:**
- **Median-of-Medians Pivot:** Guarantees worst-case O(n log n), slower on small datasets due to extra pivot computations.  
- **Median-of-Three Pivot:** Faster on small/partially sorted datasets, can be slower on very large datasets.

---

### 4. Selection Sort
Repeatedly selects the smallest (or largest) element and moves it to the correct position.

**Time Complexity:**
- Best, Average, Worst Case: O(n²)  

**Mathematical Analysis:**
- Comparisons:  
$$\sum_{i=0}^{n-1} (n-i-1) = \frac{n(n-1)}{2}$$  
- Swaps: n-1  

**Observation:**  
Better for very small arrays due to low overhead.

---

### 5. Bubble Sort
Simple comparison-based sort, swaps adjacent elements if out of order.

**Time Complexity:**
- Best Case (already sorted, with optimized flag): O(n)  
- Average/Worst Case: O(n²)  

**Mathematical Analysis:**
- Comparisons/swaps (worst case):  
$$\sum_{i=1}^{n-1} i = \frac{n(n-1)}{2}$$  

**Observation:**  
Efficient only for small arrays due to simple logic and low constant factors.

---

## Performance Analysis

**Dataset:** 10,000 random elements  

| Algorithm                       | Duration (seconds) |
|---------------------------------|------------------|
| Bubble Sort                      | 0.562018         |
| Insertion Sort                   | 0.224414         |
| Selection Sort                   | 0.181618         |
| Merge Sort                       | 0.002024         |
| Quick Sort                       | 0.002535         |
| Quick Sort (Median Pivot)        | 0.028956         |
| Quick Sort (Median-of-Three)     | 0.002339         |

**Observation:**  
- For large datasets, O(n log n) algorithms dominate.  
- Median-of-Medians Quick Sort is slower than standard Quick Sort for large arrays due to extra pivot computation.  
- Median-of-Three Quick Sort is almost as fast as standard Quick Sort for small and partially sorted datasets.

---

## Observations

- Selecting an algorithm solely by theoretical complexity is not sufficient.  
- **Small datasets (n ≈ 10–50):** Insertion Sort often outperforms others due to low overhead.  
- **Large datasets (n ≈ 10,000+):** Merge Sort and well-implemented Quick Sort dominate.  
- Pivot strategies in Quick Sort significantly affect practical runtime.

---

## Conclusion

- Practical performance depends on constants, overhead, and input characteristics, not only Big-O.  
- Simpler algorithms like Insertion Sort can beat complex algorithms for small inputs.  
- Merge Sort is reliable for very large datasets.  
- Quick Sort with good pivot selection (Median-of-Three) balances speed and reliability for typical cases.

---

## References

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). *Introduction to Algorithms* (4th ed.). MIT Press.  
