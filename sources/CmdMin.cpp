/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMin.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:54:12 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/22 21:54:14 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdMin.hpp"

CmdMin::CmdMin() {}
CmdMin::CmdMin(CmdMin const & obj)
{
	*this = obj;
}
CmdMin::~CmdMin() {}

CmdMin &	CmdMin::operator=(CmdMin const &)
{
	return *this;
}

void	CmdMin::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	if (vec.size() != 1)
		throw CmdMin::MaxException();

	IOperand const * first = poper.get(oper, NULL);
	IOperand const * second = poper.get(oper, first);

	if (std::stod(first->toString()) < std::stod(second->toString()))
	{
		oper.push(first);
		delete second;
	}
	else
	{
		oper.push(second);
		delete first;
	}
}

//MaxException---------------------------------------------------

CmdMin::MaxException::MaxException() throw() {}
CmdMin::MaxException::MaxException(MaxException const & obj) throw()
{
	*this = obj;
}
CmdMin::MaxException::~MaxException() throw() {}
const char *	CmdMin::MaxException::what() const throw()
{
	return "Wrong amount of arguments";
}
CmdMin::MaxException &	CmdMin::MaxException::operator=(MaxException const &) throw()
{
	return *this;
}
