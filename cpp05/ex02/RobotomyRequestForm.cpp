/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:18 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:42:24 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", false, 72, 45), _name_target("null") {}

RobotomyRequestForm::RobotomyRequestForm(std::string name_target) : Form("RobotomyRequestForm", false, 72, 45), _name_target(name_target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const Name, bool Signed, int const gr_exec, int const gr_sign): Form("RobotomyRequestForm", Signed, gr_exec, gr_sign),  _name_target(Name) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) { *this = src; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	this->_name_target = src.getNameTarget();
	return *this;
}

std::string RobotomyRequestForm::getNameTarget() const { return (this->_name_target); }

void RobotomyRequestForm::execute(Bureaucrat const & src) const
{
	if (src.getGrade() > this->getGradeExec())
		throw GradeTooLowException("Grade too LOW in comparison with the recommand grade.");
	else if (!this->getGradeSign())
		throw GradeTooLowException("Impossible to get the grade required to sign the form.");
	
	int n = rand() % 9 + 1;

	if (n <= 5)
	{
		std::cout << "Bvvrrrbvrvbrvrvbvbvrrrrrrout zipzip nsap chtak bbbvvvrrrrrbbvrvrbvrbvvrrrrr stonk" << std::endl;
		std::cout << this->getNameTarget() << " as been robotomized." << std::endl;
	}
	else if (n >= 6)
	{
		std::cerr << "ERROR : " << this->getNameTarget() << " can't be robotomized. Drill not operationnal." << std::endl;
	}
}