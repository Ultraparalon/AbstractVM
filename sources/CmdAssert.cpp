/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdAssert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:44:04 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:05 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdAssert.hpp"

CmdAssert::CmdAssert() {}
CmdAssert::CmdAssert(CmdAssert const & obj)
{
	*this = obj;
}
CmdAssert::~CmdAssert() {}

CmdAssert &	CmdAssert::operator=(CmdAssert const &)
{
	return *this;
}

void	CmdAssert::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	if (vec.size() != 3)
		throw CmdAssert::AssertException("wrong amount of arguments");

	if (oper.empty())
	{
		throw CmdAssert::AssertException("Empty stack");
	}

	num.check(vec[2]);

	if (typer.get(vec.at(1)) != oper.top()->getPrecision()
		|| std::stod(vec.at(2)) != std::stod(oper.top()->toString()))
	{
		throw CmdAssert::AssertException("Non equal");
	}
}

//AssertException---------------------------------------------------

CmdAssert::AssertException::AssertException() throw() : err("Error") {}
CmdAssert::AssertException::AssertException(std::string const & str) throw() : err(str) {}
CmdAssert::AssertException::AssertException(AssertException const & obj) throw()
{
	*this = obj;
}
CmdAssert::AssertException::~AssertException() throw() {}
const char *	CmdAssert::AssertException::what() const throw()
{
	return err.c_str();
}
CmdAssert::AssertException &	CmdAssert::AssertException::operator=(AssertException const &) throw()
{
	return *this;
}
