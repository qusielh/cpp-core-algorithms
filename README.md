# C++ Core Algorithms & Utilities

A curated collection of standalone C++ implementations focusing on low-level memory hygiene, algorithmic efficiency, and foundational data structures.

---

## Modules Overview

| Module | Description | Key Focus / Highlights |
| :--- | :--- | :--- |
| [**01-matrix-digit-frequency**](./01-matrix-digit-frequency/) | 2D matrix frequency distribution counter | Raw pointer heap management, custom stream insertion operator |
| [**02-descriptive-statistics**](./02-descriptive-statistics/) | Descriptive summary statistics ($\mu$, Median, $Q_1$, $Q_3$, Range) | Pointer const-correctness, statistical array partitioning |
| [**03-word-suffix-counter**](./03-word-suffix-counter/) | String array filter counting matching terminal characters | Reference counting, heap buffer lifecycle management |
| [**04-polynomial-arithmetic**](./04-polynomial-arithmetic/) | Polynomial addition, subtraction, and multiplication | Discrete convolution / Cauchy product, dense vector alignment |
| [**05-simultaneous-min-max**](./05-simultaneous-min-max/) | Optimal pairwise search for minimum and maximum values | $\lceil 1.5n \rceil - 2$ optimal comparison bound, `std::chrono` benchmarks |
| [**06-descending-stack-merger**](./06-descending-stack-merger/) | Merges two unsorted stacks into a descending ordered stack | In-place two-pointer deduplication, LIFO inversion logic |

---

## Technical Highlights

* **Memory Hygiene:** Explicit heap lifecycle tracking (`new` / `delete[]`) with strict pointer nullification to prevent memory leaks and dangling references.
* **Pass-by-Reference:** Minimizes CPU cache evictions and eliminates deep-copy overhead across function boundaries.
* **Idiomatic C++:** Custom operator overloads (`operator<<`), modern type aliasing (`using`), and zero-overhead standard abstractions where appropriate.

---

## Build Requirements

Each utility is self-contained and requires only a standard C++17 compiler:

* **MSVC:** Visual Studio 2019+
* **GCC:** `g++` 9.0+
* **Clang:** `clang++` 9.0+