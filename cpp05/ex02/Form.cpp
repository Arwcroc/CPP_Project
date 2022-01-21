/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:32:45 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:40:32 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("null"), _grade_to_sign(1), _grade_to_execute(1), _signed(false) {}

Form::Form(std::string const Name, bool signature, int const gr_exec, int const gr_sign) : _name(Name), _grade_to_sign(gr_sign), _grade_to_execute(gr_exec), _signed(signature)
{
	if (signature == true)
		_signed = false;
}

Form::~Form() {}

std::string Form::getName() const { return (this->_name); }

int Form::getGradeSign() const { return (this->_grade_to_sign); }

int Form::getGradeExec() const { return (this->_grade_to_execute); }

bool Form::getSign() const { return (this->_signed); }

void Form::beSigned(Bureaucrat & Bureaucrat)
{
	if (this->_grade_to_sign >= Bureaucrat.getGrade())
		this->_signed = true;
	else
	{
		this->_signed = false;
		throw GradeTooLowException("Grade too LOW in comparison with the recommand grade.");
	}
}

void Form::setSign(bool Signed)
{
	this->_signed = Signed;
}

std::ostream & operator<<(std::ostream & out, Form const & src) 
{
	out << src.getName() << " form. The minimum grade for signature is " << src.getGradeSign() << ". And the minimum grade for execution, " << src.getGradeExec() << ".\nSigned ?\n" << std::boolalpha <<src.getSign() << std::endl;
	return (out);
}