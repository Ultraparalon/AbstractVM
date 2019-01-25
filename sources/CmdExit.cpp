/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdExit.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:46:05 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:46:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdExit.hpp"

CmdExit::CmdExit() {}
CmdExit::CmdExit(CmdExit const & obj)
{
	*this = obj;
}
CmdExit::~CmdExit() {}

CmdExit &	CmdExit::operator=(CmdExit const &)
{
	return *this;
}

void	CmdExit::execute(std::stack<const IOperand *> &,
	std::vector<std::string> & vec, OpFactory &) // exit command
{
	if (vec.size() != 1)
		throw CmdExit::WrongSizeException();

	exit(0);
}

//WrongSizeException---------------------------------------------------

CmdExit::WrongSizeException::WrongSizeException() throw() {}
CmdExit::WrongSizeException::WrongSizeException(WrongSizeException const & obj) throw()
{
	*this = obj;
}
CmdExit::WrongSizeException::~WrongSizeException() throw() {}
const char *	CmdExit::WrongSizeException::what() const throw()
{
	return "Wrong amount of arguments";
}
CmdExit::WrongSizeException &	CmdExit::WrongSizeException::operator=(WrongSizeException const &) throw()
{
	return *this;
}
