#include <../includes/PmergeMe.hpp>
#include <../includes/PmergeDeque.hpp>

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
    
}
