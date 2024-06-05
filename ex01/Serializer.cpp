/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:06:05 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/05 18:44:49 by luciegernid      ###   ########.fr       */
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
    std::cout << BOLD << "Serializer" << RESET << ITALIC << " copy constructor called" << std::endl;
    std::cout << std::endl;
}

/*ASSIGNMENT OPERATOR*/
Serializer& Serializer::operator=(const Serializer &other)
{
    
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