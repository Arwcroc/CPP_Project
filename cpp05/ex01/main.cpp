/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:31 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/16 20:55:50 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void test1()
{
	try
	{
		Form A36("A36", false, 100, 100);
		Bureaucrat Bill(1, "Bill");
		std::cout << A36;
		std::cout << Bill;

		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
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
		Form A36("A36", false, 100, 100);
		Bureaucrat Bill(150, "Bill");
		std::cout << A36;
		std::cout << Bill;
		
		std::cout << "Signing...\n";
		A36.beSigned(Bill);
		std::cout << A36;
	}
	catch (std::exception &exc)
	{
		std::cout << exc.what() << std::endl;
	}
}

int main()
{
	std::cout << "Test 1 : try and catch form (100,100)  signed by bureaucrat 1\n";
	test1();
	std::cout << "\nTest 2 : try and catch form (100,100)  signed by bureaucrat 150\n";
	test2();

	return (0);
}