/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:02:35 by luciegernid       #+#    #+#             */
/*   Updated: 2024/06/07 08:19:20 by lgernido         ###   ########.fr       */
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
    try 
    {
        int intValue = static_cast<int>(atoi(str.c_str()));
        std::cout << "int: " << intValue << std::endl;
    } 
    catch (std::invalid_argument&) 
    {
        std::cout << "int: impossible" << std::endl;
    } 
    catch (std::out_of_range&) 
    {
        std::cout << "int: impossible" << std::endl;
    }

        // Convert to float
    try 
    {
        float floatValue;
        if (str == "-inff") 
        {
            floatValue = -std::numeric_limits<float>::infinity();
        }
        else if (str == "+inff") 
        {
            floatValue = std::numeric_limits<float>::infinity();
        } else if (str == "nanf") 
        {  
            floatValue = std::numeric_limits<float>::quiet_NaN();
        }
        else 
        {
            floatValue = static_cast<float>(atof(str.c_str()));
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f" << std::endl;
    } 
        catch (std::invalid_argument&) 
        {
            std::cout << "float: impossible" << std::endl;
        } 
        catch (std::out_of_range&) 
        {
            std::cout << "float: impossible" << std::endl;
        }

        // Convert to double
        try 
        {
            double doubleValue;
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
                doubleValue = static_cast<double>(strtod(str.c_str(), NULL));
            } 
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << doubleValue << std::endl;
        } 
        catch (std::invalid_argument&) 
        {
            std::cout << "double: impossible" << std::endl;
        } catch (std::out_of_range&) 
        {
            std::cout << "double: impossible" << std::endl;
        }
}
