/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annuaire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:10:08 by tefroiss          #+#    #+#             */
/*   Updated: 2021/10/25 15:03:08 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Annuaire.hpp"

std::string trans_string(int i)
{
	std::stringstream str;

	str << i;
	return str.str();
}

int str_to_int(std::string str)
{
	int ret;

	std::istringstream(str) >> ret;
	return ret;
}

void Annuaire::_show_contact(void) const
{
	const std::string attributes[] = 
		{"index", "first_name", "last_name", "nickname"};
	
	// for (int i = 0; i < 4; i++)
	// 	this->show_Attributes(this->_contacts[i], attributes[i]);
	std::cout << std::setw(10) << attributes[0] << "|";
	std::cout << std::setw(10) << attributes[1] << "|";
	std::cout << std::setw(10) << attributes[2] << "|";
	std::cout << std::setw(10) << attributes[3] << "|" << std::endl;
	for (int j = 0; j < this->_index_contact; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (k == 0)
				this->show_Attributes(this->_contacts[j], trans_string(j));
			else
				this->show_Attributes(this->_contacts[j], attributes[k]);
		}
		std::cout << std::endl;
	}
}

bool Annuaire::_check_cmd_in(const std::string input) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			return false;
		}
	}
	return true;
}

std::string		ft_strim(std::string input, char c)
{
	size_t begin = input.find_first_not_of(c);
	size_t end = input.find_last_not_of(c);

	if (begin != std::string::npos && end != std::string::npos)
		return (input.substr(begin, (end + 1)));
	return "";
}

std::string Annuaire::_cmd_in(const char *command) const
{
	std::string line;

	std::cout << command << std::endl;
	std::getline(std::cin, line);
	return (ft_strim(line, ' '));
}


void Annuaire::addContact(void)
{
	if (this->_index_contact < 8 && this->_index_contact >= 0)
	{
		this->_contacts[this->_index_contact++].init_attributes();
	}
	else
	{
		this->_contacts[this->_index_contact - 1].init_attributes();
	}
}

void	Annuaire::show_Attributes(Contact contact, std::string attribute) const
{
	std::string prompt = contact.get_contact(attribute);

	if (prompt.length() > 0)
		std::cout << std::setw(10) << prompt << "|";
	else
		std::cout << std::setw(10) << attribute << "|";
}

void	Annuaire::searchContact(void) const
{
	if (this->_index_contact > 0)
	{
		this->_show_contact();
		const std::string input = this->_cmd_in("Index : ");
		if (this->_check_cmd_in(input))
		{
			int index = str_to_int(input);
			if (index < this->_index_contact)
				this->_contacts[index].show_contact();
			else
			{
				std::cerr << "Error : Wrong index" << std::endl;
				this->searchContact();
			}
		}
		else
		{
			std::cerr << "Error : Input must be digit" << std::endl;
			this->searchContact();
		}
	}
	else
	{
		std::cerr << "Error : no entry in the phone book. Please add one with the ADD command." << std::endl;
	}
}

bool Annuaire::_valid_cmd(std::string cmd)
{
	if (cmd.compare("EXIT") == 0)
	{
		std::cout << "Thanks to your fidelity !" << std::endl;
		std::cout << "All repertory have been cleaned..." << std::endl;
		std::cout << "Have a nive day Bro :)" << std::endl;
		return (false);
	}
	else if (cmd.compare("ADD") == 0)
		this->addContact();
	else if (cmd.compare("SEARCH") == 0)
		this->searchContact();
	else
	{
		std::cerr << "Error : Invalid Command !" << std::endl;
		std::cin.clear();
	}
	return (true);
}

int Annuaire::run(void)
{
	std::string cmd = 
		this->_cmd_in("What do you want ? (ADD, SEARCH, EXIT) >> ");

	if (this->_valid_cmd(cmd))
		return (run());
	return (0);
}