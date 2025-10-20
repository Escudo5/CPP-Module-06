/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:55:41 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/20 13:21:06 by smarquez         ###   ########.fr       */
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