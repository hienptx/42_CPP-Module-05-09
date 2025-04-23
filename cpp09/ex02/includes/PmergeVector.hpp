#ifndef PMERGEVECTOR_HPP
#define PMERGEVECTOR_HPP

#include "../includes/PmergeMe.hpp"

class PmergeVector : public PmergeMe
{
    private:
        std::size_t _counter = 0;
    
    public:
    // Orthodox Canonical Form
        PmergeVector();
        PmergeVector(const PmergeVector &cpy);
        PmergeVector &operator=(const PmergeVector &cpy);
        ~PmergeVector();
    // Getters
        std::size_t getCounter()const;
    // Override of pure functions
        void FordJohnsonSort() override;
        void PairAndSort(std::size_t level) override;
        void establishMainAndPend(std::size_t level) override;

        void binaryInsert(  std::vector<unsigned int> &main,
                            std::vector<unsigned int> &pend,
                            std::size_t level);
        void check_main(std::vector<unsigned int> &seq,
                            std::size_t range);
        std::vector<unsigned int>::iterator getInsertPos(std::vector<unsigned int> &main,
                            std::size_t range, std::size_t num_blocks,
                            unsigned int value);  
        
    };

#endif

