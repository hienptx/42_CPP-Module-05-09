#include "../includes/PmergeMe.hpp"

template<typename T>
std::size_t PmergeMe::getSize(T container)
{
    return container.size();
}

template<typename T>
bool PmergeMe::isSorted(T begin, T end)
{
    for (auto it = begin; it != end - 1; ++it)
    {
        if (*it > *(it + 1))
            return false;
    }
    return true;
}

template<typename T>
void PmergeMe::printFunction(T container,std::string message)
{
    typename T::iterator it = container.begin();
    
    std::cout << message;
    while(it != container.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}
