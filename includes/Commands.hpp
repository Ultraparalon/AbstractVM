/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:31:34 by vkaidans          #+#    #+#             */
/*   Updated: 2019/02/01 20:31:36 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"
#include "Typer.hpp"
#include "Poper.hpp"
#include "Num.hpp"

//Assert------------------------------------------------------------------------

class CmdAssert : public ICommand
{
	Typer typer;
	Num num;
	
public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class AssertException : public std::exception
	{
		std::string err;

	public:
		AssertException() throw();
		AssertException(std::string const &) throw();
		AssertException(AssertException const &) throw();
		virtual ~AssertException() throw();
		virtual const char*	what() const throw();
		AssertException &	operator=(AssertException const &) throw();
	};
};

//Dump--------------------------------------------------------------------------

class CmdDump : public ICommand
{
public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class WrongSizeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

//Exit--------------------------------------------------------------------------

class CmdExit : public ICommand
{
public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class WrongSizeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

//Math--------------------------------------------------------------------------

class CmdMath : public ICommand
{
	Poper poper;
	
public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class MathException : public std::exception
	{
		std::string err;

	public:
		MathException() throw();
		MathException(std::string) throw();
		MathException(MathException const &) throw();
		virtual ~MathException() throw();
		virtual const char*	what() const throw();
		MathException &	operator=(MathException const &) throw();
	};
};

//Max---------------------------------------------------------------------------

class CmdMax : public ICommand
{
	Poper poper;

public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class MaxException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

//Min---------------------------------------------------------------------------

class CmdMin : public ICommand
{
	Poper poper;

public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class MinException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

//Pop---------------------------------------------------------------------------

class CmdPop : public ICommand
{
	Poper poper;

public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class PopException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

//Print-------------------------------------------------------------------------

class CmdPrint : public ICommand
{
public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class PrintException : public std::exception
	{
		std::string err;

	public:
		PrintException() throw();
		PrintException(std::string) throw();
		PrintException(PrintException const &) throw();
		virtual ~PrintException() throw();
		virtual const char*	what() const throw();
		PrintException &	operator=(PrintException const &) throw();
	};
};

//Push--------------------------------------------------------------------------

class CmdPush : public ICommand
{
	Typer typer;
	Num num;

public:
	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class WrongSizeException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};
