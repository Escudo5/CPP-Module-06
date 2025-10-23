/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:55:41 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/23 13:52:27 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default destructor" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Error, empty string " << std::endl;
        return;
    }
    if (isPseudo(literal))
    {
        std::cout << "char: impossible " << std::endl;
        std::cout << "int: impossible " << std::endl;
    }
}


bool ScalarConverter::isPseudo(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
        return true;
    if (literal == "+inf" || literal == "-inf" || literal == "inf" || literal == "inff" || literal == "+inff" || literal == "-inff")
        return(true);
    return false;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.length() == 1  && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return true;
    return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    int i = 0;
    if (literal.length() == 0)
        return false;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
        
    for(; i < literal.length(); i++)
    {
        if(!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal.length() == 0)
        return false;
    if (literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "inff")
        return true;
    if (literal.back() != 'f')
        return false;
    int i = 0;
    int dotCount = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length() - 1; i++)
    {
        if (literal[i] == '.')
            dotCount++;
        else if (!std::isdigit(literal[i]))
            return false;
    }
    if (dotCount != 1)
        return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    if (literal.length() == 0)
        return false;
    if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "inf")
        return true;
    int i = 0;
    int dotCount = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
            dotCount++;
        else if (!std::isdigit(literal[i]))
            return false;
    }
    if (dotCount != 1)
        return false;
    return true;
}