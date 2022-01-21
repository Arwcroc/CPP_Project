/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:27:32 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:52:46 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern() {};
		Intern(Intern const & src) { *this = src; };
		~Intern() {};

		Intern & operator=(Intern const & src)
		{
			(void)src;
			return *this;
		}
		
		Form*  makeform(std::string formName, std::string target);

	private:
		
};

#endif