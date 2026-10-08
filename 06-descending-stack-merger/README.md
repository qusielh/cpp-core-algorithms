# Descending Stack Merger & Deduplicator

A C++ utility that merges two unsorted integer stacks into a single sorted stack where elements are arranged in descending order (highest value at the top), with configurable duplicate retention or elimination.

---

## Overview

Given two arbitrary stacks populated with random integers, the program extracts all elements, sorts them, optionally eliminates duplicate values, and reconstructs a target stack such that LIFO pops yield a descending sequence:

$$\text{Top} \rightarrow [x_{\max}, \dots, x_{\min}] \rightarrow \text{Bottom}$$

---

## Algorithm & Architecture

1. **Stack Extraction:** Both source stacks are drained into a unified dynamically allocated contiguous array of size $n_1 + n_2$.
2. **Ascending Sort:** The combined buffer is sorted in ascending order using `std::sort` ($O(N \log N)$).
3. **Branching Modes:**
   * **Mode 0 (Preserve Duplicates):** Retains all elements as originally counted across both stacks.
   * **Mode 1 (Remove Duplicates):** Uses an in-place two-pointer filtering algorithm (`read` and `write` indices) across the sorted buffer in $O(N)$ linear time without additional memory allocation.
4. **LIFO Inversion (Descending Top):** Because a stack operates under Last-In, First-Out semantics, pushing values in **ascending** order naturally places the largest elements at the top, ensuring descending order upon extraction.

---

## Implementation Details

* **In-Place Two-Pointer Deduplication:** Scans the sorted array by tracking adjacent boundaries (`array[read] != array[write - 1]`), overwriting duplicates in-place and truncating the logical size.
* **In-Place Construction:** Uses `stack.emplace()` instead of `push()` to avoid temporary copy-construction overhead.
* **Manual Memory Lifecycle:** Allocates the merge buffer directly on the heap with explicit cleanup (`delete[]`) and pointer nullification.

---

## Sample Run

### Mode 1: Deduplication Enabled
```text
Please enter the size of each stack to proceed
Size of first stack: 3
Size of second stack: 3
-------------------------
Now please input the elements of each stack with this format
e.g. '1 2 3 4 5..'  | or one by one following each with an 'Enter'
Elements of the first stack: 4 2 9
Done! now lets move on and fill the second stack
Elements of the second stack: 2 11 4
Would you like to keep iterated integers or remove them?
(0 to keep them, 1 to remove them): 1
Great! please wait for couple nanoseconds so
the program can process the data haha!
The Resulting Stack: 11 9 4 2 
```

---

## How to Run

Compile using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp -o stack_merger
./stack_merger
```