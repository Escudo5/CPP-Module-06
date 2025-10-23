/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:49:46 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/23 14:06:11 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>
#include <limits>
#include <cctype>


class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        ~ScalarConverter();
        
        
        static bool isChar(const std::string &literal);
        static bool isFloat(const std::string &literal);
        static bool isInt(const std::string &literal);
        static bool isDouble(const std::string &literal);
        static bool isPseudo(const std::string &literal);

        static void convertFromChar(char literal);
        static void convertFromInt(int literal);
        static void convertFromFloat(float literal);
        static void convertFromDouble(double literal);
        static void printPseudo(const std::string &literal);
        
    public:
        static void convert(const std::string &literal);
    



};


#endif