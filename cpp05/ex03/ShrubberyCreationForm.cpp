/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:18:23 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:47:22 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", false, 145, 137), _name_target("null") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name_target) : Form("ShrubberyCreationForm", false, 145, 137), _name_target(name_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const Name, bool Signed, int const gr_exec, int const gr_sign): Form("ShrubberyCreationForm", Signed, gr_exec, gr_sign),  _name_target(Name) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) { *this = src; }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getNameTarget() << " destroyed !" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	this->_name_target = src.getNameTarget();
	return *this;
}

std::string ShrubberyCreationForm::getNameTarget() const { return (this->_name_target); }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException("Grade too LOW in comparison with the recommand grade.");
	else if (!this->getGradeSign())
		throw GradeTooLowException("Impossible to get the grade required to sign the form.");
	
	std::string fileName = this->getNameTarget() + "_shrubbery";
	std::ofstream file (fileName.c_str());
	if (file.is_open())
	{
		file << "                                                                                \n" <<
				"                                                                                \n" <<
				"                   @                      @@                                    \n" <<
				"                   @@                     @              @                      \n" <<
				"              @    @                      @@       @@@  @                       \n" <<
				"                @@@            @@          @@   @@@@@@                          \n" <<
				"                 @@        @@@              @@ @                                \n" <<
				"                  @@    @@@            @     @@                 @@@@@@@@@       \n" <<
				"                   @@ (@@              @     @@              @@                 \n" <<
				"       @@    @      @@@@               @@    @@            @@/ /@/@             \n" <<
				"        @@  @@        @@@@@     @@       @@  @@           @@         @@         \n" <<
				"         @@@@             @@@@ @@         *@@@@          @@       @@            \n" <<
				"          @@@                @@@@          @@@          @@@@@@@@@@@@@           \n" <<
				"            @@@&               @@@@      &@@@         @@@                       \n" <<
				"               .@@@@@@@@@@@@@@@@@@@@   @@@@.      &@@@@                         \n" <<
				"                  @@@@@@      @@@@@@@ @@@@  @@@@@@@@@@@@                        \n" <<
				"  @           @@@@               @@@@@@@@@@@@@@@       @@@@@           @@@@     \n" <<
				"    @@@@@@@@@@@                    @@@@@@@@               @@@@@@@@@@@@@@@       \n" <<
				"           @@                       @@@@@@                 @@             @.    \n" <<
				"          @@                       @@@@@@                    @@@                \n" <<
				"                                   @@@@@@                                       \n" <<
				"                                   @@@@@                                        \n" <<
				"                                  @@@@@@                                        \n" <<
				"                                  @@@@@@                                        \n" <<
				"                                  @@@@@                                         \n" <<
				"                                  @@@@@                                         \n" <<
				"                                 @@@@@@                                         \n" <<
				"                                 @@@@@@                                         \n" <<
				"                                 @@@@@@                                         \n" <<
				"                                 @@@@@@@                                        \n" <<
				"                                  @@@@@@                                        \n" <<
				"                                  @@@@@@@                                       \n" <<
				"                                   @@@@@@@@                                     \n" <<
				"                                   @@@@@@@@@                                    \n" <<
				"                                 @@@@ @@@@@@@@                                  \n" <<
				"                         @@@@@@@@&   @@@    @@@@@@@@@@&                         \n" <<
				"                     ,@@@ @@          @@         @@@@@@@                        \n" <<
				"                   @@@    @@           @@@    *         @@@                     \n" <<
				"                                         @@                                     \n" <<
				"                                          @                                     " << std::endl;
		file.close();
	}
	else 
		std::cerr << "ERROR : " << fileName << "not exist" << std::endl;
}