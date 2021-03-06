/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:32:48 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/16 20:56:59 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	public:
		Form();
		Form(std::string const Name, bool signature, int const gr_exec, int const gr_sign);
		~Form();

		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSign() const;

		void beSigned(Bureaucrat & Bureaucrat);
		void setSign(bool Signed);
		
	private:
		std::string const _name;
		int const _grade_to_sign;
		int const _grade_to_execute;
		bool _signed;

};

std::ostream & operator<<(std::ostream & out, Form const & src);
