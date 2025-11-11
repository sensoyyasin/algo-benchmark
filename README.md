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


**Why Insertion Sort is Faster for Small Inputs than Quick Sort:**  
When discussing Big-O, constant factors are ignored. Big-O describes growth as n → ∞, but not actual runtime, especially for small n.  

- Insertion Sort: O(n²) with very small constants  
- Quick Sort: O(n log n) with much larger constants (recursive calls, stack frames, pivot selection, partitioning, comparisons/swaps)  

For small datasets, actual runtimes can be approximated by constants:  

$$\text{Insertion Sort Time} \approx 1.2 n^2$$  
$$\text{Quick Sort Time} \approx 10 n \log n$$  

| n    | Insertion Sort | Quick Sort | Faster Algorithm |
|------|----------------|------------|-----------------|
| 10   | 1.2 × 10² ≈ 120 | 10 × 10 log 10 ≈ 230 | Insertion Sort |
| 40   | 1.2 × 40² ≈ 1920 | 10 × 40 log 40 ≈ 2120 | Insertion Sort |
| 200  | 1.2 × 200² ≈ 48,000 | 10 × 200 log 200 ≈ 15,200 | Quick Sort |

**Observation:**  
- Although n² grows faster than n log n asymptotically, the larger constant factor in Quick Sort makes it slower for small n.  
- This explains why Insertion Sort can outperform Quick Sort on small datasets (≈10–50 elements).


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

### 6. Quick Sort with Median-of-Medians Pivot
The Median-of-Medians pivot selection improves Quick Sort’s worst-case performance by guaranteeing O(n log n) instead of O(n²).

**Pivot Selection Procedure:**
1. Divide the array into groups of 5 elements.  
2. Sort each group individually.  
3. Take the median of each group to form a new array of medians.  
4. Recursively compute the median of the medians array.  
5. Use this median-of-medians as the pivot for partitioning.  

> Using 5-element groups guarantees the pivot splits the array such that at least 30% of elements are less than it and at least 30% are greater than it.

**Mathematical Analysis:**  
Let n be the array size:  
1. Split n elements into ⌈n/5⌉ groups of 5.  
2. Take medians of each group → array of medians of size ⌈n/5⌉.  
3. Find the median of medians recursively (pivot m).  

The pivot m satisfies:  
- At least 3 · ⌊n/5 / 2⌋ ≈ 3n/10 elements are ≥ pivot.  
- At least 3n/10 elements are ≤ pivot.  

This ensures each subarray has at most 7n/10 elements.  

- Work per recursion level: cn  
- Depth of recursion: O(log n)  
- Total worst-case time: T(n) = O(n log n)  

**Observation:**  
Median-of-Medians Quick Sort guarantees O(n log n) worst-case performance but incurs extra computation overhead, which can make it slower on small datasets compared to standard Quick Sort.

---

### My Observations: Median-of-Three vs Standard Quick Sort
I compared standard Quick Sort with Quick Sort using the Median-of-Three pivot selection strategy.  

**Median-of-Three Pivot Selection:**  
- Median of the first, middle, and last elements used as pivot.  
- Goal: Avoid worst-case pivot choices, improve partitioning quality.  

**Experimental Observations:**  
- On **small datasets**, Median-of-Three Quick Sort outperforms standard Quick Sort.  
  - Minimal overhead, reduced recursion depth.  
- On **large datasets**, Median-of-Three Quick Sort becomes slower than standard randomized Quick Sort.  
  - Overhead of median computation compounds with recursion.  

**Conclusion:**  
- Median-of-Three is beneficial for small/partially sorted datasets.  
- For large datasets, standard randomized Quick Sort is more efficient.

<img width="726" height="406" alt="Ekran Resmi 2025-11-10 22 34 37" src="https://github.com/user-attachments/assets/d6cba1f5-0155-459d-9c7d-77b368337a16" />


