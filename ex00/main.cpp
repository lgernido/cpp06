/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:44:26 by luciegernid       #+#    #+#             */
/*   Updated: 2024/05/29 21:09:17 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        return (1);
    }
    // Get fundamental scalar and build Cast object with him
    std::string inputString = argv[1];
    ScalarConverter castedString;

    castedString.convert(inputString);

    return (0);
}
