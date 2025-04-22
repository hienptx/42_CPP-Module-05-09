/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:35:36 by hipham            #+#    #+#             */
/*   Updated: 2025/04/22 13:01:38 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy) : _vector(cpy._vector), _deque(cpy._deque)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    if (this != &cpy)
    {
        this->_vector = cpy._vector;
        this->_deque = cpy._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

std::deque<unsigned int> PmergeMe::getDeque() const
{
    return _deque;
}

std::vector<unsigned int> PmergeMe::getVector() const
{
    return _vector;
}

void PmergeMe::parse_input(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg(av[i]);
        if (arg.empty())
            throw std::invalid_argument("Error: Empty argument.");
        if (arg.find_first_not_of("0123456789") != std::string::npos)
            throw std::invalid_argument("Error: Invalid value in argument.");
        unsigned int num = std::stoul(arg);
        if (num > 2147483647)
            throw std::out_of_range("Error: Number out of range.");
        _vector.push_back(num);
        _deque.push_back(num);
    }
}
/*
    F(n)\=k\=1∑n​⌈log2​(43​⋅k)⌉
*/
int PmergeMe::F(std::size_t size)
{
    int sum = 0;
    for (std::size_t k = 1; k <= size; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

unsigned int PmergeMe::Jacobsthal(unsigned int n)
{
    return (std::pow(2, n) - std::pow(-1, n)) / 3;
}

