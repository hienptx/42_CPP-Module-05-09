/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:15:17 by hipham            #+#    #+#             */
/*   Updated: 2025/04/22 14:37:43 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeVector.hpp"

PmergeVector::PmergeVector()
{
}

PmergeVector::PmergeVector(const PmergeVector &cpy)
: PmergeMe(cpy)
{
    *this = cpy;
}

PmergeVector &PmergeVector::operator=(const PmergeVector &cpy)
{
    if (this != &cpy)
    {
        this->_vector = cpy._vector;
        this->_vector = cpy._vector;
    }
    return *this;
}

PmergeVector::~PmergeVector()
{
}

// Getters
std::size_t PmergeVector::getCounter() const
{
    return _counter;
}

// Override of pure functions
void PmergeVector::FordJohnsonSort()
{
    PairAndSort(0);
    establishMainAndPend(_level);
    if (!isSorted(_vector.begin(), _vector.end()))
    {
        std::cout << "Sequence is not sorted after binary insert." << std::endl;
        return;
    }
}

void PmergeVector::PairAndSort(std::size_t level)
{
    std::size_t i = 0;
    std::size_t size = _vector.size();
    std::size_t range = std::pow(2, level);
    std::vector<unsigned int>::iterator it = _vector.begin(); 
    std::vector<unsigned int>::iterator tmp = it; 
    
    // std::cout << "Level: " << level << std::endl;
    if (level == 0)    
    {
        while ((i < size - 1))
        {
            if (_vector[i] > _vector[i + 1])
            {
                _counter++;
                std::swap(_vector[i], _vector[i + 1]);
            }
            i += 2;
        }
    }
    else
    {
        i = range - 1;
        while (i + range < size)
        {
            if (_vector[i] > _vector[i + range])
            {
                _counter++;
                std::swap_ranges(tmp, tmp + range, tmp + range);
            }
            i = i + range * 2;
            tmp = tmp + range * 2;
        }
    }
    level += 1;
    _level = level;
    if (std::pow(2, level + 1) <= size / 2)
        PairAndSort(level);
}


void PmergeVector::establishMainAndPend(std::size_t level)
{
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    std::vector<unsigned int> rest;
    auto it = _vector.begin();
    std::size_t i = 1;
    
    if (level == 0)
        return;
    std::size_t nbr_of_element = (_vector.size() / level);
    --level;
    std::size_t range = std::pow(2, level);
    while ( i <= nbr_of_element && i *  range <= _vector.size())
    {
        if (i == 1 || i == 2)
        {
            std::copy(it, std::next(it, range), std::back_inserter(main));
            std::advance(it, range);
        }
        else
        {
            if (i % 2 == 0)
                std::copy(it, std::next(it, range), std::back_inserter(main));
            else
                std::copy(it, std::next(it, range), std::back_inserter(pend));
            std::advance(it, range);
        }
        i++;
    }
    if (it != _vector.end())
        std::copy(it, _vector.end(), std::back_inserter(rest));
    check_main(main, range);
    binaryInsert(main, pend, level);
    std::copy(rest.begin(), rest.end(), std::back_inserter(main));
    _vector.clear();
    _vector = main;
    pend.clear();
    rest.clear();
    main.clear();
    if(level >= 1)
        establishMainAndPend(level);
}

void PmergeVector::binaryInsert(  std::vector<unsigned int> &main,
                    std::vector<unsigned int> &pend,
                    std::size_t level)
{

    std::size_t range = std::pow(2, level);
    std::vector<unsigned int>::iterator pos;
    std::size_t num_blocks;
    
    _n = 3;
    while (pend.size() != 0)
    {
        num_blocks = std::pow(2, (_n - 1)) - 1;
        std::size_t counter = Jacobsthal(_n) - Jacobsthal(_n - 1);
        while (counter > 0 && pend.size() != 0)
        {
            std::size_t remain_elements = pend.size() / range;
            if (remain_elements < counter)
                counter = remain_elements;
            // std::cout << "jacob = " << Jacobsthal(_n);
            // std::cout << "  |   range = " << range;
            // std::cout << "  |   counter = " << counter;
            // std::cout << "  |   bound index = " << num_blocks << std::endl;

            auto block_start = pend.begin() + (counter - 1) * range;
            auto block_end = block_start + range - 1;
            // std::cout << "pending block = " << *block_start;
            // std::cout << " " << *block_end << std::endl;
    
            pos = getInsertPos(main, range, num_blocks, *block_end);
            main.insert(pos, block_start, block_end + 1);
            pend.erase(block_start, block_end + 1);
            // printvector(main, "Main after insert:     ");
            // printvector(pend, "Pend after insert:     ");
            // printvector(rest, "Rest after insert:     ");
            counter--;
        }    
        _n += 1;
    }
}

void PmergeVector::check_main(std::vector<unsigned int>& seq,
    std::size_t range)
{
    if (range == 0 || seq.empty()) return;

    std::vector<std::vector<unsigned int>> chunks;

    for (size_t i = seq.size(); i > 0; i -= range) 
    {
        size_t chunk_start = (i >= range) ? i - range : 0;
        std::vector<unsigned int> chunk(seq.begin() + chunk_start, seq.begin() + i);
        chunks.insert(chunks.begin(), chunk); // replaces push_front
    }
    for (size_t i = 0; i < chunks.size(); ++i) 
    {
        for (size_t j = 0; j < chunks.size() - 1 - i; ++j) 
        {
            if (chunks[j].back() > chunks[j + 1].back())
            {
            std::swap(chunks[j], chunks[j + 1]);
            _counter++;
            } 
        }
    }
    seq.clear();
    for (const auto& chunk : chunks)
        seq.insert(seq.end(), chunk.begin(), chunk.end());
}

    
std::vector<unsigned int>::iterator PmergeVector::getInsertPos(std::vector<unsigned int> &main,
                        std::size_t range, std::size_t num_blocks,
                        unsigned int value)
{
    std::vector<unsigned int>::iterator pos;
    std::vector<unsigned int>::iterator it;
    std::vector<unsigned int> comparevector;

    for (std::size_t i = 1; i <= num_blocks; i++)
    {
        if ((i * range) - 1 < main.size())
            comparevector.push_back(main[(i * range) - 1]);
    }
    it = comparevector.begin();
    std::size_t left = 0;
    std::size_t right = comparevector.size();
    while (left < right)
    {
        _counter++;
        std::size_t mid = left + (right - left) / 2;
        if (comparevector[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    unsigned int offset = left * range;
    if (offset <= main.size())
        pos = main.begin() + offset;
    else
        pos = main.end();
    return pos;
}