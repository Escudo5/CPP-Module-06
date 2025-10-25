/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:01:15 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/25 13:25:08 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{
    std::cout << "Base destructor" << std::endl;
}
Base *generate(void)
{
    int random = rand() % 3;
    
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }
        if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "B" << std::endl;
        return;

    }
        if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "C" << std::endl;
        return;
    }
}
void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p); // usmaos void porque no necesitamos saber el resultado del casteo, solo si fuinciona o no.
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Not A keep trying" << std::endl;
    }
        try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Not B keep trying" << std::endl;
    }
        try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Not C keep trying" << std::endl;
    }
}