/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:27:34 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/06 11:44:16 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Form *ShrubberyCreationIF(std::string const & target) { return (new ShrubberyCreationForm(target)); }

Form *PresidentialPardonIF(std::string const & target) { return (new PresidentialPardonForm(target)); }

Form *RobotomyRequestIF(std::string const & target) { return (new RobotomyRequestForm(target)); }

Form *Intern::makeform(std::string formName, std::string target)
{
	Form *indexForm;
	Form *(*p[3])(std::string const &otherTarget) = {
		ShrubberyCreationIF,
		PresidentialPardonIF,
		RobotomyRequestIF
	};
	std::string name[3] = {
		"Shrubbery Creation",
		"Presidential Pardon",
		"Robotomy Request"
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == name[i])
		{
			indexForm = (*p[i])(target);
			std::cout << "Intern creates " << indexForm->getName() << std::endl;
			return (indexForm);
		}
	}
	std::cout << formName << " couldn't be find. This is the Administration's rule..." << std::endl;
	return (0);
}
