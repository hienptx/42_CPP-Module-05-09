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
    std::cout << "| size = " << _deque.size() << std::endl;
}

bool isSorted(std::deque<unsigned int>::iterator begin, std::deque<unsigned int>::iterator end)
{
    for (auto it = begin; it != end - 1; ++it)
    {
        if (*it > *(it + 1))
            return false;
    }
    return true;
}

std::size_t PmergeDeque::getCounter() const
{
    return _counter;
}

void PmergeDeque::FordJohnsonSort()
{
    if(isSorted(_deque.begin(), _deque.end()) == true)
        return;
    if (_deque.size() <= 3)
    {
        std::sort(_deque.begin(), _deque.end());
        return;
    }
    PairAndSort(0);
    establishMainAndPend(_level);
    if (!isSorted(_deque.begin(), _deque.end()))
    {
        std::cout << "Deque is not sorted after binary insert." << std::endl;
        return;
    }
}

unsigned int PmergeDeque::Jacobsthal(unsigned int n)
{
    return (std::pow(2, n) - std::pow(-1, n)) / 3;
}

void printDeque(std::deque<unsigned int> &deque, std::string message)
{
    std::cout << message;
    for (std::deque<unsigned int>::iterator it = deque.begin(); it != deque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

// std::deque<unsigned int>::iterator PmergeDeque::getInsertPos(
//     std::deque<unsigned int> &main, std::size_t range, std::size_t num_blocks, unsigned int value)
// {
//     std::deque<unsigned int>::iterator pos;
//     std::deque<unsigned int>::iterator it;
//     std::deque<unsigned int> compareList;
//     for (std::size_t i = 1; i <= num_blocks; i++)
//     {
//         if ((i * range) - 1 < main.size())
//             compareList.push_back(main[(i * range) - 1]);
//     }
//     it = std::lower_bound(compareList.begin(), compareList.end(), value);
//     unsigned int offset = std::distance(compareList.begin(), it) * range;
//     if (offset <= main.size())
//         pos = main.begin() + offset;
//     else
//         pos = main.end();
//     return pos;
// }

std::deque<unsigned int>::iterator PmergeDeque::getInsertPos(
    std::deque<unsigned int> &main, std::size_t range, std::size_t num_blocks, unsigned int value)
{
    std::deque<unsigned int>::iterator pos;
    std::deque<unsigned int>::iterator it;
    std::deque<unsigned int> compareList;

    for (std::size_t i = 1; i <= num_blocks; i++)
    {
        if ((i * range) - 1 < main.size())
            compareList.push_back(main[(i * range) - 1]);
    }
    it = compareList.begin();
    std::size_t left = 0;
    std::size_t right = compareList.size();
    while (left < right)
    {
        _counter++;
        std::size_t mid = left + (right - left) / 2;
        if (compareList[mid] < value)
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

void PmergeDeque::binaryInsert(
    std::deque<unsigned int> &main, std::deque<unsigned int> &pend,
    std::size_t level)
{
    std::deque<unsigned int>::iterator mid;
    std::size_t range = std::pow(2, level);
    std::deque<unsigned int>::iterator pos;
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
            // printDeque(main, "Main after insert:     ");
            // printDeque(pend, "Pend after insert:     ");
            // printDeque(rest, "Rest after insert:     ");
            counter--;
        }    
        _n += 1;
    }
} 

void PmergeDeque::sort_chunks_in_main(std::deque<unsigned int>& seq, std::size_t range) 
{
    if (range == 0 || seq.empty()) return;
    std::deque<std::deque<unsigned int>> chunks;

    for (size_t i = seq.size(); i > 0; i -= range) 
    {
        size_t chunk_start = (i >= range) ? i - range : 0;
        std::deque<unsigned int> chunk(seq.begin() + chunk_start, seq.begin() + i);
        chunks.push_front(chunk);
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

// main contains a1, b1 and rest of a(s)
void PmergeDeque::establishMainAndPend(std::size_t level)
{
    std::deque<unsigned int> main;
    std::deque<unsigned int> pend;
    std::deque<unsigned int> rest;
    auto it = _deque.begin();
    std::size_t i = 1;
    
    if (level == 0)
        return;
    std::size_t nbr_of_element = (_deque.size() / level);
    --level;
    std::size_t range = std::pow(2, level);
    while ( i <= nbr_of_element && i *  range <= _deque.size())
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
    if (it != _deque.end())
        std::copy(it, _deque.end(), std::back_inserter(rest));
    // printDeque(_deque, "Deque before:     ");
    // printDeque(main, "Main before:     ");
    // printDeque(pend, "Pend before:     ");
    // printDeque(rest, "Rest before:     ");

    sort_chunks_in_main(main, range);
    binaryInsert(main, pend, level);
    std::copy(rest.begin(), rest.end(), std::back_inserter(main));
    _deque.clear();
    _deque = main;
    pend.clear();
    rest.clear();
    main.clear();
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
            {
                _counter++;
                std::swap(_deque[i], _deque[i + 1]);
            }
            i += 2;
        }
    }
    else
    {
        i = range - 1;
        while (i + range < size)
        {
            if (_deque[i] > _deque[i + range])
            {
                _counter++;
                std::swap_ranges(tmp, tmp + range, tmp + range);
            }
            i = i + range * 2;
            tmp = tmp + range * 2;
        }
    }
    if (std::pow(2, level + 1) <= size / 2)
    {
        level += 1;
        _level = level;
        PairAndSort(level);
    }
}


// void PmergeDeque::binaryInsert(
//     std::deque<unsigned int> &main, std::deque<unsigned int> &pend,
//     std::deque<unsigned int> &rest, std::size_t level)
// {
//     std::deque<unsigned int>::iterator mid;
//     std::size_t range = std::pow(2, level);
//     std::deque<unsigned int>::iterator pos;
//     std::size_t bound_index;
//     (void)rest;
//     _n = 3;
//     while (pend.size() != 0)
//     {
//         bound_index = std::pow(2, (_n - 1)) - 1;
//         std::size_t counter = Jacobsthal(_n) - Jacobsthal(_n - 1);
//         while (counter > 0 && pend.size() != 0)
//         {
//             std::size_t remain_elements = pend.size() / range;
//             if (remain_elements < counter)
//                 counter = remain_elements;
//             std::cout << "jacob = " << Jacobsthal(_n);
//             std::cout << "  |   range = " << range;
//             std::cout << "  |   counter = " << counter;
//             std::cout << "  |   bound index = " << bound_index << std::endl;
//             std::size_t block_end_index = counter * range - 1;
//             if (block_end_index >= pend.size())
//                 break;
//             auto block_start = pend.begin() + (counter - 1) * range;
//             auto block_end = block_start + range - 1;
//             std::cout << "pending block = " << *block_start;
//             std::cout << " " << *block_end << std::endl;
//             // Calculate middle insertion point in `main`
//             std::size_t num_blocks = main.size() / range;
//             std::size_t mid_index = (num_blocks % 2 == 0)
//                 ? range * (num_blocks / 2) - 1
//                 : range * ((num_blocks / 2) + 1) - 1;
//             if (mid_index >= main.size())
//                 break;
//             auto mid = main.begin() + mid_index;
//             if (range == 1)
//                 pos = std::lower_bound(main.begin(), main.end(), *block_end);
//             else
//             {
//                 if (*block_end > *mid)
//                 {
//                     while (*block_end > *mid)
//                     {
//                         if (mid + range >= main.end())
//                             break;
//                         mid += range;
//                     }
//                     if (*block_end > *mid)
//                     {
//                         pos = (mid == main.end() - 1) ? main.end() : mid + 1;
//                     }
//                     else
//                     {
//                         pos = mid - range + 1;
//                     }
//                 }
//                 else
//                 {
//                     while (*block_end < *mid)
//                     {
//                         if (std::distance(main.begin(), mid) <= static_cast<long>(range))
//                             break;
//                         mid -= range;
//                     }
//                     if (*block_end < *mid && mid == main.begin())
//                         pos = main.begin();
//                     else if (*block_end < *mid && mid != main.begin())
//                         pos = (*block_end < *main.begin()) ? main.begin() : mid - range + 1;
//                     else
//                         pos = mid + 1;
//                 }
//             }
//             main.insert(pos, block_start, block_end + 1);
//             pend.erase(block_start, block_end + 1);
//             printDeque(pend, "Pend after insert:     ");
//             printDeque(main, "Main after insert:     ");
//             counter--;
//         }    
//         _n += 1;
//     }
//     std::cout << std::endl;
// } 

// 6 15 8 16 2 11 0 17  9 18 14 19 3 10 1 21  5 12 4 20 7 13 