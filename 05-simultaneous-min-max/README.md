# Optimal Simultaneous Min-Max Search & Benchmarking

An optimized C++ implementation of the simultaneous minimum and maximum search algorithm that minimizes total element comparisons to $\lceil \frac{3n}{2} \rceil - 2$, benchmarked using `std::chrono`.

---

## Overview

The standard naive approach to finding both minimum and maximum checks every element against both current bounds, costing up to $2(n - 1)$ comparisons. 

This implementation processes elements in **pairs**. By comparing two candidate elements against each other first, only the larger element is compared against the global maximum, and only the smaller is compared against the global minimum. This yields 3 comparisons for every 2 elements instead of 4.

---

## Exact Comparison Complexity

| Dataset Parity | Initial Setup | Remaining Loop Comparisons | Total Comparisons |
| :--- | :--- | :--- | :--- |
| **Odd $n$** | `min = max = arr[0]` (0 comp) | $3 \times \frac{n - 1}{2}$ | $\mathbf{\frac{3(n - 1)}{2}} \approx 1.5n - 1.5$ |
| **Even $n$** | Compare `arr[0]` vs `arr[1]` (1 comp) | $3 \times \frac{n - 2}{2}$ | $\mathbf{1 + 3 \times \frac{n - 2}{2}} = \mathbf{1.5n - 2}$ |

* **Time Complexity:** $\Theta(n)$ with exactly $\approx 1.5n$ comparisons (a 25% reduction compared to naive linear scan).
* **Space Complexity:** $O(1)$ auxiliary space.

---

## Implementation Details

* **Bitwise Parity Check:** Evaluates `size & 1` instead of `size % 2` to determine odd/even length in a single CPU instruction.
* **Fast I/O:** Unties C++ streams (`std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);`) to minimize stream flush latency during input reading.
* **High-Resolution Microbenchmarking:** Measures sub-millisecond execution times across 100,000 iterations using `std::chrono::high_resolution_clock`, reporting normalized nanosecond-level runtimes.
* **Memory Management:** Dynamically manages raw array buffers with explicit heap deallocation (`delete[]`) and pointer nullification.

---

## Sample Run

```text
Please enter the size of the array: 6
the algorithm has not started yet, it will start when all the inputs
 are taken.
Please enter the elements of the array: 15 3 29 4 82 1
-------------------------------------------------------------------------------------
the algorithm has started, and the timer is running . . .
Minimum value: 1
Maximum value : 82
Time taken: 3.4e-08seconds | 0.00034 milliseconds | 34 nanoseconds
```

---

## How to Run

Compile using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp -o min_max_bench
./min_max_bench
```