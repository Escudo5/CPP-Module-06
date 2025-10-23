/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:55:41 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/23 18:48:36 by smarquez         ###   ########.fr       */
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
    if (isChar(literal))
        convertFromChar(literal[0]);
    else if (isInt(literal))
        convertFromInt(std::atoi(literal.c_str()));
    else if (isFloat(literal))
        convertFromFloat(std::strtof(literal.c_str(), NULL));
    else if (isDouble(literal))
        convertFromDouble(std::strtod(literal.c_str(), NULL));
    else
        std::cout << "Error: invalid literal" << std::endl;
        
}


void ScalarConverter::convertFromInt(int literal)
{
    if (std::isprint(literal))
        std::cout << "char: '" <<  static_cast<char>(literal) << "'" << std::endl;
    else
        std::cout << "char: non displayable" << std::endl;

    std::cout << "int: " << literal << std::endl;
    std::cout << "float: " << static_cast<float>(literal) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(literal) << std::endl;
}

void ScalarConverter::convertFromChar(char literal)
{
    if (std::isprint(literal))
        std::cout << "char : " << literal << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(literal) << std::endl;
    std::cout << "float: " << static_cast<float>(literal) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(literal) << std::endl;
}

void ScalarConverter::convertFromFloat(float literal)
{
    if (std::isnan(literal) || std::isinf(literal))
        std::cout << "char: impossible" << std::endl;
    else if(std::isprint(static_cast<int>(literal)))
        std::cout << "char: " << static_cast<char>(literal) << "'" << std::endl;
    else
        std::cout << "char: non dislayable" << std::endl;

    if (std::isnan(literal) || std::isinf(literal))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(literal) << std::endl;

    std::cout << "float: " << literal;
    if (literal == static_cast<float>(literal))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(literal);
    if (literal == static_cast<int>(literal))
        std::cout << ".0";
    std::cout << std::endl;
}
void ScalarConverter::convertFromDouble(double literal)
{
    if (std::isnan(literal) || std::isinf(literal))
        std::cout << "char: impossible" << std::endl;
    else if(std::isprint(static_cast<int>(literal)))
        std::cout << "char: " << static_cast<char>(literal) << "'" << std::endl;
    else
        std::cout << "char: non dislayable" << std::endl;

    if (std::isnan(literal) || std::isinf(literal))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(literal) << std::endl;

    std::cout << "float: " << static_cast<float>(literal);
    if (literal == static_cast<int>(literal))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << literal;
    if (literal == static_cast<int>(literal))
        std::cout << ".0";
    std::cout << std::endl;
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