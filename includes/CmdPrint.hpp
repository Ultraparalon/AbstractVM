/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPrint.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:42:19 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:42:20 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdPrint : public ICommand
{
public:
	CmdPrint();
	CmdPrint(CmdPrint const &);
	~CmdPrint();

	CmdPrint &	operator=(CmdPrint const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class PrintException : public std::exception
	{
		std::string err;

	public:
		PrintException() throw();
		PrintException(std::string) throw();
		PrintException(PrintException const &) throw();
		virtual ~PrintException() throw();
		virtual const char*	what() const throw();
		PrintException &	operator=(PrintException const &) throw();
	};
};
