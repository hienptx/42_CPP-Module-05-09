## CPP Module 08: Generic programing
Generic programming is when a single algorithm is written to work on many data types. 
As programmers, we only have to write the algorithm once: the compiler takes care of 
generating the code for each data type, reducing the need to write duplicate code.
Topics: Templated containers (vector) , iterators, algorithm

# ex00: Easy find
    - Return a pointer to the value to find in a vector of integers
# ex01: Span
    - Create span of integers
    - Add number to the array
    - Find shortest and longest span of the integer vector
# ex02: MutantStack
    - Create iterator functionality for std::stack

# C++ STL Containers: Vector vs. Deque vs. Stack vs. List

This guide provides a quick comparison of four common C++ Standard Template Library (STL) containers: `std::vector`, `std::deque`, `std::stack`, and `std::list`.

## Overview

| Container | Type                 | Memory Layout      | Random Access | Insert/Delete (Front) | Insert/Delete (Back) | Insert/Delete (Middle) |
|-----------|----------------------|--------------------|---------------|-----------------------|----------------------|------------------------|
| `vector`  | Dynamic array         | Contiguous        | ✅ O(1)       | ❌ O(N)               | ✅ O(1)              | ❌ O(N)                |
| `deque`   | Double-ended queue    | Segmented blocks  | ✅ O(1)       | ✅ O(1)               | ✅ O(1)              | ❌ O(N)                |
| `stack`   | LIFO container        | Uses deque        | ❌            | ❌                    | ✅ O(1)              | ❌                     |
| `list`    | Doubly linked list    | Non-contiguous    | ❌ O(N)       | ✅ O(1)               | ✅ O(1)              | ✅ O(1) (via iterator) |

## Choosing the Right Container

### Use `std::vector` when:
- You need fast random access (**O(1)**).
- You mainly insert/remove at the end (**O(1)**).
- You want cache-friendly, contiguous memory allocation.

### Use `std::deque` when:
- You need fast insertions/removals at both ends (**O(1)**).
- You require efficient random access (**O(1)**), but slightly slower than `vector`.

### Use `std::stack` when:
- You only need **Last In, First Out (LIFO)** behavior.
- You don’t need iteration or random access.
- You want a simple, restricted interface for stack operations.

### Use `std::list` when:
- You frequently insert or delete in the middle (**O(1)** with iterator).
- You don’t need fast random access (**O(N)**).
- You need stable iterators (no reallocation like `vector`).

## Example Usage

```cpp
#include <vector>
#include <deque>
#include <stack>
#include <list>
#include <iostream>

int main() {
    // Using std::vector
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4);  // Fast append

    // Using std::deque
    std::deque<int> deq = {1, 2, 3};
    deq.push_front(0); // Fast insert at front
    deq.push_back(4);  // Fast insert at back

    // Using std::stack
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.pop();  // Last In, First Out (LIFO)

    // Using std::list
    std::list<int> lst = {1, 2, 3};
    auto it = lst.begin();
    std::advance(it, 1);
    lst.insert(it, 10); // Fast insert in the middle

    return 0;
}

[Source](https://internalpointers.com/post/writing-custom-iterators-modern-cpp)