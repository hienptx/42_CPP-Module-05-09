#ifndef PMERGEDEQUE_HPP
#define PMERGEDEQUE_HPP

#include "../includes/PmergeMe.hpp"

class PmergeDeque : public PmergeMe
{
    private:
        std::size_t _counter = 0;
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
        // void JacobsIndices(std::size_t n);
        // void mergeSort(std::deque<unsigned int> &bigVals, std::deque<unsigned int> &smallVals);
        void binaryInsert(  std::deque<unsigned int> &main,
                            std::deque<unsigned int> &pend,
                            std::size_t level);
        void sort_chunks_in_main(std::deque<unsigned int> &seq, std::size_t range);
        std::deque<unsigned int>::iterator getInsertPos(
            std::deque<unsigned int> &main, std::size_t range, std::size_t num_blocks, unsigned int value);
        std::size_t getCounter() const;
};

#endif