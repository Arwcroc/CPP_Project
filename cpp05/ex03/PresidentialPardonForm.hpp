/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:15 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/21 17:04:05 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "RobotomyRequestForm.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name_target);
		PresidentialPardonForm(std::string const Name, bool Signed, int const gr_exec, int const gr_sign);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
		
		std::string getNameTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
		
	private:
		std::string _name_target;
};

#endif