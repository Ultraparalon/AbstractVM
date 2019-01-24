/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPrint.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:45:57 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:45:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdPrint.hpp"

CmdPrint::CmdPrint() {}
CmdPrint::CmdPrint(CmdPrint const & obj)
{
	*this = obj;
}
CmdPrint::~CmdPrint() {}

CmdPrint &	CmdPrint::operator=(CmdPrint const &)
{
	return *this;
}

void	CmdPrint::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &)
{
	if (vec.size() != 1)
	{
		throw PrintException("Wrong amount of arguments");
	}

	if (oper.empty())
	{
		throw PrintException("Empty stack");
	}

	if (oper.top()->getType() != INT8)
	{
		throw PrintException("Wrong type");
	}
	else
	{
		std::cout << static_cast<char>(std::stoi(oper.top()->toString()))
			<< std::endl;
	}
}

//PrintException---------------------------------------------------

CmdPrint::PrintException::PrintException() throw() : err("Error") {}
CmdPrint::PrintException::PrintException(std::string str) throw() : err(str) {}
CmdPrint::PrintException::PrintException(PrintException const & obj) throw()
{
	*this = obj;
}
CmdPrint::PrintException::~PrintException() throw() {}
const char *	CmdPrint::PrintException::what() const throw()
{
	return err.c_str();
}
CmdPrint::PrintException &	CmdPrint::PrintException::operator=(PrintException const &) throw()
{
	return *this;
}
