/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:25:22 by tefroiss          #+#    #+#             */
/*   Updated: 2021/09/27 11:21:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <iomanip>
#include <sstream>

class Contact {

	public:
		std::string get_contact(std::string) const;
		void show_contact(void) const;
		void init_attributes(void);

	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;

		std::string		_cmd_in(const char*) const;
		std::string		_truncate(std::string) const;
};

#endif