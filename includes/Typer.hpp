/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Typer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:33:37 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/22 16:33:40 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"

class Typer
{
public:
	Typer();
	Typer(Typer const &);
	~Typer();

	Typer &	operator=(Typer const &);

	eOperandType	get(std::string const &);

	class NonexistentTypeException : public std::exception
	{
	public:
		NonexistentTypeException() throw();
		NonexistentTypeException(NonexistentTypeException const &) throw();
		virtual ~NonexistentTypeException() throw();
		virtual const char*	what() const throw();
		NonexistentTypeException &	operator=(NonexistentTypeException const &) throw();
	};
};
