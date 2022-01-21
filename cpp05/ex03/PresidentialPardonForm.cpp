/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:11 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:47:32 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", false, 25, 5), _name_target("null") {}

PresidentialPardonForm::PresidentialPardonForm(std::string name_target) : Form("PresidentialPardonForm", false, 25, 5), _name_target(name_target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const Name, bool Signed, int const gr_exec, int const gr_sign): Form("PresidentialPardonForm", Signed, gr_exec, gr_sign),  _name_target(Name) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) { *this = src; }

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->getNameTarget() << " destroyed !" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	this->_name_target = src.getNameTarget();
	return *this;
}

std::string PresidentialPardonForm::getNameTarget() const { return (this->_name_target); }

void PresidentialPardonForm::execute(Bureaucrat const & src) const
{
	if (src.getGrade() > this->getGradeExec())
		throw GradeTooLowException("Grade too LOW in comparison with the recommand grade.");
	else if (!this->getGradeSign())
		throw GradeTooLowException("Impossible to get the grade required to sign the form.");
	
	std::cout << "Congrats to " << this->getNameTarget() << ". Zafod Beeblebrox announces he forgives you. For what ? I'm sure you already know that..." << std::endl;
}