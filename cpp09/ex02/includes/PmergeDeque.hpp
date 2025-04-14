#ifndef PMERGEDEQUE_HPP
#define PMERGEDEQUE_HPP

#include "../includes/PmergeMe.hpp"

class PmergeDeque : public PmergeMe
{
    public:
        PmergeDeque();
        PmergeDeque(const PmergeDeque &cpy);
        PmergeDeque &operator=(const PmergeDeque &cpy);
        ~PmergeDeque();

        void printFunction(std::string message) const override;
        void FordJohnsonSort() override;
        
        void PairAndSort(std::size_t level) override;
        void establishMainAndPend(std::size_t level);
        unsigned int Jacobsthal(unsigned int n);
        // void mergeSort(std::deque<unsigned int> &bigVals, std::deque<unsigned int> &smallVals);
        void binaryInsert(  std::deque<unsigned int> &main,
                            std::deque<unsigned int> &pend,
                            std::deque<unsigned int> &rest);
        // std::size_t size();
};

#endif