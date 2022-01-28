/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:52:13 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/28 15:58:53 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(std::string str) : _valueChar(), _valueInt()
{
	this->_is_valid = true;
	this->_is_valid_str = true;
		
	if (!is_valid_str(str))
		this->_is_valid_str = false;
	else
	{
		if (!atoi(str.c_str()) && str.size() == 1)
			this->_valueInt = static_cast<int>(str[0]);
		else
			this->_valueInt = atoiMod(str);
		if (str.size() == 1)
		{
			char const c = str[0];
			if (c >= ' ' && c < 127 && !atoi(str.c_str()))
				this->_valueChar = static_cast<char>(str[0]);
			else
				this->_valueChar = -1;
		}
		else if (str.size() != 1)
		{
			this->_valueChar = static_cast<char>(_valueInt);
		}
	}

	if (!is_valid(str))
		this->_is_valid = false;
	else
	{
		if (!atoi(str.c_str()) && str.size() == 1)
		{
			this->_valueFloat = static_cast<float>(str[0]);
			this->_valueDouble = static_cast<double>(str[0]);
		}
		else
		{
			this->_valueFloat = atofMod(str);
			this->_valueDouble = atofMod(str);
		}
	}
}

int		Convert::atoiMod(std::string input) const
{
	const char *str = input.c_str();
	long nb = atol(str);
	
	if (nb < INT_MIN || nb > INT_MAX)
		throw ImpossibleStatus("Impossible Conversion\n");
	return static_cast<int>(nb);
}

float Convert::atofMod(std::string input) const
{
	const char *str = input.c_str();
	float nb = strtof(str, NULL);
	
	if (errno == ERANGE)
		throw ImpossibleStatus("Impossible Conversion\n");
	return static_cast<float>(nb);
}

char Convert::getChar() const
{
	if (this->_is_valid_str == false)
		throw ImpossibleStatus("Impossible Conversion\n");
	if (_valueFloat != _valueFloat || _valueDouble != _valueDouble)
		throw ImpossibleStatus("impossible\n");
	if (_valueChar < ' ' || _valueChar > 126)
		throw ImpossibleStatus("Non displayable\n");
	return this->_valueChar;
}

int Convert::getInt() const
{
	if (this->_is_valid_str == false)
		throw ImpossibleStatus("Impossible Conversion\n");
	if (_valueFloat != _valueFloat || _valueDouble != _valueDouble)
		throw ImpossibleStatus("impossible\n");
	return this->_valueInt;
}

float Convert::getFloat() const
{
	if (this->_is_valid == false)
		throw ImpossibleStatus("Impossible Conversion\n");
	return this->_valueFloat;
}

double Convert::getDouble() const
{
	if (this->_is_valid == false)
		throw ImpossibleStatus("Impossible Conversion\n");
	return this->_valueDouble;
}

int is_valid(std::string input)
{
	int j = 0;
	int k = 0;
	bool point = false;

	if (input.compare("-inf") == 0 || input.compare("inf") == 0 || input.compare("nan") == 0 || input.compare("-inff") == 0 || input.compare("inff") == 0 || input.compare("nanf") == 0)
		return (1);
	if (input.size() > 1 && !isdigit(input[input.size() - 1]) && input[input.size() - 1] == 'f')
	{
		for (unsigned int i = 0; i < input.size(); i++)
		{
			if (input[0] == '-')
				i++;
			if (input[i] == '.')
			{
				if (point == true)
					return 0;
				point = true;
			}
			if (!isdigit(input[i]))
				j++;
			if (j > 2)
				return 0;
		}
	}
	j = 0;
	if (input.size() > 1 && !isdigit(input[input.size() - 1]) && input[input.size() - 1] != 'f')
	{
		for (unsigned int i = 0; i < input.size(); i++)
		{
			if (input[0] == '-')
				i++;
			if (input[i] == '.')
			{
				if (point == true)
					return 0;
				point = true;
			}
			if (!isdigit(input[i]))
				j++;
			if (isdigit(input[i]))
				k++;
			if (j > 0 && k > 0)
				return(0);
		}
	}
	if (atoi(input.c_str()) || atof(input.c_str()))
		return (1);
	if (!atoi(input.c_str()))
	{
		char *str = (char *)input.c_str();
		str[0]++;
		if (atoi(str))
			return (1);
		if (input.size() == 1)
			return (1);
		return (0);
	}
	return (0);
}

int is_valid_str(std::string input)
{
	if (is_valid(input))
	{
		if (static_cast<long int>(atof(input.c_str())) <= INT_MAX && 
			static_cast<long int>(atof(input.c_str())) >= INT_MIN)
			return (1);
	}
	return (0);
}

std::ostream &operator<<(std::ostream &out, Convert const &src)
{
	try
	{
		out << "char:    " << src.getChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what();
	}

	try
	{
		out << "int:     " << src.getInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		out << "float:   " << src.getFloat();
		if (static_cast<int>(src.getFloat()) == src.getFloat())
			out << ".0";
		out << 'f' << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		out << "double:  " << src.getDouble();
		if (static_cast<int>(src.getDouble()) == src.getDouble())
			out << ".0";
		out << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
	return (out);
}
