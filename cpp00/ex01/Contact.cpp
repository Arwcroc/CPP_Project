/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:25:09 by tefroiss          #+#    #+#             */
/*   Updated: 2021/10/25 15:03:34 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::init_attributes(void)
{
	this->_first_name = this->_cmd_in("First Name");
	this->_last_name = this->_cmd_in("Last Name");
	this->_nickname = this->_cmd_in("Nickname");
	this->_phone_number = this->_cmd_in("Phone Number");
	this->_darkest_secret = this->_cmd_in("Darkest Secret");
}

std::string		ft_strtrim(std::string input, char c)
{
	size_t begin = input.find_first_not_of(c);
	size_t end = input.find_last_not_of(c);
	
	if (begin != std::string::npos && end != std::string::npos)
		return (input.substr(begin, (end + 1)));
	return "";
}

std::string		Contact::_cmd_in(const char *info) const
{
	std::string	input;

	std::cout << info << " : ";
	std::getline(std::cin, input);
	std::cin.clear();
	input = ft_strtrim(input, ' ');
	if (input.length() > 0)
		return input;
	else
	{
		std::cerr << "Error : PUT THE FUCK INPUT BASTARD !" << std::endl << std::endl;
		return this->_cmd_in(info);
	}
}

void	show_attributes(const char *str, std::string attribute)
{
	std::cout << str << " : " << attribute << std::endl;
}

void Contact::show_contact(void) const
{
	show_attributes("First Name", this->_first_name);
	show_attributes("Last Name", this->_last_name);
	show_attributes("Nickname", this->_nickname);
	show_attributes("Phone Number", this->_phone_number);
	show_attributes("Darkest Secret", this->_darkest_secret);
}

std::string Contact::_truncate(std::string str) const
{
	if (str.length() > 10)
	{
		return (str.substr(0, 8) + '.');
	}
	return (str);
}

std::string Contact::get_contact(std::string str) const
{
	if (str.compare("first_name") == 0)
		return (this->_truncate(this->_first_name));
	else if (str.compare("last_name") == 0)
		return (this->_truncate(this->_last_name));
	else if (str.compare("nickname") == 0)
		return (this->_truncate(this->_nickname));
	else
		return (str);
}