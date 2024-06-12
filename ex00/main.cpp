/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:44:26 by luciegernid       #+#    #+#             */
/*   Updated: 2024/06/12 09:43:35 by lgernido         ###   ########.fr       */
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
    ScalarConverter::convert(inputString);

    return (0);
}
