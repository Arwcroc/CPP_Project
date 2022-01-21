/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:28:31 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/18 17:02:09 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) 
{
	try 
	{
		// Bureaucrat Lowrie(-10, "Lowrie");
		// Bureaucrat Highton(160, "Highton");
		Bureaucrat Michel(1, "Michel");

		std::cout << std::endl;
		std::cout << Michel;
		Michel.decreaseGrade();
		std::cout << Michel;
		Michel.increaseGrade();
		std::cout << Michel;
		// Michel.increaseGrade();
		// std::cout << Michel;
		while (Michel.getGrade() < 150)
			Michel.decreaseGrade();
		std::cout << Michel;
		Michel.decreaseGrade();
		std::cout << Michel;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}