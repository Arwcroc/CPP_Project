/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:27 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:24:12 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("null"), _grade(1) {}

Bureaucrat::Bureaucrat(int i, std::string const Name) : _name(Name)
{
	if (i < 1)
		throw GradeTooHighException("Grade must be set above or equal to 1.");
	else if (i > 150)
		throw GradeTooLowException("Grade must be set under or equal to 150.");
	else
		this->_grade = i;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	this->_grade = src.getGrade();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const { return (this->_name); }

int Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::increaseGrade()
{
	if (this->_grade > 1)
		this->_grade -= 1;
	else 
		throw GradeTooHighException("Grade must be set above or equal to 1.");
}

void Bureaucrat::decreaseGrade()
{
	if (this->_grade < 150)
		this->_grade += 1;
	else 
		throw GradeTooLowException("Grade must be set under or equal to 150.");
}

void Bureaucrat::signForm(Form & Form)
{
	if (this->_grade <= Form.getGradeSign())
	{
		Form.setSign(true);
		std::cout << this->_name << " signs " << Form.getName() << std::endl;
	}
	else
	{
		Form.setSign(false);
		std::cout << this->_name << " cannot sign because grade required is " << Form.getGradeSign() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src)
{
	out << src.getName() << " as come. He has a grade for signature and execution level " << src.getGrade() << "." << std::endl;
	return (out);
}
