#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>
#include <iterator>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>

class PmergeMe
{
    protected:
        std::vector<unsigned int> _vector;
        std::deque<unsigned int> _deque;
        std::size_t _level;
        std::size_t _n;

    public:
    // Othordox Canonical Form
        PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);
        ~PmergeMe();
    // Getters
        std::deque<unsigned int> getDeque() const;
        std::vector<unsigned int> getVector() const;     
    // Member functions
        void parse_input(int ac, char **av);
        int F(std::size_t size);
        unsigned int Jacobsthal(unsigned int n);
    // Pure virtual functions, to be implemented in derived classes 
        virtual void FordJohnsonSort() = 0;
        virtual void PairAndSort(std::size_t level) = 0;
        virtual void establishMainAndPend(std::size_t level) = 0;
    // Template functions
        template<typename T>
        std::size_t getSize(T container);
        template<typename T>
        bool isSorted(T begin, T end);
        template<typename T>
        void printFunction(T container, std::string message);
};

#include "../srcs/PmergeMe.tpp"

#endif