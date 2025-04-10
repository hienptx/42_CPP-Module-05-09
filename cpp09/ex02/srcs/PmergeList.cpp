#include "../includes/PmergeList.hpp"

PmergeList::PmergeList()
{
}

PmergeList::PmergeList(const PmergeList &cpy)
: PmergeMe(cpy)
{
    *this = cpy;
}

PmergeList &PmergeList::operator=(const PmergeList &cpy)
{
    if (this != &cpy)
    {
        this->_list = cpy._list;
        this->_deque = cpy._deque;
    }
    return *this;
}

PmergeList::~PmergeList()
{
}

void PmergeList::printFunction(std::string message) const
{
    std::list<unsigned int>::const_iterator it = _list.begin();
    
    std::cout << message;
    while(it != _list.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void PmergeList::mergeSort(std::list<unsigned int> &bigVals, std::list<unsigned int> &smallVals)    
{
    std::list <unsigned int>::iterator it = _list.begin();
    
    while (it != _list.end())
    {
        int first = *it;
        ++it;
        if (it != _list.end())
        {
            int second = *it;
            ++it;
            if (first > second)
            {
                bigVals.push_back(first);
                smallVals.push_back(second);
            }
            else
            {
                bigVals.push_back(second);
                smallVals.push_back(first);
            }
        }
        else
            smallVals.push_back(first);
    }
}

void PmergeList::FordJohnsonSort()
{
    // Implement merge sort algorithm for list
    std::list <unsigned int> bigVals, smallVals;

    if (_list.size() <= 1)
        return;
    mergeSort(bigVals, smallVals);
    _list = bigVals;
    FordJohnsonSort();
    for (int value : smallVals)
        binaryInsert(_list, value);
}

void PmergeList::binaryInsert(std::list<unsigned int> &list, unsigned int value)
{
    // Define the range for binary search
    auto begin = list.begin();
    auto end = list.end();

    // Perform binary search manually
    while (begin != end)
    {
        // Find the middle point by advancing the iterator
        auto middle = begin;
        std::advance(middle, std::distance(begin, end) / 2);
        if (*middle < value)
            begin = ++middle; // Move the lower bound up
        else
            end = middle; // Narrow the upper bound
    }
    // Insert the value at the correct position
    list.insert(begin, value);
}

// void PmergeList::insertSort(std::list<unsigned int> &list, unsigned int value)
// {
//     std::list<unsigned int>::iterator it = list.begin();
//     while (it != list.end() && *it < value)
//         ++it;
//     list.insert(it, value);
// }

std::size_t PmergeList::size()
{
    return _list.size();
}
