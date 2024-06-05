/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:48:38 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/05 13:57:02 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*DESTRUCTORS*/
Base::~Base()
{
    std::cout << BOLD << "Base" << RESET << ITALIC << " destructor called." << RESET << std::endl;
    std::cout << std::endl;
}

/*PUBLIC METHODS*/

Base* Base::generate(void)
{
    
}

void Base::identify(Base *p)
{
    
}

void Base::identify(Base& p)
{
    
}