/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:31 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/17 11:08:38 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
#include <time.h> 

void ShrubberyCreation1()
{
	try
	{
		ShrubberyCreationForm A36("A36", false, 100, 100);
		Bureaucrat Bill(1, "Bill");
		std::cout << A36;
		std::cout << Bill;

		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
		ShrubberyCreationForm DeadTree("DeadTree");
		Bill.executeForm(DeadTree);
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void ShrubberyCreation2()
{
	try
	{
		ShrubberyCreationForm A36("A36", false, 100, 100);
		Bureaucrat Bill(150, "Bill");
		std::cout << A36;
		std::cout << Bill;
		
		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
		ShrubberyCreationForm DeadTree("DeadTree");
		Bill.executeForm(DeadTree);
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void PresidentialPardon1()
{
	try
	{
		PresidentialPardonForm A36("A36", false, 100, 100);
		Bureaucrat Bill(1, "Bill");
		std::cout << A36;
		std::cout << Bill;
		
		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
		PresidentialPardonForm Amnesty("Amnesty");
		Bill.executeForm(Amnesty);
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void PresidentialPardon2()
{
	try
	{
		PresidentialPardonForm A36("A36", false, 100, 100);
		Bureaucrat Bill(150, "Bill");
		std::cout << A36;
		std::cout << Bill;

		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
		PresidentialPardonForm Amnesty("Amnesty");
		Bill.executeForm(Amnesty);
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void RobotomyRequest1 ()
{
	try
	{
		RobotomyRequestForm A36("A36", false, 100, 100);
		Bureaucrat Bill(1, "Bill");
		std::cout << A36;
		std::cout << Bill;

		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
		RobotomyRequestForm NonoTheBot("NonoTheBot");
		Bill.executeForm(NonoTheBot);
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void RobotomyRequest2()
{
	try
	{
		RobotomyRequestForm A36("A36", false, 100, 100);
		Bureaucrat Bill(150, "Bill");
		std::cout << A36;
		std::cout << Bill;

		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
		RobotomyRequestForm NonoTheBot("NonoTheBot");
		Bill.executeForm(NonoTheBot);
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	std::cout << "\nShrubberyCreation1 : try and catch form (100,100) signed by bureaucrat 1\n";
	ShrubberyCreation1();
	std::cout << "\nShrubberyCreation2 : try and catch form (100,100) signed by bureaucrat 150\n";
	ShrubberyCreation2();
	std::cout << "\nPresidentialPardon1 : try and catch form (100,100) signed by bureaucrat 1\n";
	PresidentialPardon1();
	std::cout << "\nPresidentialPardon2 : try and catch form (100,100) signed by bureaucrat 150\n";
	PresidentialPardon2();
	std::cout << "\nRobotomyRequest1 : try and catch form (100,100) signed by bureaucrat 1\n";
	RobotomyRequest1();
	std::cout << "\nRobotomyRequest2 : try and catch form (100,100) signed by bureaucrat 150\n";
	RobotomyRequest2();
	return (0);
}
