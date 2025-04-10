#ifndef PMERGEME_H
#define PMERGEME_H

#include <list>
#include <deque>
#include <iterator>
#include <cstddef>
#include <iostream>
#include <algorithm>

class PmergeMe
{
    protected:
        std::list<unsigned int> _list;
        std::deque<unsigned int> _deque;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);
        ~PmergeMe();

        void parse_input(int ac, char **av);
        virtual void printFunction(std::string message) const = 0;
        virtual void FordJohnsonSort() = 0;
        // virtual void mergeSort(std::list<unsigned int> &bigVals, std::list<unsigned int> &smallVals) = 0;
        // virtual void insertSort(std::list<unsigned int> &list, unsigned int value) = 0;
        // virtual void binaryInsert(std::list<unsigned int> &list, unsigned int value) = 0;
};  

#endif