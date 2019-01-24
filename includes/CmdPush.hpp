/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPush.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:37:58 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:00 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Typer.hpp"
#include "Num.hpp"

class CmdPush : public ICommand
{
	Typer typer;
	Num num;

public:
	CmdPush();
	CmdPush(CmdPush const &);
	~CmdPush();

	CmdPush &	operator=(CmdPush const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class WrongSizeException : public std::exception
	{
	public:
		WrongSizeException() throw();
		WrongSizeException(WrongSizeException const &) throw();
		virtual ~WrongSizeException() throw();
		virtual const char*	what() const throw();
		WrongSizeException &	operator=(WrongSizeException const &) throw();
	};
};
