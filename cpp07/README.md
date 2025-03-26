## CPP MODULE 07

# ex00: template
	- implement template functions: swap(), min(), max()
# ex01: iter
	- implement a template function that can iterate any type of data array
# ex02: array
	- create a template class Array

## Types of Associative Containers in C++
The Standard Template Library (STL) provides four main types of associative containers:

Ordered Associative Containers (implemented as balanced binary search trees, usually Red-Black Trees)

std::set – Stores unique elements in a sorted order.
std::map – Stores key-value pairs with unique keys in a sorted order.
std::multiset – Like set, but allows duplicate elements.
std::multimap – Like map, but allows duplicate keys.
Unordered Associative Containers (implemented as hash tables)

std::unordered_set – Stores unique elements with no specific order, but provides fast lookup.
std::unordered_map – Stores key-value pairs with unique keys, using hashing for fast access.
std::unordered_multiset – Like unordered_set, but allows duplicate elements.
std::unordered_multimap – Like unordered_map, but allows duplicate keys.
Key Features
Fast Lookup: Ordered containers provide O(log n) complexity, while unordered ones offer O(1) average-time complexity for lookups.
Automatic Sorting (for ordered containers): Elements are maintained in sorted order.
Uniqueness Control: set and map ensure unique elements/keys, while multiset and multimap allow duplicates.
Key-based Access: Unlike sequence containers, associative containers use keys instead of indices.
