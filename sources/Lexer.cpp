/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:43:45 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 13:43:46 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

std::vector<std::string>	Lexer::explode(std::string const & str) // divide string to vector<string>
{
	std::string buff;
	std::vector<std::string> vec;

	for (auto n:str)
	{
		if ((n == ' ' || n == '(' || n == ')') && buff.length())
		{
			vec.push_back(buff);
			buff = "";
		}
		else if (n != ' ' && n != '(' && n != ')')
			buff += n;
	}
	if (buff != "")
		vec.push_back(buff);

	return vec;
}
