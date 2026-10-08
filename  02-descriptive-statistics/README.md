# Descriptive Statistics & Quartile Analyzer

A C++ utility that reads an unsorted numerical dataset and computes essential summary statistics: Arithmetic Mean, Median, First Quartile ($Q_1$), Third Quartile ($Q_3$), and Range.

---

## Overview

The program prompts for the dataset size $n$ followed by the sequence of values. It aggregates sums during stream extraction, sorts the dataset, and performs parity-based index calculations to extract the median and quartiles (interquartile boundaries).

---

## Metrics Computed

* **Arithmetic Mean ($\mu$):** Accumulated sum divided by sample size $n$.
* **Range:** Absolute spread between the maximum and minimum values ($array[n-1] - array[0]$ post-sort).
* **Median ($Q_2$):** Middle element for odd-length datasets, or arithmetic average of the two central elements for even-length datasets.
* **Quartiles ($Q_1$ & $Q_3$):** Median values of the lower and upper subsets partitioned around the sample median.

---

## Implementation Details

* **Reference Outputs:** Output metrics (`avg`, `med`, `q1`, `q3`, `rng`) are passed by reference (`float&`) to eliminate copy overhead and avoid complex wrapper structs.
* **Pointer Const-Correctness:** Analysis functions enforce double const qualification (`const int* const array`), guaranteeing that neither the target array data nor the pointer itself can be mutated during statistical passes.
* **Manual Heap Management:** The primary buffer is dynamically allocated on the heap and explicitly deallocated (`delete[]`) with pointer nullification to prevent memory leaks.
* **Hybrid Sorting:** Utilizes `std::sort` ($O(n \log n)$ introsort) prior to position-based quartile slicing.

---

## Sample Run

```text
Please enter the desired size of the array: 7
Please enter the elements of the array: 12 5 22 30 7 18 15
arthmetic mean: 15.5714
median: 15
first quartile: 7
third quartile: 22
range: 25
```

---

## How to Run

Compile using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp -o descriptive_stats
./descriptive_stats
```# cpp-core-algorithms
Low-level C++ implementations of classical algorithms, custom data structures, and mathematical utilities.
