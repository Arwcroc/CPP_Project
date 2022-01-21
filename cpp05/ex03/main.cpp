/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:31 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/17 11:49:10 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

void test1()
{
	try
	{
		Intern billy;
		Form *n_form = billy.makeform("BipBoopBip", "BoopBipBoop");
		std::cout << n_form << std::endl;
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void test2()
{
	try
	{
		Intern billy;
		Form *n_form = billy.makeform("Presidential Pardon", "Joker");
		std::cout << n_form << std::endl;
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void test3()
{
	try
	{
		Intern billy;
		Form *n_form = billy.makeform("Robotomy Request", "Blender");
		std::cout << n_form << std::endl;
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

void test4()
{
	try
	{
		Intern billy;
		Form *n_form = billy.makeform("Shrubbery Creation", "Ni");
		std::cout << n_form << std::endl;
	}
	catch(std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

int main()
{
	std::cout << "Test Intern create unknown form :\n";
	test1();
	std::cout << "\nTest Intern create presidential pardon form :\n";
	test2();
	std::cout << "\nTest Intern create robotomy request form :\n";
	test3();
	std::cout << "\nTest Intern create shrubbery creation form :\n";
	test4();

	return (0);
}
