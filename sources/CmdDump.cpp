/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdDump.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:43:52 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:55 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdDump.hpp"

CmdDump::CmdDump() {}
CmdDump::CmdDump(CmdDump const & obj)
{
	*this = obj;
}
CmdDump::~CmdDump() {}

CmdDump &	CmdDump::operator=(CmdDump const &)
{
	return *this;
}

void	CmdDump::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	std::stack<const IOperand *> st = oper;

	if (vec.size() != 1)
		throw CmdDump::WrongSizeException();

	while (!st.empty())
	{
		std::cout << st.top()->toString() << std::endl;
		st.pop();
	}
}

//WrongSizeException---------------------------------------------------

CmdDump::WrongSizeException::WrongSizeException() throw() {}
CmdDump::WrongSizeException::WrongSizeException(WrongSizeException const & obj) throw()
{
	*this = obj;
}
CmdDump::WrongSizeException::~WrongSizeException() throw() {}
const char *	CmdDump::WrongSizeException::what() const throw()
{
	return "Wrong amount of arguments";
}
CmdDump::WrongSizeException &	CmdDump::WrongSizeException::operator=(WrongSizeException const &) throw()
{
	return *this;
}
