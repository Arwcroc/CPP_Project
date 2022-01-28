/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:14:57 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/28 11:29:10 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	A test1;
    B test2;
    C test3;
	srand(time(NULL));

	std::cout << "Identify from Pointer" << std::endl;

    identify_from_pointer(&test1);
    identify_from_pointer(&test2);
    identify_from_pointer(&test3);

	std::cout << std::endl;
	std::cout << "Identify from Reference" << std::endl;
	
    identify_from_reference(test1);
    identify_from_reference(test2);
    identify_from_reference(test3);
	
	std::cout << std::endl;
    std::cout << "Random Identify" << std::endl;
    int i = 0;
	
    while (i < 15)
    {
        Base * testing = generate();
        identify_from_reference(*testing);
        identify_from_pointer(testing);
        std::cout << std::endl;
        delete testing;
        i++;
    }
}
