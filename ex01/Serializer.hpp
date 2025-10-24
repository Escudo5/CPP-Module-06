/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:14:27 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/24 13:55:09 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
// #include <cstdint>
#include <stdint.h>

struct Data
{
    int number;
    std::string text;
};


class Serializer
{
    public:

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);



    private:
        Serializer();
        Serializer(const Serializer &copy);
        Serializer &operator=(const Serializer &copy);
        ~Serializer();


};



#endif