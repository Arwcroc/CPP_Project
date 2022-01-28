/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:52:10 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/28 11:05:46 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <float.h>
#include <cstdlib>
#include <cerrno>
#include "Exception.hpp"

class Convert
{
	public:
		Convert() {};
		Convert(std::string str);
		Convert(Convert const & src) { *this = src; };
		~Convert() {};

		Convert const & operator=(Convert const & src) { return (src); };

		char getChar() const;
		int getInt()const;
		float getFloat() const;
		double getDouble() const;

		int atoiMod(std::string input) const;
		float atofMod(std::string input) const;

	private:
		std::string _input;
		bool _is_valid;
		bool _is_valid_str;
		char _valueChar;
		int _valueInt;
		float _valueFloat;
		double _valueDouble;
};

std::ostream &operator<<(std::ostream &out, Convert const &src);
int is_valid_str(std::string str);
int is_valid(std::string str);