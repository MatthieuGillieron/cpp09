
#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>


class RPN
{

	private :
			std::stack<int> _stack;
			bool _isDgit(std::string &token);
			bool _isOperator(const std::string &op);
			int _calcul(const std::string &op);



	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void process(const std::string &input);

};



#endif