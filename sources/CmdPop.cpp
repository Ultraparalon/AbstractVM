/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:43:44 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdPop.hpp"

CmdPop::CmdPop() {}
CmdPop::CmdPop(CmdPop const & obj)
{
	*this = obj;
}
CmdPop::~CmdPop() {}

CmdPop &	CmdPop::operator=(CmdPop const &)
{
	return *this;
}

void	CmdPop::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	if (vec.size() != 1)
		throw PopException();

	delete poper.get(oper, NULL);
}

//PopException---------------------------------------------------

CmdPop::PopException::PopException() throw() {}
CmdPop::PopException::PopException(PopException const & obj) throw()
{
	*this = obj;
}
CmdPop::PopException::~PopException() throw() {}
const char *	CmdPop::PopException::what() const throw()
{
	return "Wrong amount of arguments";
}
CmdPop::PopException &	CmdPop::PopException::operator=(PopException const &) throw()
{
	return *this;
}
