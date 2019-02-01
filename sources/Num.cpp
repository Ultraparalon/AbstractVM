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

void	Num::check(std::string const & str) // checks if string made of 0-9 . - symbols
{
	for (auto c:str)
	{
		if ((c < '0' || c > '9') && c != '.' && c != '-')
			throw NumException();
	}
}

//NumException---------------------------------------------------

const char *	Num::NumException::what() const throw()
{
	return "Val is not number";
}
