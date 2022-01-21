#pragma once

#include <stdexcept>
#include <iostream>

class GradeTooHighException : public std::exception
{
	public:
		GradeTooHighException(std::string str) { this->_str = "ERROR : " + str; };
		virtual ~GradeTooHighException() throw(){};
		virtual const char *what() const throw()
		{
			return (_str.c_str());
		}

	private:
		std::string _str;
};

class GradeTooLowException : public std::exception
{
	public:
		GradeTooLowException(std::string str) { this->_str = "ERROR : " + str; };
		virtual ~GradeTooLowException() throw(){};
		virtual const char *what() const throw()
		{
			return (_str.c_str());
		}

	private:
    	std::string _str;
};
