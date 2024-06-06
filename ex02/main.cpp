/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:41:16 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/06 10:43:16 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() 
{
    // Generate and identify multiple instances to extensively test the class
    const int testCount = 10;
    Base* instances[testCount];

    for (int i = 0; i < testCount; ++i) {
        instances[i] = generate();
    }

    std::cout << GREEN BOLD << "Testing identify(Base* p):" << RESET << std::endl;
    for (int i = 0; i < testCount; ++i) {
        identify(instances[i]);
    }

    std::cout << GREEN BOLD << "Testing identify(Base& p):" << RESET << std::endl;
    for (int i = 0; i < testCount; ++i) {
        identify(*instances[i]);
    }

    // Cleanup
    for (int i = 0; i < testCount; ++i) {
        delete instances[i];
    }

    return 0;
}
