/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpFactory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:17:24 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/06 17:17:25 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpFactory.hpp"
#include "Operand.hpp"

IOperand const * OpFactory::createInt8(std::string const & val) const
{
	if (static_cast<char>(std::stoi(val)) != std::stoi(val))
	{
		throw OpFactory::OutOfRangeException();
	}
	return new Operand<char>(std::stoi(val), INT8, this);
}

IOperand const * OpFactory::createInt16(std::string const & val) const
{
	if (static_cast<short>(std::stoi(val)) != std::stoi(val))
	{
		throw OpFactory::OutOfRangeException();
	}
	return new Operand<short>(std::stoi(val), INT16, this);
}

IOperand const * OpFactory::createInt32(std::string const & val) const
{
	return new Operand<int>(std::stoi(val), INT32, this);
}

IOperand const * OpFactory::createFloat(std::string const & val) const
{
	return new Operand<float>(std::stof(val), FLOAT, this);
}

IOperand const * OpFactory::createDouble(std::string const & val) const
{
	return new Operand<double>(std::stod(val), DOUBLE, this);
}

IOperand const *	OpFactory::createOperand(eOperandType type, std::string const & val) const // factory that makes new operands
{
	switch (type)
	{
		case(INT8):		return createInt8(val);		break;
		case(INT16):	return createInt16(val);	break;
		case(INT32):	return createInt32(val);	break;
		case(FLOAT):	return createFloat(val);	break;
		case(DOUBLE):	return createDouble(val);	break;
		default:		return NULL;
	}
}

//OutOfRangeException---------------------------------------------------

const char *	OpFactory::OutOfRangeException::what() const throw()
{
	return "Out of range.";
}
