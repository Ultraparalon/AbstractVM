/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMachine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:44 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/04 18:51:46 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine() {}
VirtualMachine::VirtualMachine(VirtualMachine const & obj)	{	*this = obj;	}
VirtualMachine::~VirtualMachine() {}

VirtualMachine &	VirtualMachine::operator=(VirtualMachine const &)
{
	return *this;
}

static void	comment(std::string & str)
{
	if (str.find(";") != std::string::npos)
	{
		str.resize(str.find(";"));
	}
}

void	VirtualMachine::engine(std::istream & stream)
{
	std::string					buff;
	std::vector<std::string>	vec;
	OpFactory					factory;

	while (getline(stream, buff))
	{
		try
		{
			if (buff == ";;" && &stream == &std::cin)
			{
				exit(0);
			}

			comment(buff);

			if (buff == "")
			{
				continue;
			}

			vec = lexer.explode(buff);
			parser.operate(vec.at(0))->execute(_operands, vec, factory);
		}
		catch (std::exception & e)
		{
			std::cerr << "Error: " << e.what() << "!\n";
		}
	}

	std::cerr << "Error: no exit command found!" << std::endl;
}
