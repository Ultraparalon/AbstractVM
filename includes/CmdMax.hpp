/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMax.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:53:53 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/22 21:53:55 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Poper.hpp"

class CmdMax : public ICommand
{
	Poper poper;

public:
	CmdMax();
	CmdMax(CmdMax const &);
	~CmdMax();

	CmdMax &	operator=(CmdMax const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class MaxException : public std::exception
	{
	public:
		MaxException() throw();
		MaxException(MaxException const &) throw();
		virtual ~MaxException() throw();
		virtual const char*	what() const throw();
		MaxException &	operator=(MaxException const &) throw();
	};
};
