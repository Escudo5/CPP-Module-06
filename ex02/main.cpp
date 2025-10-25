/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:22:38 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/25 13:22:56 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    srand(time(NULL));
    
    // Generar y probar con punteros
    Base* obj1 = generate();
    std::cout << "Identificando con puntero: ";
    identify(obj1);
    
    // Probar con referencia
    std::cout << "Identificando con referencia: ";
    identify(*obj1);
    
    delete obj1;
    
    // Repetir varias veces para probar la aleatoriedad
    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        std::cout << "Objeto " << i << " - Puntero: ";
        identify(obj);
        std::cout << "Objeto " << i << " - Referencia: ";
        identify(*obj);
        delete obj;
    }
    
    return 0;
}