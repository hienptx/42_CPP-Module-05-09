#include "../includes/PmergeDeque.hpp"

PmergeDeque::PmergeDeque()
{}

PmergeDeque::PmergeDeque(const PmergeDeque &cpy)
: PmergeMe(cpy)
{
    *this = cpy;
}

PmergeDeque &PmergeDeque::operator=(const PmergeDeque &cpy)
{
    if (this != &cpy)
    {
        this->_list = cpy._list;
        this->_deque = cpy._deque;
    }
    return *this;
}   

PmergeDeque::~PmergeDeque()
{}

void PmergeDeque::printFunction(std::string message) const
{
    std::deque<unsigned int>::const_iterator it = _deque.begin();
    
    std::cout << message;
    while(it != _deque.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void PmergeDeque::FordJohnsonSort()
{
    PairAndSort(0);
    establishMainAndPend(_level);
}

unsigned int PmergeDeque::Jacobsthal(unsigned int n)
{
    return (std::pow(2, n) - std::pow(-1, n)) / 3;
}


void PmergeDeque::binaryInsert(
    std::deque<unsigned int> &main, std::deque<unsigned int> &pend,
    std::deque<unsigned int> &rest, std::size_t level)
{
    std::size_t range = std::pow(2, level);
    std::cout << "n = " << _n << std::endl;
    std::size_t counter = Jacobsthal(_n) - Jacobsthal(_n - 1);
    while (counter > 0 && pend.size() > 0)
    {
        std::deque<unsigned>::iterator it_pend = pend.begin();
        std::deque<unsigned>::iterator it_main = main.begin();
        std::deque<unsigned>::iterator big_pend = it_pend + (counter * range) - 1;
        std::deque<unsigned>::iterator big_main = it_main + (counter * range) - 1;
        std::cout << "Compare value from pend = " << *big_pend << std::endl;
        std::cout << "Compare value from main = " << *big_main << std::endl;
        counter--;
    }
    std::cout << "Main:     ";
    for (std::deque<unsigned int>::iterator it1 = main.begin(); it1 != main.end(); it1++)
        std::cout << *it1 << " ";
    std::cout << std::endl;
    std::cout << "Pend:     ";
    for (std::deque<unsigned int>::iterator it2 = pend.begin(); it2 != pend.end(); it2++)
        std::cout << *it2 << " ";
    std::cout << std::endl;
    std::cout << "Rest      ";
    for (std::deque<unsigned int>::iterator it3 = rest.begin(); it3 != rest.end(); it3++)
        std::cout << *it3 << " ";
    std::cout << std::endl;
    _n += 1;
} 


// main contains a1, b1 and rest of a(s)
void PmergeDeque::establishMainAndPend(std::size_t level)
{
    std::deque<unsigned int> main;
    std::deque<unsigned int> pend;
    std::deque<unsigned int> rest;
    auto it = _deque.begin();
    std::size_t nbr_of_element = (_deque.size() / level);
    std::size_t i = 1;
    
    --level;
    std::size_t range = std::pow(2, level);
    while ( i < nbr_of_element && i *  range < _deque.size())
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
    std::copy(it, _deque.end(), std::back_inserter(rest));
    std::cout << "Level: " << level << std::endl;
    std::cout << "Main length: " << main.size() << std::endl;
    std::cout << "Pend length: " << pend.size() << std::endl;
    std::cout << "Rest length: " << rest.size() << std::endl;
    binaryInsert(main, pend, rest, level);
    // _deque = main;
    std::cout << std::endl;
    // if(level >= 1)
    //     establishMainAndPend(level);
}

void PmergeDeque::PairAndSort(std::size_t level)
{
    std::size_t i = 0;
    std::size_t size = _deque.size();
    std::size_t range = std::pow(2, level);
    std::deque<unsigned int>::iterator it = _deque.begin(); 
    std::deque<unsigned int>::iterator tmp = it; 

    // std::cout << "Level: " << level << std::endl;
    if (level == 0)    
    {
        while ((i < size - 1))
        {
            if (_deque[i] > _deque[i + 1])
            std::swap(_deque[i], _deque[i + 1]);
            i += 2;
        }
    }
    else
    {
        i = range - 1;
        while (i + range < size)
        {
            // if(level == 2)
            // {
            //     std::cout << "First pair: " << _deque[i] << std::endl;
            //     std::cout << "Second pair: " << _deque[i + range] << std::endl;   
            // }
            if (_deque[i] > _deque[i + range])
                std::swap_ranges(tmp, tmp + range, tmp + range);
            i = i + range * 2;
            tmp = tmp + range * 2;
        }
    }
    // printFunction("");
    if (std::pow(2, level + 1) < size / 2)
    {
        level += 1;
        _level = level;
        PairAndSort(level);
    }
}



// 6 15 8 16 2 11 0 17  9 18 14 19 3 10 1 21  5 12 4 20 7 13 