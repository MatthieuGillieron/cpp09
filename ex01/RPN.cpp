
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
// === METHODE ===

void RPN::process(const std::string &expression)
{

}