/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:02:35 by luciegernid       #+#    #+#             */
/*   Updated: 2024/05/29 16:18:23 by luciegernid      ###   ########.fr       */
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
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') 
    {
        char charValue = str[1];
        std::cout << "char: '" << charValue << "'" << std::endl;
    }
    else 
    {
        std::cout << "char: impossible" << std::endl;
    }

        // Convert to int
    try 
    {
        int intValue = std::stoi(str);
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
            floatValue = std::stof(str);
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
                doubleValue = std::stod(str);
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
