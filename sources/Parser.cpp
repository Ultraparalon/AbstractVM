/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:47:15 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 11:47:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser()
{
	_commands["push"] = new CmdPush;
	_commands["pop"] = new CmdPop;
	_commands["dump"] = new CmdDump;
	_commands["assert"] = new CmdAssert;
	_commands["add"] = new CmdMath;
	_commands["sub"] = new CmdMath;
	_commands["mul"] = new CmdMath;
	_commands["div"] = new CmdMath;
	_commands["mod"] = new CmdMath;
	_commands["max"] = new CmdMax;
	_commands["min"] = new CmdMin;
	_commands["print"] = new CmdPrint;
	_commands["exit"] = new CmdExit;
}
Parser::Parser(Parser const &) {}
Parser::~Parser()
{
	for (std::map<std::string, ICommand *>::iterator it = _commands.begin();
			it != _commands.end(); it++)
	{
		if (it->second)
		{
			delete it->second;
			it->second = NULL;
		}
	}
}

Parser &	Parser::operator=(Parser const &)
{
	return *this;
}

ICommand *	Parser::operate(std::string const & cmd)
{
	return _commands.at(cmd);
}
