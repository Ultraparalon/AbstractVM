/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Poper.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:03:17 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/23 13:03:19 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include "IOperand.hpp"

class Poper
{
public:
	Poper();
	Poper(Poper const &);
	~Poper();

	Poper &	operator=(Poper const &);

	IOperand const *	get(std::stack<IOperand const *> &, IOperand const *);

	class EmptyStackException : public std::exception
	{
	public:
		EmptyStackException() throw();
		EmptyStackException(EmptyStackException const &) throw();
		virtual ~EmptyStackException() throw();
		virtual const char*	what() const throw();
		EmptyStackException &	operator=(EmptyStackException const &) throw();
	};	
};
