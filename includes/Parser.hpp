/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:47:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 11:47:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ICommand.hpp"
#include "CmdPush.hpp"
#include "CmdPop.hpp"
#include "CmdDump.hpp"
#include "CmdAssert.hpp"
#include "CmdPrint.hpp"
#include "CmdExit.hpp"
#include "CmdMath.hpp"
#include "CmdMax.hpp"
#include "CmdMin.hpp"

class Parser
{
	std::map<std::string, ICommand *>	_commands;

public:
	Parser();
	Parser(Parser const &);
	~Parser();

	Parser &	operator=(Parser const &);

	ICommand *	operate(std::string const &);
	
};