<img width="711" height="407" alt="Ekran Resmi 2025-11-10 22 34 47" src="https://github.com/user-attachments/assets/54df83b6-0769-453e-87a8-2759b3eeb1f6" />



## Conclusion

Based on my measurements and observations, selecting an algorithm solely based on theoretical time complexity is not sufficient. For example, although Quick Sort with the Median-of-Medians pivot strategy guarantees O(n log n) performance even in the worst case, the extra computation required for pivot selection makes it slower than the classical Quick Sort in practice.

**Real-world observations:**
- **Small datasets (n ≈ 10–50):** Insertion Sort is often the fastest due to its very low overhead. If the list is already sorted or nearly sorted, it runs in almost O(n) time. Quick Sort and Merge Sort, despite better theoretical complexities, can be slower because of recursive calls, partitioning steps, and extra space usage. Selection Sort and Bubble Sort perform many unnecessary comparisons regardless of input order.
- **Large datasets (n ≈ 10,000+):** Merge Sort and well-implemented Quick Sort dominate due to O(n log n) complexity, consistent performance, and efficient handling of large inputs.

**Summary:**  
- For small inputs, simpler algorithms like Insertion Sort outperform more complex ones due to lower constant factors.  
- For very large datasets, algorithms with O(n log n) complexity such as Merge Sort and Quick Sort are preferable.  
- Pivot strategies in Quick Sort significantly affect practical runtime and should be chosen based on input size and characteristics.

<img width="544" height="339" alt="Ekran Resmi 2025-11-10 22 36 16" src="https://github.com/user-attachments/assets/8cac7070-ef74-4a32-94fc-6b1a4091fcca" />


<img width="606" height="335" alt="Ekran Resmi 2025-11-10 22 36 25" src="https://github.com/user-attachments/assets/c15946b1-b96a-4ae7-9844-05f4e43b3265" />

<img width="568" height="338" alt="Ekran Resmi 2025-11-10 22 36 33" src="https://github.com/user-attachments/assets/52d82b63-4b33-4dc4-ac73-caad396395ac" />


<img width="566" height="346" alt="Ekran Resmi 2025-11-10 22 36 43" src="https://github.com/user-attachments/assets/989a0cda-3cd8-4a2a-9e11-4a4569bc6e70" />

<img width="604" height="346" alt="Ekran Resmi 2025-11-10 22 36 50" src="https://github.com/user-attachments/assets/495dab95-20e1-46c1-8cc7-1797df8f29a2" />


<img width="593" height="335" alt="Ekran Resmi 2025-11-10 22 37 00" src="https://github.com/user-attachments/assets/fde4274e-560a-468f-abfc-76c96d39955f" />


Size = 10000

In this case, we’re waiting merge sort and quicksort can dominate all the algorithms
in terms of space complexity.

Approximately :

Unsorted random 10000 elements :

- Bubble Sort - Duration: 0.562018 seconds 
- Insertion Sort - Duration: 0.224414 seconds 
- Merge Sort - Duration: 0.00202379 seconds
- Quick Sort- Duration: 0.00253513 seconds 
- Quick Sort with Median Duration: 0.0289556 seconds
- Quick Sort with Median Of Three Duration: 0.00233937 seconds
- Selection Sort: 0.181618 seconds


<img width="707" height="423" alt="Ekran Resmi 2025-11-10 22 37 24" src="https://github.com/user-attachments/assets/873b917e-65d0-478d-8258-2ddaf7a68ba1" />


For 10,000 random numbers, we can see that simple sorts like Bubble, Insertion, and Selection are much slower. Bubble is the worst here with 0.56s. Merge Sort and normal Quick Sort are super fast, around 0.002s, because they are O(nlogn). Quick Sort with
Median-of-Medians is slower, 0.029s, because it does extra work for choosing pivot. But
Quick Sort with Median-of-Three is almost as fast as normal Quick Sort, 0.0023s.
So basically, when the dataset is bigger, constants and multipliers matter more, not
just the n’s.


## References

Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). *Introduction to Algorithms* (4th ed.). MIT Press.  
