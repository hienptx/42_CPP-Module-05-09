#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>
#include <iterator>
#include <cstddef>

// using hear is equivalent to typedef

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        struct iterator {
                typedef T   value_type = T;;
                typedef Distance difference_type = std::ptrdiff_t;
                // using difference_type = std::prtdiff_t;
                typedef Pointer pointer = T*;
                typedef Reference reference = &T;
                typedef Category iterator_category = std::forward_iterator_tag;

                iterator(pointer ptr);
            private:
                pointer m_ptr;
        };
};

#endif