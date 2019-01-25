/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPush.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:43:31 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:33 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdPush.hpp"

CmdPush::CmdPush() {}
CmdPush::CmdPush(CmdPush const & obj)
{
	*this = obj;
}
CmdPush::~CmdPush() {}

CmdPush &	CmdPush::operator=(CmdPush const &)
{
	return *this;
}

void	CmdPush::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory & factory) // command that pushes new operands
{
	if (vec.size() != 3)
	{
		throw CmdPush::WrongSizeException();
	}

	num.check(vec[2]);

	oper.push(factory.createOperand(typer.get(vec.at(1)), vec.at(2)));
}

//WrongSizeException---------------------------------------------------

CmdPush::WrongSizeException::WrongSizeException() throw() {}
CmdPush::WrongSizeException::WrongSizeException(WrongSizeException const & obj) throw()
{
	*this = obj;
}
CmdPush::WrongSizeException::~WrongSizeException() throw() {}
const char *	CmdPush::WrongSizeException::what() const throw()
{
	return "Wrong amount of arguments";
}
CmdPush::WrongSizeException &	CmdPush::WrongSizeException::operator=(WrongSizeException const &) throw()
{
	return *this;
}
