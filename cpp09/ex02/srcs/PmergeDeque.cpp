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
        PmergeMe::operator=(cpy); // Use base class assignment operator
        _counter = cpy._counter;
    }
    return *this;
}

PmergeDeque::~PmergeDeque()
{}

std::size_t PmergeDeque::getCounter() const
{
    return _counter;
}

void PmergeDeque::FordJohnsonSort()
{
    PairAndSort(0);
    establishMainAndPend(_level);
    if (!isSorted(_deque.begin(), _deque.end()))
    {
        std::cout << "Deque is not sorted after binary insert." << std::endl;
        return;
    }
}

/*
    This function determines the correct insertion position in main deque for a block 
    (ending in value), using binary search among specific "boundary" defined by 
    2^(k+1)-1 elements taken from the main deque. And insert the block in binary search.
*/

std::deque<unsigned int>::iterator PmergeDeque::getInsertPos(
    std::deque<unsigned int> &main, std::size_t range, std::size_t num_blocks, unsigned int value)
{
    std::deque<unsigned int>::iterator pos;
    std::deque<unsigned int>::iterator it;
    std::deque<unsigned int> compareDeque;

    for (std::size_t i = 1; i <= num_blocks; i++)
    {
        if ((i * range) - 1 < main.size())
            compareDeque.push_back(main[(i * range) - 1]);
    }
    it = compareDeque.begin();
    std::size_t left = 0;
    std::size_t right = compareDeque.size();
    while (left < right)
    {
        _counter++;
        std::size_t mid = left + (right - left) / 2;
        if (compareDeque[mid] < value)
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

/*
    This function inserts sorted blocks from a pend deque into the main deque using
    binary search logic based on the Ford-Johnson merge-insertion algorithm 
    (optimized via the Jacobsthal sequence). Key Concepts:
    - range: size of each block (based on recursion level)
    - Jacobsthal(_n): determines how many blocks to insert in each round
    - getInsertPos(...): finds the correct position in main to insert a block based on
    binary search among selected comparison elements
*/
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
            auto block_start = pend.begin() + (counter - 1) * range;
            auto block_end = block_start + range - 1;
            pos = getInsertPos(main, range, num_blocks, *block_end);
            main.insert(pos, block_start, block_end + 1);
            pend.erase(block_start, block_end + 1);
            counter--;
        }    
        _n += 1;
    }
} 

void PmergeDeque::check_main(std::deque<unsigned int>& seq, std::size_t range) 
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

/*
    This function takes a level as an argument and establishes the main and
    pending deques. It does this by iterating through the original deque and
    copying elements into the main and pending deques based on the level. The
    function also sorts the chunks in the main deque and performs a binary
    insert of the pending deque into the main deque. Finally, it clears the
    original deque and copies the sorted elements back into it.
*/
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
    check_main(main, range);
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

/*
    In this function, we are pairing the elements of the deque and sorting them
    in place. The function is called recursively until the level is greater than
    half the size of the deque. The level is incremented by 1 in each recursive
    call. The function uses a range variable to determine the size of the pairs
    to be sorted. The function uses a while loop to iterate through the deque
    and swap the elements if they are out of order.
*/
void PmergeDeque::PairAndSort(std::size_t level)
{
    std::size_t i = 0;
    std::size_t size = _deque.size();
    std::size_t range = std::pow(2, level);
    std::deque<unsigned int>::iterator it = _deque.begin(); 
    std::deque<unsigned int>::iterator tmp = it; 
    
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
    level += 1;
    _level = level;
    if (std::pow(2, level) <= size / 2)
        PairAndSort(level);
}
