/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:02:35 by luciegernid       #+#    #+#             */
/*   Updated: 2024/06/12 09:38:46 by lgernido         ###   ########.fr       */
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
    (void)other;
    return (*this);
}

/*PUBLIC METHODS*/

bool parseNumber(const std::string& s) 
{
    bool hasDecimalPoint = false;
    bool hasDigits = false;
    size_t start = (s[0] == '-' || s[0] == '+') ? 1 : 0;

    for (size_t i = start; i < s.length(); ++i)
     {
        if (std::isdigit(s[i])) 
        {
            hasDigits = true;
        } 
        else if (s[i] == '.') 
        {
            if (hasDecimalPoint) return false;
            hasDecimalPoint = true;
        } 
        else if (s[i] == 'f' && i == s.length() - 1 && hasDigits) 
        {
            return true;
        } 
        else 
        {
            return false;
        }
    }
    return hasDigits;
}

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
    else if (parseNumber(str))
    {
        std::cout << "int: " << static_cast<int>(atoi(str.c_str())) << std::endl;
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
    if (str == "-inff" || str == "-inf") 
    {
        std::cout << "float: " << "-inf" << "f" << std::endl;
    }
    else if (str == "+inff" || str == "+inf") 
    {
        std::cout << "float: " << "inf" << "f" << std::endl;
    } 
    else if (str == "nan" || str == "nanf") 
    {  
        std::cout << "float: " << "nan" << "f" << std::endl;
    }
    else if (parseNumber(str))
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(atof(str.c_str())) << "f" << std::endl;
    }
    else 
    {
        if (str.length() == 1)
        {
            if (str[0] >= '0' && str[0] <= '9')
                std::cout << "float: " << str << "f" << std::endl;
            else         
            {  
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;          
            }  
        }
        else
        {
            bool error = false;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                {
                    std::cout << "float: impossible" << std::endl;
                    error = true;
                    break;
                }
            }
            if (error == false)
            {
                std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(atof(str.c_str())) << "f" << std::endl;           
            }
        }
    }

    // Convert to double

    if (str == "-inf" || str == "-inff") 
    {
        std::cout << "double: " << "-inf" << std::endl;
    } 
    else if (str == "+inf" || str == "+inff") 
    {
        std::cout << "double: " << "inf" << std::endl;
    } 
    else if (str == "nan" || str == "nanf") 
    {
        std::cout << "double: " << "nan" << std::endl;
    }
    else if (parseNumber(str))
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(strtod(str.c_str(), NULL)) << std::endl;
    }
    else 
    {
        if (str.length() == 1)
        {
            if (str[0] >= '0' && str[0] <= '9')
                std::cout << "double: " << str << std::endl;
            else         
            {   
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;           
            }  
        }
        else
        {
            bool error = false;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (!isdigit(str[i]))
                {
                    std::cout << "double: impossible" << std::endl;
                    error = true;
                    break;
                }
            }
            if (error == false)
            {
                std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(strtod(str.c_str(), NULL)) << std::endl;  
            }
        }
    }
}           
