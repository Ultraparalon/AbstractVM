/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poper.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:04:03 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/23 13:05:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Poper.hpp"

Poper::Poper() {}
Poper::Poper(Poper const & obj) {	*this = obj;	}
Poper::~Poper() {}

Poper &	Poper::operator=(Poper const &)
{
	return *this;
}

IOperand const *	Poper::get(std::stack<IOperand const *> & oper,
	IOperand const * tmp)
{
	if (oper.empty())
	{
		if (tmp)
			oper.push(tmp);
		throw EmptyStackException();
	}
	tmp = oper.top();
	oper.pop();
	return tmp;
}

//EmptyStackException---------------------------------------------------

Poper::EmptyStackException::EmptyStackException() throw() {}
Poper::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
Poper::EmptyStackException::~EmptyStackException() throw() {}
const char *	Poper::EmptyStackException::what() const throw()
{
	return "Empty stack";
}
Poper::EmptyStackException &	Poper::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}
