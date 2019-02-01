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
	IOperand const *	get(std::stack<IOperand const *> &, IOperand const *);

	class EmptyStackException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};	
};
