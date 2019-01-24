/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMin.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:53:38 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/22 21:53:42 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Poper.hpp"

class CmdMin : public ICommand
{
	Poper poper;

public:
	CmdMin();
	CmdMin(CmdMin const &);
	~CmdMin();

	CmdMin &	operator=(CmdMin const &);

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
