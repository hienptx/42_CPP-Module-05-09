## CPP Module 09:

# ex00: Bitcoin Exchange
    - from provided dataset "bitcoin exchange rate", the program supposes to take "input.txt" as input, then output the value of a certain amount of bitcoin on certain date. 
    - Using std::list<>
# ex01: Reverse Polish Notation
    - Using std::stack<>
# ex02: PmergeMe
    - Ford-Johnson Algorithm
    - Using std::vector<> and deque<>

## Overview about containers

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
