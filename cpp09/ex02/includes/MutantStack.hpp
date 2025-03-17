#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <cstddef>
#include <iostream>
#include <algorithm>

// "using" is equivalent to "typedef <tag>"
// Tags are used to select the most efficient algorithm if your container is passed to one of 
// the Standard Library functions from the <algorithm> library. Wrong tags mean sub-optimal performance! 

/* C++ expects some properties/tags from an iterator:
iterator_category   — one of the six iterator categories we have seen above. 
                    The std::forward_iterator_tag tag is what we need;
difference_type     — a signed integer type that can be used to identify distance between iterator steps. 
                    Our iterator is basically a wrapper around a pointer and leverages pointer arithmetic, 
                    so the default std::ptrdiff_t is a good choice;
value_type          — the type the iterator iterates over. T in our case;
pointer             — defines a pointer to the type iterated over. T* in our case;
reference           — defines a reference to the type iterated over. T& in our case;
*/

// All iterators must be constructible, copy-constructible, copy-assignable, destructible and swappable.
// Fully customized iterator approach
// template <class T>
// class MutantStack : public std::stack<T>
// {
//     public:
//         struct iterator {
//                 using value_type = T;;
//                 using difference_type = std::ptrdiff_t;
//                 using pointer = T*;
//                 using reference = T&;
//                 using iterator_category = std::forward_iterator_tag;

//                 // Constructor
//                 // iterator(){};
//                 iterator() : m_ptr(){};
//                 iterator(pointer ptr) : m_ptr(ptr){};
//                 iterator(const iterator& cpy) : m_ptr(cpy.m_ptr) {};
//                 iterator& operator=(const iterator& cpy) {m_ptr = cpy.m_ptr; return *this;} 

//                 // Implement operators
//                 reference operator*() const {return *m_ptr;}
//                 pointer operator->() {return m_ptr;}

//                 // Prefix increment
//                 iterator& operator++() {++m_ptr; return *this;}
//                 // Postfix increment
//                 iterator operator++(int) {iterator tmp = *this; ++m_ptr; return tmp;}

//                 // Prefix decrement
//                 iterator& operator--() {--m_ptr; return *this;}
//                 // Postfix decrement
//                 iterator operator--(int) {iterator tmp = *this; --m_ptr; return tmp;}
                
//                 // Compare operators    
//                 // These operators take only 1 param, because they are member function
//                 // For non-member function, they have to take 2 params 
//                 bool operator== (const iterator& other) {return(m_ptr == other.m_ptr);}
//                 bool operator!= (const iterator& other) { return(m_ptr != other.m_ptr);}
//             private:
//                 pointer m_ptr;
//         };
//         iterator begin() {return iterator(&this->c[0]);}
//         // The end iterator points past the end of the target sequence
//         iterator end() {return iterator(&this->c[0] + this->c.size());} 
// };

// Using std::deque<> approach
template <class T>
class MutantStack: public std::stack<T>
{
    public:
        using std::stack<T>::c;
        using iterator = typename std::deque<T>::iterator;
        using const_iterator = typename std::deque<T>::const_iterator;
        // iterator begin() {return iterator(this->c.begin());}
        // iterator end() {return iterator(this->c.end());}
        iterator begin();
        iterator end();
};

// For template function, the implementation file has to be included here
#include "../srcs/MutantStack.tpp"

#endif