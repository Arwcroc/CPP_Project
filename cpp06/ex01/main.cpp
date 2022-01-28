/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:11:23 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/07 14:35:57 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialisation.hpp"

int main(void) 
{
    Data ptr;
    double d1(0.5f);
    double d2(1.2);
    char* chaine(const_cast<char*>("chaine"));

    ptr.a = 'c';
    ptr.b = 17;
    ptr.c = 5.5f;
    ptr.d = chaine;
    ptr.e = "string";
    ptr.f[0] = &d1;
    ptr.f[1] = &d2;
    ptr.ptr2 = NULL;
    std::cout << "**********      address of Data ptr      **********" << std::endl;
    std::cout << ptr << std::endl;
    std::cout << "******** address returned by deserialize ********" << std::endl;
    std::cout << *deserialize(serialize(&ptr)) << std::endl;
    return 0;
}
