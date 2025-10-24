/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:46:26 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/24 13:53:27 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main()
{
    Data datos;
    datos.number = 42;

    Data *originalPtr = &datos;

    std::cout << "Original address: " << originalPtr << std::endl;
    std::cout << "Int number: " << originalPtr->number << std::endl;



    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;


    Data *ptr = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << ptr << std::endl;


    if (originalPtr == ptr)
        std::cout << "Addresses are the same" << std::endl;
    else
        std::cout << "Error, adress doesn´t match" << std::endl;
    return (0);
}