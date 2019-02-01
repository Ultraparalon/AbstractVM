/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:32:02 by vkaidans          #+#    #+#             */
/*   Updated: 2019/02/01 20:32:04 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Commands.hpp"

//==============================================================================
// Assert
//==============================================================================

void	CmdAssert::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // command that checks if operands are equal, otherwise throws error
{
	if (vec.size() != 3)
		throw CmdAssert::AssertException("wrong amount of arguments");

	if (oper.empty())
	{
		throw CmdAssert::AssertException("Empty stack");
	}

	num.check(vec[2]);

	if (typer.get(vec.at(1)) != oper.top()->getPrecision()
		|| std::stod(vec.at(2)) != std::stod(oper.top()->toString()))
	{
		throw CmdAssert::AssertException("Non equal");
	}
}

//AssertException---------------------------------------------------------------

CmdAssert::AssertException::AssertException() throw() : err("Error") {}
CmdAssert::AssertException::AssertException(std::string const & str) throw() : err(str) {}
CmdAssert::AssertException::AssertException(AssertException const & obj) throw()
{
	*this = obj;
}
CmdAssert::AssertException::~AssertException() throw() {}
const char *	CmdAssert::AssertException::what() const throw()
{
	return err.c_str();
}
CmdAssert::AssertException &	CmdAssert::AssertException::operator=(AssertException const & obj) throw()
{
	this->err = obj.err;
	return *this;
}

//==============================================================================
// Dump
//==============================================================================

void	CmdDump::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // command that shows current operands in the stack
{
	std::stack<const IOperand *> st = oper;

	if (vec.size() != 1)
		throw CmdDump::WrongSizeException();

	while (!st.empty())
	{
		std::cout << st.top()->toString() << std::endl;
		st.pop();
	}
}

//WrongSizeException------------------------------------------------------------

const char *	CmdDump::WrongSizeException::what() const throw()
{
	return "Wrong amount of arguments";
}

//==============================================================================
// Exit
//==============================================================================

void	CmdExit::execute(std::stack<const IOperand *> &,
	std::vector<std::string> & vec, OpFactory &) // exit command
{
	if (vec.size() != 1)
		throw CmdExit::WrongSizeException();

	exit(0);
}

//WrongSizeException------------------------------------------------------------

const char *	CmdExit::WrongSizeException::what() const throw()
{
	return "Wrong amount of arguments";
}

//==============================================================================
// Math
//==============================================================================

void	CmdMath::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // command that makes math operations
{
	if (vec.size() != 1)
		throw CmdMath::MathException("Wrong amount of arguments");

	IOperand const * first = poper.get(oper, NULL);
	IOperand const * second = poper.get(oper, first);

	try
	{
		if (vec[0] == "add")
		{
			oper.push(*second + *first);
		}
		else if (vec[0] == "sub")
		{
			oper.push(*second - *first);
		}
		else if (vec[0] == "mul")
		{
			oper.push(*second * *first);
		}
		else if (vec[0] == "div")
		{
			if (!std::stod(first->toString()))
			{
				throw CmdMath::MathException("Division by zero");
			}
			oper.push(*second / *first);
		}
		else if (vec[0] == "mod")
		{
			if (!std::stod(first->toString()))
			{
				throw CmdMath::MathException("Mod by zero");
			}
			if (first->getType() > INT32 || second->getType() > INT32)
			{
				throw CmdMath::MathException("Floating point");
			}
			oper.push(*second % *first);
		}

		delete first;
		delete second;
	}
	catch (std::exception & e)
	{
		oper.push(second);
		oper.push(first);
		std::cerr << "Error: " << e.what() << "!\n";
	}
}

//MathException-----------------------------------------------------------------

CmdMath::MathException::MathException() throw() : err("Error") {}
CmdMath::MathException::MathException(std::string err) throw() : err(err) {}
CmdMath::MathException::MathException(MathException const & obj) throw()
{
	*this = obj;
}
CmdMath::MathException::~MathException() throw() {}
const char *	CmdMath::MathException::what() const throw()
{
	return err.c_str();
}
CmdMath::MathException &	CmdMath::MathException::operator=(MathException const & obj) throw()
{
	this->err = obj.err;
	return *this;
}

//==============================================================================
// Max
//==============================================================================

void	CmdMax::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // command takes two operands and return bigger one
{
	if (vec.size() != 1)
		throw CmdMax::MaxException();

	IOperand const * first = poper.get(oper, NULL);
	IOperand const * second = poper.get(oper, first);

	if (std::stod(first->toString()) > std::stod(second->toString()))
	{
		oper.push(first);
		delete second;
	}
	else
	{
		oper.push(second);
		delete first;
	}
}

//MaxException------------------------------------------------------------------

const char *	CmdMax::MaxException::what() const throw()
{
	return "Wrong amount of arguments";
}

//==============================================================================
// Min
//==============================================================================

void	CmdMin::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // command take two operand and return little one
{
	if (vec.size() != 1)
		throw CmdMin::MinException();

	IOperand const * first = poper.get(oper, NULL);
	IOperand const * second = poper.get(oper, first);

	if (std::stod(first->toString()) < std::stod(second->toString()))
	{
		oper.push(first);
		delete second;
	}
	else
	{
		oper.push(second);
		delete first;
	}
}

//MinException------------------------------------------------------------------

const char *	CmdMin::MinException::what() const throw()
{
	return "Wrong amount of arguments";
}

//==============================================================================
// Pop
//==============================================================================

void	CmdPop::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // command pop out last operand
{
	if (vec.size() != 1)
		throw PopException();

	delete poper.get(oper, NULL);
}

//PopException------------------------------------------------------------------

const char *	CmdPop::PopException::what() const throw()
{
	return "Wrong amount of arguments";
}

//==============================================================================
// Print
//==============================================================================

void	CmdPrint::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory &) // if last operand if int8, command print it like a char symbol
{
	if (vec.size() != 1)
	{
		throw PrintException("Wrong amount of arguments");
	}

	if (oper.empty())
	{
		throw PrintException("Empty stack");
	}

	if (oper.top()->getType() != INT8)
	{
		throw PrintException("Wrong type");
	}
	else
	{
		std::cout << static_cast<char>(std::stoi(oper.top()->toString()))
			<< std::endl;
	}
}

//PrintException----------------------------------------------------------------

CmdPrint::PrintException::PrintException() throw() : err("Error") {}
CmdPrint::PrintException::PrintException(std::string str) throw() : err(str) {}
CmdPrint::PrintException::PrintException(PrintException const & obj) throw()
{
	*this = obj;
}
CmdPrint::PrintException::~PrintException() throw() {}
const char *	CmdPrint::PrintException::what() const throw()
{
	return err.c_str();
}
CmdPrint::PrintException &	CmdPrint::PrintException::operator=(PrintException const & obj) throw()
{
	this->err = obj.err;
	return *this;
}

//==============================================================================
// Push
//==============================================================================

void	CmdPush::execute(std::stack<const IOperand *> & oper,
	std::vector<std::string> & vec, OpFactory & factory) // command that pushes new operands
{
	if (vec.size() != 3)
	{
		throw CmdPush::WrongSizeException();
	}

	num.check(vec[2]);

	oper.push(factory.createOperand(typer.get(vec.at(1)), vec.at(2)));
}

//WrongSizeException------------------------------------------------------------

const char *	CmdPush::WrongSizeException::what() const throw()
{
	return "Wrong amount of arguments";
}
