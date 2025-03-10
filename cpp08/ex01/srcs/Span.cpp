#include "../includes/Span.hpp"

Span::Span(unsigned int n): N(n)
{}

Span::Span(Span const &copy): N(copy.N)
{}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
		N = copy.N;
	return (*this);
}

Span::~Span()
{}

void Span::addNumber(int num)
{
	if (span.size() >= N)
		throw std::out_of_range("Array is full\n");
	span.push_back(num);
}

unsigned int Span::getSpanSize()
{
	return span.size();
}

unsigned int Span::shortestSpan()
{
	std::vector<unsigned int> shortest;
	unsigned int tmp;
	unsigned int min;

	for(auto it1 = span.begin(); it1 != span.end(); ++it1)
	{
		if (it1 == span.end())
			break ;
		for(auto it2 = it1 + 1; it2 != span.end(); ++it2)
		{
			tmp = std::abs(*it1 - *it2);
			shortest.push_back(tmp);
		}
	}
	min = *shortest.begin();
	for(auto it = shortest.begin(); it != shortest.end(); ++it)
	{
		if (*it < min)
			min = *it;
	}
	return min;
}

unsigned int Span::longestSpan()
{
	std::vector<unsigned int> longest;
	unsigned int tmp;
	unsigned int max;

	for(auto it1 = span.begin(); it1 != span.end(); ++it1)
	{
		if (it1 == span.end())
			break ;
		for(auto it2 = it1 + 1; it2 != span.end(); ++it2)
		{
			tmp = std::abs(*it1 - *it2);
			longest.push_back(tmp);
		}
	}
	max = *longest.begin();
	for(auto it = longest.begin(); it != longest.end(); ++it)
	{
		if (*it > max)
			max = *it;
	}
	return max;
}

void Span::addMoreNumbers(std::vector<int>& arr)
{
	if (arr.size() < N)
		std::for_each(arr.begin(), arr.end(), [this](int x){this->span.push_back(x);});
	else
		std::for_each(arr.begin(), std::next(arr.begin(), N), [this](int x){this->span.push_back(x);});
}
