/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialisation.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:57:57 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/28 11:39:39 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdint.h>

typedef struct Data
{
    char a;
    int b;
    float c;
    char* d;
    std::string e;
    double* f[2];
    void* ptr2;
}             Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream & operator<<(std::ostream & o, Data const & rhs);

#endif