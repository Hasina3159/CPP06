/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntodisoa <ntodisoa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:57:04 by ntodisoa          #+#    #+#             */
/*   Updated: 2025/04/02 14:36:31 by ntodisoa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
    {
        std::cout << "Generated : A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated : B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated : C" << std::endl;
        return new C();
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified 1 : A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified 1 : B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified 1 : C" << std::endl;
    else
        std::cout << "42" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Identified 2 : A" << std::endl;
    }
    catch (std::exception &e) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Identified 2 : B" << std::endl;
    }
    catch (std::exception &e) {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Identified 2 : C" << std::endl;
    }
    catch (std::exception &e) {}
}
int main()
{
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}