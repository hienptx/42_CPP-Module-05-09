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

void PmergeDeque::setJacobsIndices(std::size_t n)
{
    jacobIndices.clear();
    for (std::size_t i = 0; i < n; ++i)
    {
        if (i == 0 || i == 1)
            jacobIndices.push_back(i);
        else
        {
            std::size_t j = Jacobsthal(i);
            if (j > 0 && j < _deque.size())
                jacobIndices.push_back(j);
        }
    }
}

void PmergeDeque::binaryInsert(
    std::deque<unsigned int> &main, std::deque<unsigned int> &pend,
    std::deque<unsigned int> &rest, std::size_t level)
{
    std::deque<unsigned int> bigValsMain;
    std::deque<unsigned int>::iterator mid;
    std::size_t range = std::pow(2, level);
    std::cout << "n = " << _n << std::endl;
    std::size_t jnbr = Jacobsthal(_n);
    std::size_t counter = jnbr - Jacobsthal(_n - 1);

    // while (counter > 0 && !pend.empty())
    // {
    //     std::size_t block_end_index = counter * range - 1;
    //     if (block_end_index >= pend.size())
    //         break;
    //     auto block_start = pend.begin() + (counter - 1) * range;
    //     auto block_end = block_start + range;
    //     auto big_pend = block_end - 1;
    //     // Calculate middle insertion point in `main`
    //     std::size_t num_blocks = main.size() / range;
    //     std::size_t mid_index = (num_blocks % 2 == 0)
    //         ? range * (num_blocks / 2) - 1
    //         : range * ((num_blocks / 2) + 1) - 1;
    //     if (mid_index >= main.size())
    //         break;
    //     auto mid = main.begin() + mid_index;
    //     // Move forward to find correct insert position
    //     while (*big_pend > *mid && std::distance(mid, main.end()) > static_cast<long>(range))
    //         mid += range;
    //     // Insert block before the found mid position
    //     if (std::distance(main.begin(), mid) >= static_cast<long>(range))
    //         main.insert(mid - (range - 1), block_start, block_end);
    //     counter--;
    // }
    for (std::size_t i = 0; i < jacobIndices.size(); ++i)
    {
        std::size_t idx = jacobIndices[i];
        std::size_t start_idx = idx * range;
        if (start_idx + range > pend.size()) continue;
        auto block_start = pend.begin() + start_idx;
        auto block_end = block_start + range;
        auto big_pend = block_end - 1;

        std::size_t num_blocks = main.size() / range;
        std::size_t mid_index = (num_blocks % 2 == 0)
            ? range * (num_blocks / 2) - 1
            : range * ((num_blocks / 2) + 1) - 1;
        if (mid_index >= main.size())
            break;
        auto mid = main.begin() + mid_index;

        while (*big_pend > *mid && std::distance(mid, main.end()) > static_cast<long>(range))
            mid += range;

        if (std::distance(main.begin(), mid) >= static_cast<long>(range))
            main.insert(mid - (range - 1), block_start, block_end);
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
    std::copy(rest.begin(), rest.end(), std::back_inserter(main));
    _deque.clear();
    _deque = main;
    pend.clear();
    rest.clear();
    main.clear();
    std::cout << "Deque:     ";
    for (std::deque<unsigned int>::iterator it1 = _deque.begin(); it1 != _deque.end(); it1++)
        std::cout << *it1 << " ";
    std::cout << std::endl;
    if(level >= 1)
        establishMainAndPend(level);
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