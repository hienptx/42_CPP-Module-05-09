#include "../includes/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
	if (this != &cpy)
	{
		this->_input = cpy._input;
		this->_stack = cpy._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

void RPN::validate_input(const std::string &input)
{
	if (input.empty())
		throw std::invalid_argument("Error: Empty input.");
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Error: Invalid character in input.");
	if (input.find_first_of("+-*/") == std::string::npos)
		throw std::invalid_argument("Error: No operator found in input.");
	_input = input;		
}

void RPN::calculate(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error: Not enough operands.");
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();
    switch (op)
    {
        case '+':
            _stack.push(b + a);
            break;
        case '-':
            _stack.push(b - a);
            break;
        case '*':
            _stack.push(b * a);
            break;
        case '/':
            if (a == 0)
                throw std::runtime_error("Error: Division by zero.");
            _stack.push(b / a);
            break;
        default:
            throw std::invalid_argument("Error: Invalid operator.");
    }
}

void RPN::parse_input(RPN &rpn)
{
	std::istringstream iss(_input);
	std::string operators("+-*/");
	std::string token;
	
	while (iss >> token)
	{
		if (operators.find(token) != std::string::npos)
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Not enough operands.");
			rpn.calculate(token[0]);
		}
		else
		{
			int num;
			std::istringstream(token) >> num;
			if (num < 0 || num > 9)
				throw std::invalid_argument("Error: Invalid number.");
			_stack.push(num);
		}
	}
	if (_stack.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression.");
	std::cout << _stack.top() << std::endl;
}
