/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:14:07 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/23 15:14:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Num.hpp"

Num::Num() {}
Num::Num(Num const & obj) {	*this = obj;	}
Num::~Num() {}

Num &	Num::operator=(Num const &)
{
	return *this;
}

void	Num::check(std::string const & str) // checks if string made of 0-9 . - symbols
{
	for (auto c:str)
	{
		if ((c < '0' || c > '9') && c != '.' && c != '-')
			throw NumException();
	}
}

//NumException---------------------------------------------------

Num::NumException::NumException() throw() {}
Num::NumException::NumException(NumException const & obj) throw()
{
	*this = obj;
}
Num::NumException::~NumException() throw() {}
const char *	Num::NumException::what() const throw()
{
	return "Val is not number";
}
Num::NumException &	Num::NumException::operator=(NumException const &) throw()
{
	return *this;
}
