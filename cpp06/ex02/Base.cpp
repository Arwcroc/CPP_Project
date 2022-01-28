/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:15:08 by tefroiss          #+#    #+#             */
/*   Updated: 2021/12/13 19:17:00 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * generate(void)
{
    int i = rand() % 9 + 1;
    if (i <= 3)
        return (new A);
    else if (i >= 7)
        return (new B);
    else
        return (new C);
}

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "ERROR : no type from pointer found" << std::endl;
}

void identify_from_reference(Base & p)
{
    try
    {
        Base base = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    try
    {
        Base base = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    try
    {
        Base base = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    } 
    catch (std::exception &e) {}
}