/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:02:35 by luciegernid       #+#    #+#             */
/*   Updated: 2024/06/10 13:39:38 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*CONSTRUCTORS & DESTRUCTORS*/

//Default Constructor
ScalarConverter::ScalarConverter()
{
    std::cout << BOLD << "Scalar Converter" << RESET << ITALIC << " default constructor called" << RESET << std::endl;
    std::cout << std::endl;
}

//Destructor
ScalarConverter::~ScalarConverter()
{
    std::cout << BOLD << "Scalar Converter" << RESET << ITALIC << " destructor called" << RESET << std::endl;
    std::cout << std::endl;
}

//Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
    std::cout << BOLD << "Scalar Converter" << RESET << ITALIC << " copy constrcutor called" << RESET << std::endl;
    std::cout << std::endl;
}

/*ASSIGNMENT OPERATOR*/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this == &other)
        return (*this);
    return (*this);
}

/*PUBLIC METHODS*/

void ScalarConverter::convert(std::string const str)
{
    if (str.length() == 1) 
    {
        int charToInt = 0;
        if (!isdigit(str[0]))
            charToInt = static_cast<int>(str[0]);
        if (!isprint(charToInt))
        {
            std::cout << "char: Non displayable" << std::endl;          
        }
        else
        {
            char charValue = static_cast<char>(charToInt);
            std::cout << "char: '" << charValue << "'" << std::endl;
        }
    }
    else
    {
        int num = atoi(str.c_str());
        
        if (num >= 0 && num <= 127 && isprint(static_cast<char>(num)))
        {
            char charValue = static_cast<char>(num);
            std::cout << "char: '" << charValue << "'" << std::endl;
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
        }
    }

        // Convert to int
        if (str.length() == 1)
        {
            if (str[0] >= '0' && str[0] <= '9')
                std::cout << "int: " << str << std::endl;
            else         
            { 
                int strToInt = static_cast<int>(str[0]);    
                std::cout << "int: " << strToInt << std::endl;          
            }  
        }
        else
        {
            bool error = false;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                {
                    std::cout << "int: impossible" << std::endl;
                    error = true;
                    break;
                }
            }
            if (error == false)
            {
                int intValue = static_cast<int>(atoi(str.c_str()));
                std::cout << "int: " << intValue << std::endl;             
            }
        }

        // Convert to float
        bool error2 = false;
        float floatValue;
        if (str == "-inff") 
        {
            floatValue = -std::numeric_limits<float>::infinity();
        }
        else if (str == "+inff") 
        {
            floatValue = std::numeric_limits<float>::infinity();
        } 
        else if (str == "nanf") 
        {  
            floatValue = std::numeric_limits<float>::quiet_NaN();
        }
        else 
        {
            if (str.length() == 1 && (str[0] < 0 || str[0] > 9))
                floatValue = static_cast<float>(atof(str.c_str()));
            else
            {
                for (size_t i = 0; i < str.length(); i++)
                    {
                        if (!isdigit(str[i]))
                        {
                            std::cout << "float: impossible" << std::endl;
                            error2 = true;
                            break;
                        }
                    }  
                floatValue = static_cast<float>(str[0]);
            }
        }
        if (error2 == false)
        {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << floatValue << "f" << std::endl;
        }

        // Convert to double

            double doubleValue;
            bool error = false;
            if (str == "-inf") 
            {
                doubleValue = -std::numeric_limits<double>::infinity();
            } 
            else if (str == "+inf") 
            {
                doubleValue = std::numeric_limits<double>::infinity();
            } 
            else if (str == "nan") 
            {
                doubleValue = std::numeric_limits<double>::quiet_NaN();
            } 
            else 
            {
                for (size_t i = 0; i < str.length(); i++)
                {
                    if (!isdigit(str[i]))
                    {
                        std::cout << "double: impossible" << std::endl;
                        error = true;
                        break;
                    }
                }
                if (str.length() == 1 && (str[0] < 0 || str[0] > 9))
                    doubleValue = static_cast<double>(strtod(str.c_str(), NULL));
                else
                    doubleValue = static_cast<double>(str[0]);    
            } 
            if (error == false)
            {
                std::cout << std::fixed << std::setprecision(1);
                std::cout << "double: " << doubleValue << std::endl; 
            }

}
