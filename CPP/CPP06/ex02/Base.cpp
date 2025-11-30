/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:17:16 by vgodart           #+#    #+#             */
/*   Updated: 2025/03/19 23:17:19 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Base.hpp"
#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"

Base::~Base() {}

Base * generate(void)
{
    switch (std::rand() % 3)
    {
        case 0:
        {
            std::cout << "	- Generated type is : A" << std::endl;
            return (new A);
        }
        case 1:
        {
            std::cout << "	- Generated type is : B" << std::endl;
            return (new B);
        }
        case 2:
        {
            std::cout << "	- Generated type is : C" << std::endl;
            return (new C);
        }
        default:
            break;
    }
    return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "	- Pointer type is : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "	- Pointer type is : B" << std::endl;
	else if (dynamic_cast<C*>(p))
	std::cout << "	- Pointer type is : C" << std::endl;
	else
		std::cout << "	Error type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &aRef = dynamic_cast<A&>(p);
		std::cout << "	- Ref type is : A" << std::endl;
		(void) aRef;
	}
	catch(const std::exception& e){}
	try
	{
		B &bRef = dynamic_cast<B&>(p);
		std::cout << "	- Ref type is : B" << std::endl;
		(void) bRef;
	}
	catch(const std::exception& e){}
	try
	{
		C &cRef = dynamic_cast<C&>(p);
		std::cout << "	- Ref type is : C" << std::endl;
		(void) cRef;
	}
	catch(const std::exception& e){}
}