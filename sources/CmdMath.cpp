/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMath.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:34:02 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/21 21:34:04 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdMath.hpp"

CmdMath::CmdMath() {}
CmdMath::CmdMath(CmdMath const & obj)
{
	*this = obj;
}
CmdMath::~CmdMath() {}

CmdMath &	CmdMath::operator=(CmdMath const &)
{
	return *this;
}

void	CmdMath::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	if (vec.size() != 1)
		throw CmdMath::MathException("Wrong amount of arguments");

	IOperand const * first = poper.get(oper, NULL);
	IOperand const * second = poper.get(oper, first);

	try
	{
		if (vec[0] == "add")
		{
			oper.push(*second + *first);
		}
		else if (vec[0] == "sub")
		{
			oper.push(*second - *first);
		}
		else if (vec[0] == "mul")
		{
			oper.push(*second * *first);
		}
		else if (vec[0] == "div")
		{
			if (!std::stod(first->toString()))
			{
				throw CmdMath::MathException("Division by zero");
			}
			oper.push(*second / *first);
		}
		else if (vec[0] == "mod")
		{
			if (!std::stod(first->toString()))
			{
				throw CmdMath::MathException("Mod by zero");
			}
			if (first->getType() > INT32 || second->getType() > INT32)
			{
				throw CmdMath::MathException("Floating point");
			}
			oper.push(*second % *first);
		}

		delete first;
		delete second;
	}
	catch (std::exception & e)
	{
		oper.push(second);
		oper.push(first);
		std::cerr << "Error: " << e.what() << "!\n";
	}
}

//MathException---------------------------------------------------

CmdMath::MathException::MathException() throw() : err("Error") {}
CmdMath::MathException::MathException(std::string err) throw() : err(err) {}
CmdMath::MathException::MathException(MathException const & obj) throw()
{
	*this = obj;
}
CmdMath::MathException::~MathException() throw() {}
const char *	CmdMath::MathException::what() const throw()
{
	return err.c_str();
}
CmdMath::MathException &	CmdMath::MathException::operator=(MathException const &) throw()
{
	return *this;
}
