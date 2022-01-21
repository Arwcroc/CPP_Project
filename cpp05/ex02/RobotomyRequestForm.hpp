/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:20 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/05 13:54:09 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include <random>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name_target);
		RobotomyRequestForm(std::string const Name, bool Signed, int const gr_exec, int const gr_sign);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm();

		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
		
		std::string getNameTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
		
	private:
		std::string _name_target;
};

#endif