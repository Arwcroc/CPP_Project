/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:52:06 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/26 18:45:12 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "ERROR : Wrong number of argument" << std::endl;
		return EXIT_FAILURE;
	}

	Convert conv(av[1]); 

	std::cout << conv;
	return (0);
}