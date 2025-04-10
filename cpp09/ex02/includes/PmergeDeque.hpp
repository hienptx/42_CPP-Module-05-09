#ifndef PMERGEDEQUE_HPP
#define PMERGEDEQUE_HPP

#include <PmergeMe.hpp>

class PmergeDeque : public PmergeMe
{
    public:
        PmergeDeque();
        PmergeDeque(const PmergeDeque &cpy);
        PmergeDeque &operator=(const PmergeDeque &cpy);
        ~PmergeDeque();

        void printFunction(std::string message) const override;
        void FordJohnsonSort() override;
        
        void mergeSort(std::deque<unsigned int> &bigVals, std::deque<unsigned int> &smallVals);
        void binaryInsert(std::deque<unsigned int> &list, unsigned int value);
        std::size_t size();
};

#endif