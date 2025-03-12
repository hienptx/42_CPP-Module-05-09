#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <cstddef>

// "using" here is equivalent to "typedef <tag>"
// Tags are used to select the most efficient algorithm if your container is passed to one of 
// the Standard Library functions from the <algorithm> library. Wrong tags mean sub-optimal performance! 

/* C++ expects some properties/tags from an iterator:
iterator_category   — one of the six iterator categories we have seen above. 
                    The full list is available here. The std::forward_iterator_tag tag is what we need;
difference_type     — a signed integer type that can be used to identify distance between iterator steps. 
                    Our iterator is basically a wrapper around a pointer and leverages pointer arithmetic, 
                    so the default std::ptrdiff_t is a good choice;
value_type          — the type the iterator iterates over. T in our case;
pointer             — defines a pointer to the type iterated over. T* in our case;
reference           — defines a reference to the type iterated over. T& in our case;
*/

// All iterators must be constructible, copy-constructible, copy-assignable, destructible and swappable.
template <class T>
class MutantStack : public std::stack<T>
{
    public:
        struct iterator {
                using value_type = T;;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference = T&;
                using iterator_category = std::forward_iterator_tag;

                // Constructor
                iterator(pointer ptr);

                // Implement operators
                reference operator*() const;
                pointer operator->();

                // Prefix increment
                iterator& operator++();
                // Postfix increment
                iterator operator++(int);

                // Prefix decrement
                iterator& operator--();
                // Postfix decrement
                iterator operator--(int);
                
                // Compare operators    
                // These operators take only 1 param, because they are member function
                // For non-member function, they have to take 2 params 
                bool operator== (const iterator& other);
                bool operator!= (const iterator& other);
            private:
                pointer m_ptr;
        };
};

#endif