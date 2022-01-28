/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialisation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tefroiss <tefroiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:49:11 by tefroiss          #+#    #+#             */
/*   Updated: 2022/01/07 14:39:17 by tefroiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialisation.hpp"

uintptr_t serialize(Data * ptr) 
{
	std::cout << "Serialization working..." << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) 
{
	std::cout << "Deserialization working..." << std::endl;
	return reinterpret_cast<Data *>(raw);	
}

std::ostream & operator<<(std::ostream & out, Data const & src)
{
	std::cout << std::endl;
	out << "Adress of Data Struct : " << &src << std::endl << std::endl;
	std::cout << "Structure DATA ->" << std::endl;
	out << src.a << std::endl;
	out << src.b << std::endl;
	out << src.c << std::endl;
	out << src.d << std::endl;
	out << src.e << std::endl;
	out << src.f << std::endl;
	out << src.ptr2 << std::endl;
	std::cout << std::endl;
	return out;
}