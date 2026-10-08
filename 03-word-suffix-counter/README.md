# Word Suffix Frequency Counter

A lightweight C++ utility that analyzes an array of words and counts how many end with a specific user-defined character.

---

## Overview

The program prompts for the number of words $n$, reads the tokens into dynamically allocated storage, takes a target character filter, and iterates through each word to check whether its terminal character matches the target.

---

## Implementation Details

* **Reference Counting:** The accumulation counter (`int& count`) is passed by reference, updating the result directly without creating redundant return values or temporary objects.
* **Heap Buffer Management:** An array of `std::string` objects is allocated on the heap (`new std::string[size]`) and explicitly freed using `delete[]` followed by resetting the pointer to `nullptr`.
* **Index-Based Character Traversal:** Inspects the last character of each string via `words[i][words[i].length() - 1]` for direct $O(1)$ terminal character lookup per word, giving an overall linear time complexity of $O(n)$.

---

## Sample Run

```text
Please enter the number of word: 4
Please enter the words: apple banana orange pie
Please enter the character: e
----------------------------------
The number of words that end with the character 'e' is: 2
```

---

## How to Run

Compile using any standard C++ compiler:

```bash
g++ -std=c++17 main.cpp -o suffix_counter
./suffix_counter
```