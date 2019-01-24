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

Typer::Typer() {}
Typer::Typer(Typer const & obj) {	*this = obj;	}
Typer::~Typer() {}

Typer &	Typer::operator=(Typer const &)
{
	return *this;
}

eOperandType	Typer::get(std::string const & stype)
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

Typer::NonexistentTypeException::NonexistentTypeException() throw() {}
Typer::NonexistentTypeException::NonexistentTypeException(NonexistentTypeException const & obj) throw()
{
	*this = obj;
}
Typer::NonexistentTypeException::~NonexistentTypeException() throw() {}
const char *	Typer::NonexistentTypeException::what() const throw()
{
	return "Wrong type.";
}
Typer::NonexistentTypeException &	Typer::NonexistentTypeException::operator=(NonexistentTypeException const &) throw()
{
	return *this;
}
