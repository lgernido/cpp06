/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:44:26 by luciegernid       #+#    #+#             */
/*   Updated: 2024/06/06 12:01:36 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        return (1);
    }
    std::string inputString = argv[1];
    ScalarConverter castedString;

    castedString.convert(inputString);

    return (0);
}
