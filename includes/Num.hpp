/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:13:38 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/23 15:13:39 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Num
{
public:
	Num();
	Num(Num const &);
	~Num();

	Num &	operator=(Num const &);

	void	check(std::string const &);

	class NumException : public std::exception
	{
	public:
		NumException() throw();
		NumException(NumException const &) throw();
		virtual ~NumException() throw();
		virtual const char*	what() const throw();
		NumException &	operator=(NumException const &) throw();
	};	
};
