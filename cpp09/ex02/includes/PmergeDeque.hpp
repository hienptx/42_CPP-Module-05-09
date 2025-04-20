#ifndef PMERGEDEQUE_HPP
#define PMERGEDEQUE_HPP

#include "../includes/PmergeMe.hpp"

class PmergeDeque : public PmergeMe
{
    private:
        std::size_t _counter = 0;

    public:
    // Orthodox Canonical Form
        PmergeDeque();
        PmergeDeque(const PmergeDeque &cpy);
        PmergeDeque &operator=(const PmergeDeque &cpy);
        ~PmergeDeque();
    // Getters
        std::size_t getCounter()const;
    // Override of pure functions 
        void FordJohnsonSort() override;
        void PairAndSort(std::size_t level) override;
        void establishMainAndPend(std::size_t level) override;

        void binaryInsert(  std::deque<unsigned int> &main,
                            std::deque<unsigned int> &pend,
                            std::size_t level);
        void sort_chunks_in_main(std::deque<unsigned int> &seq,
                            std::size_t range);
        std::deque<unsigned int>::iterator getInsertPos(std::deque<unsigned int> &main,
                            std::size_t range, std::size_t num_blocks,
                            unsigned int value);
        
};

#endif