/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:35:36 by hipham            #+#    #+#             */
/*   Updated: 2025/04/15 16:52:50 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    _n = 3;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    *this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    if (this != &cpy)
    {
        this->_list = cpy._list;
        this->_deque = cpy._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
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
        _list.push_back(num);
        _deque.push_back(num);
    }
}
