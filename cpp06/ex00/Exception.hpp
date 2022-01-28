#pragma once

#include <stdexcept>
#include <iostream>

class ImpossibleStatus : public std::exception
{
	public:
		ImpossibleStatus(std::string str) { this->_str = str; };
		virtual ~ImpossibleStatus() throw(){};
		virtual const char *what() const throw()
		{
			return (_str.c_str());
		}

	private:
		std::string _str;
};
