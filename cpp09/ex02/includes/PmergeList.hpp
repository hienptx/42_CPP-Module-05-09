#ifndef PMERGELIST_HPP
#define PMERGELIST_HPP

#include "../includes/PmergeMe.hpp"

class PmergeList : public PmergeMe
{
    public:
        PmergeList();
        PmergeList(const PmergeList &cpy);
        PmergeList &operator=(const PmergeList &cpy);
        ~PmergeList();

        // Inherited functions
        void printFunction(std::string message) const override;
        void FordJohnsonSort() override;

        // Class specific functions
        void mergeSort(std::list<unsigned int> &bigVals, std::list<unsigned int> &smallVals);
        void binaryInsert(std::list<unsigned int> &list, unsigned int value);
        std::size_t size();
    };

#endif

