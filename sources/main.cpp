/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:13:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/03 15:13:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "VirtualMachine.hpp"

int	main(int argc, char ** argv)
{
	VirtualMachine vm;

	if (argc == 2)
	{
		std::ifstream	file(argv[1]);
		
		if (file.is_open())
		{
			vm.engine(file);
		}
		else
		{
			std::cerr << "Error: File don't exist\n";
		}
	}
	else
	{
		vm.engine(std::cin);
	}

	// system("leaks avm");
	return (0);
}
