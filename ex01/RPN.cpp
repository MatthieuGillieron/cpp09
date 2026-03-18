
#include "RPN.hpp"


// === CANONICAL FORM === 

RPN::RPN()
{}

RPN::RPN(const RPN &other) : _stack(other._stack)
{}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN()
{}


// == UTILS == 

bool RPN::_isDgit(std::string &token)
{
	if (!isdigit(token[0]))
		return false;
	return true;
}

bool RPN::_isOperator(const std::string &op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
		return true;
	return false;
}

int RPN::_calcul(const std::string &op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("error: need 2 number for calculate");
		
	int a;
	int b;

	a = _stack.top();
	_stack.pop();

	b = _stack.top();
	_stack.pop();

	if (op == "+")
		return (b + a);
	if (op == "-")
		return (b - a);
	if (op == "*")
		return (b * a);
	if (op == "/")
	{
		if (a == 0)
			throw std::runtime_error("error: division with 0");
		else
			return (b / a);
	}
	throw std::runtime_error("error: invalid operator");
}

// === METHODE ===

void RPN::process(const std::string &input)
{
	std::istringstream ss(input);
	std::string token;

	try
	{
		while (ss >> token)
		{
			if (_isDgit(token))
			{
				int Itoken;
				std::istringstream convertToken(token);
				convertToken >> Itoken;
				
				_stack.push(Itoken);
			}

			else if (_isOperator(token))
			{
				int result = _calcul(token);
				_stack.push(result);
			}
			else
				throw std::invalid_argument("error");
		}
		std::cout << _stack.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}