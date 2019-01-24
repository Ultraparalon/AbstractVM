/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdAssert.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:38:26 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:28 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Typer.hpp"
#include "Num.hpp"

class CmdAssert : public ICommand
{
	Typer typer;
	Num num;
	
public:
	CmdAssert();
	CmdAssert(CmdAssert const &);
	~CmdAssert();

	CmdAssert &	operator=(CmdAssert const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class AssertException : public std::exception
	{
		std::string err;

	public:
		AssertException() throw();
		AssertException(std::string const &) throw();
		AssertException(AssertException const &) throw();
		virtual ~AssertException() throw();
		virtual const char*	what() const throw();
		AssertException &	operator=(AssertException const &) throw();
	};
};