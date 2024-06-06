/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:06:05 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/06 10:10:29 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/

//Constructor
Serializer::Serializer()
{
    std::cout << BOLD << "Serializer" << RESET << ITALIC << " default constructor called" << RESET << std::endl;
    std::cout << std::endl;
}

//Destructor
Serializer::~Serializer()
{
    std::cout << BOLD << "Serializer" << RESET << ITALIC << " destructor called" << std::endl;
    std::cout << std::endl;
}

//Copy constructor
Serializer::Serializer(const Serializer& other)
{
    (void)other;
    std::cout << BOLD << "Serializer" << RESET << ITALIC << " copy constructor called" << std::endl;
    std::cout << std::endl;
}

/*ASSIGNMENT OPERATOR*/
Serializer& Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
}

/*PUBLIC METHODS*/
uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
    return (ret);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ret = reinterpret_cast<Data*>(raw);
    return (ret);
}