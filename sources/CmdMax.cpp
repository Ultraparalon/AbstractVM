/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMax.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:54:24 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/22 21:54:26 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdMax.hpp"

CmdMax::CmdMax() {}
CmdMax::CmdMax(CmdMax const & obj)
{
	*this = obj;
}
CmdMax::~CmdMax() {}

CmdMax &	CmdMax::operator=(CmdMax const &)
{
	return *this;
}

void	CmdMax::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	if (vec.size() != 1)
		throw CmdMax::MaxException();

	IOperand const * first = poper.get(oper, NULL);
	IOperand const * second = poper.get(oper, first);

	if (std::stod(first->toString()) > std::stod(second->toString()))
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

CmdMax::MaxException::MaxException() throw() {}
CmdMax::MaxException::MaxException(MaxException const & obj) throw()
{
	*this = obj;
}
CmdMax::MaxException::~MaxException() throw() {}
const char *	CmdMax::MaxException::what() const throw()
{
	return "Wrong amount of arguments";
}
CmdMax::MaxException &	CmdMax::MaxException::operator=(MaxException const &) throw()
{
	return *this;
}
