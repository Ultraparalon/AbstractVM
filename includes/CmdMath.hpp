/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMath.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:33:48 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/21 21:33:50 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Poper.hpp"

class CmdMath : public ICommand
{
	Poper poper;
	
public:
	CmdMath();
	CmdMath(CmdMath const &);
	~CmdMath();

	CmdMath &	operator=(CmdMath const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class MathException : public std::exception
	{
		std::string err;

	public:
		MathException() throw();
		MathException(std::string) throw();
		MathException(MathException const &) throw();
		virtual ~MathException() throw();
		virtual const char*	what() const throw();
		MathException &	operator=(MathException const &) throw();
	};
};
