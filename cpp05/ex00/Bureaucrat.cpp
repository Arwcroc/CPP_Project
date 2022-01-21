/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:27 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 16:58:38 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("null"), _grade(1) {}

Bureaucrat::Bureaucrat(int i, std::string const Name) : _name(Name), _grade(i)
{
	if (i < 1)
		throw GradeTooHighException();
	else if (i > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) { *this = src; }

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
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	if (this->_grade < 150)
		this->_grade += 1;
	else 
		throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src)
{
	out << src.getName() << ", bureaucrat grade is " << src.getGrade() << "." << std::endl;
	return (out);
}