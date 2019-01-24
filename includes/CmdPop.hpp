/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPop.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:38:08 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Poper.hpp"

class CmdPop : public ICommand
{
	Poper poper;

public:
	CmdPop();
	CmdPop(CmdPop const &);
	~CmdPop();

	CmdPop &	operator=(CmdPop const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class PopException : public std::exception
	{
	public:
		PopException() throw();
		PopException(PopException const &) throw();
		virtual ~PopException() throw();
		virtual const char*	what() const throw();
		PopException &	operator=(PopException const &) throw();
	};
};
