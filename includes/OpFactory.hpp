/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpFactory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:17:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/06 17:17:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"

class OpFactory
{
	IOperand const * createInt8(std::string const &) const;
	IOperand const * createInt16(std::string const &) const;
	IOperand const * createInt32(std::string const &) const;
	IOperand const * createFloat(std::string const &) const;
	IOperand const * createDouble(std::string const &) const;

public:

	IOperand const *	createOperand(eOperandType, std::string const &) const;

	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};	
};
