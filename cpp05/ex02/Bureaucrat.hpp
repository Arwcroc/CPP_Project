/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:33 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/17 11:02:59 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Exception.hpp"

#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(int i, std::string const Name);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & src);

		std::string getName() const;
		int getGrade() const;

		void increaseGrade();
		void decreaseGrade();

		void signForm(Form & Form);
		void executeForm(Form const & Form) const;

	private:
		std::string const _name;
		int _grade;
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & src);