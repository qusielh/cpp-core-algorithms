# Polynomial Arithmetic Engine

A C++ program that models single-variable polynomials and computes their addition, subtraction, and multiplication (Cauchy product / convolution).

---

## Overview

Polynomials are represented in dense form using coefficient vectors ordered from the highest degree down to the constant term:

$$P(x) = c_0 x^d + c_1 x^{d-1} + \dots + c_d$$

Given two arbitrary-degree polynomials, the program aligns their degree terms to compute:
1. **Addition ($P_1 + P_2$)**
2. **Subtraction ($P_1 - P_2$)**
3. **Multiplication ($P_1 \times P_2$)**

---

## Mathematical Logic

* **Degree Alignment (Addition / Subtraction):** The resulting degree matches $\max(\deg P_1, \deg P_2)$. Coefficients with matching exponents are combined from the constant term upward, and unshared higher-degree terms are preserved directly.
* **Discrete Convolution (Multiplication):** Each coefficient $c_i$ of $P_1$ is distributed across each coefficient $c_j$ of $P_2$, accumulating into index $i + j$:
  $$\text{multi}[i + j] += P_1[i] \cdot P_2[j]$$
  The product requires a buffer size of $(n + m - 1)$.

---

## Implementation Details

* **Modern Type Aliasing:** Uses `using f_poly = std::vector<float>;` for cleaner signatures and readability.
* **Pass-by-Reference:** Vectors are passed by reference (`f_poly&`) across initializers and operator functions to eliminate buffer reallocations and copies.
* **Stream Insertion Overload:** Custom `operator<<` formats polynomials in vector notation directly via `std::cout`.
* **Dense Layout Pre-sizing:** Utilizes `.resize()` to pre-allocate exact capacity upfront, avoiding dynamic reallocations during polynomial aggregation.

---

## Sample Run

Using $(2x^2 + 4x - 5)$ and $(3x + 2)$:

```text
Please enter the size of each Polynomial
size of first poly: 3
size of second poly: 2
for the polynomials input, you just have to enter the coefficients
instead of '2x^2 + 4x -5' you can do 2 4 -5
please when you enter polys ensure that degrees go one by one
this code is unable to solve polys that have missing degrees 
like '2x^3 + 5' because the degree of x^2 and x are missing
Please enter the elements of the first polynomial: 2 4 -5
Please enter the elements of the second polynomial: 3 2

-----------------------------
Addition: { 2, 7, -3 }
Subtraction: { 2, 1, -7 }
Multiplication: { 6, 16, -7, -10 }
```

---

## How to Run

Compile using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp -o poly_ops
./poly_ops
```