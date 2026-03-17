
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



// === METHODE ===

void RPN::process(const std::string &expression)
{
	
}