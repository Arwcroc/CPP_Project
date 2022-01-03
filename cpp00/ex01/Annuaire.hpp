/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:25:15 by tefroiss          #+#    #+#             */
/*   Updated: 2021/10/25 14:20:08 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_HPP
#define ANNUAIRE_HPP
#include "Contact.hpp"

class Annuaire {
	public:
		int				run(void);
		void			addContact(void);
		void			searchContact(void) const;
		void			show_Attributes(Contact, std::string) const;

	private:
		Contact			_contacts[8];
		int				_index_contact;
		std::string		_cmd_in(const char *) const;
		bool			_check_cmd_in(const std::string) const;
		void			_show_contact(void) const;
		bool			_valid_cmd(std::string);

};

#endif