/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:31:49 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/24 13:45:59 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    
}

Serializer::~Serializer()
{
    
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);  //convierte el puntero a un int
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);  //convierte el int a un puntero
}