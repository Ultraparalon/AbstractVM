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

IOperand const *	Poper::get(std::stack<IOperand const *> & oper,
	IOperand const * tmp) // gets operand from the stack
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

const char *	Poper::EmptyStackException::what() const throw()
{
	return "Empty stack";
}
