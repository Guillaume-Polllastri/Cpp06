/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:13:52 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/23 18:49:08 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base*	generate(void)
{
	int rng = rand() % 3;

	if (rng == 0)
		return new A;
	else if (rng == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "[Pointer] The type of this base is A" << std::endl;
	if (dynamic_cast<B*>(p) != NULL)
		std::cout << "[Pointer] The type of this base is B" << std::endl;
	if (dynamic_cast<C*>(p) != NULL)
		std::cout << "[Pointer] The type of this base is C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "[Reference] The type of this base is A" << std::endl;
	}
	catch (std::exception& ) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "[Reference] The type of this base is B" << std::endl;
	}
	catch (std::exception&) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "[Reference] The type of this base is C" << std::endl;
	}
	catch (std::exception&) {}
}


int	main(void)
{
	srand(time(NULL));

	Base*	base;

	base = generate();
	
	identify(base);
	identify(*base);

	delete base;
	return (0);
}