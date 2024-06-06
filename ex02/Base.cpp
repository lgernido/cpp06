/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:48:38 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/06 10:40:46 by lgernido         ###   ########.fr       */
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

Base* generate(void)
{
    static bool init = false;
    if (!init)
    {
        std::srand(time(NULL));
        init = true;
    }
    int i = std::rand() % 3;
    std::cout << rand() << std::endl; 
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p)) 
    {
        std::cout << "A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p)) 
    {
        std::cout << "B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p)) 
    {
        std::cout << "C" << std::endl;
    } 
    else 
    {
        std::cout << "Error" << std::endl;
    }
}

void identify(Base& p)
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
    } 
    catch (std::exception &e) 
    {
        try 
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)b;
        } 
        catch (std::exception &e) 
        {
            try 
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)c;
            } 
            catch (std::exception &e) 
            {
                std::cout << "Error" << std::endl;
            }
        }
    }
}