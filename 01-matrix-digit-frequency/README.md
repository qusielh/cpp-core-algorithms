# 2D Matrix Digit Frequency Counter

A lightweight C++ utility that reads an $n \times m$ matrix of single-digit integers ($0–9$) and computes the exact frequency distribution of each digit.

---

## Overview

The program prompts for the dimensions of a 2D matrix ($n$ rows by $m$ columns) and takes integer values strictly between `0` and `9`. As elements are entered, the occurrence of each digit is tracked in a fixed-size 10-element array, where index `i` maps to digit `i`.

---

## Implementation Details

* **Pass-by-Reference:** The output array `int (&digits_count)[10]` is passed by reference to avoid copying array buffers across function calls.
* **Manual Heap Management:** The 2D matrix is dynamically allocated on the heap using raw pointers (`int**`). Every row allocation is explicitly tracked, freed, and zeroed out to `nullptr` to prevent memory leaks and dangling pointers.
* **Stream Insertion Overload:** Implements an overloaded `operator<<` for the fixed-size array reference, formatting the output directly through `std::cout` without relying on ad-hoc print functions.

---

## Sample Run

```text
Please input two integers
Rows: 2
Columns: 3
------------------
to insert the elements of the matrix smoothly
please follow this pattern '0 1 2 3..' or do it one by one
matrix elements: 1 2 2 9 0 2

result: { 1, 1, 3, 0, 0, 0, 0, 0, 0, 1 }
```

---

## How to Run

Compile using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp -o matrix_frequency
./matrix_frequency
```