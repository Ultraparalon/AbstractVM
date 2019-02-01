/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Typer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:33:52 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/22 16:33:55 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Typer.hpp"

eOperandType	Typer::get(std::string const & stype) // return type of operand
{
	if (stype == "int8")
		return INT8;
	else if (stype == "int16")
		return INT16;
	else if (stype == "int32")
		return INT32;
	else if (stype == "float")
		return FLOAT;
	else if (stype == "double")
		return DOUBLE;
	else
		throw Typer::NonexistentTypeException();
}

//NonexistentTypeException---------------------------------------------------

const char *	Typer::NonexistentTypeException::what() const throw()
{
	return "Wrong type.";
}
