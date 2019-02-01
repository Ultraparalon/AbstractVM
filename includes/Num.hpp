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
	void	check(std::string const &);

	class NumException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};	
};
