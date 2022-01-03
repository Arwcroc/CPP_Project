/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:45:49 by tefroiss          #+#    #+#             */
/*   Updated: 2021/07/24 12:42:53 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] = av[i][j] - 32;
				j++;
			}
			std::cout << av[i];
			i++;
		}
		std::cout << "\n";
	}
	return (0);
}