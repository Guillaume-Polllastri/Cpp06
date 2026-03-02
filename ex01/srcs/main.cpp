/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:21:59 by gpollast          #+#    #+#             */
/*   Updated: 2026/03/02 18:14:51 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	data;
	uintptr_t	raw;

	data.value = 42;
	std::cout << "data adress = " << &data << std::endl;
	std::cout << "data value = " << data.value << std::endl << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "(raw) data adress = " << raw << std::endl << std::endl;
	
	Data	*ptr;

	ptr = Serializer::deserialize(raw);
	std::cout << "ptr adress = " << ptr << std::endl;
	std::cout << "ptr value = " << ptr->value << std::endl;
	if (ptr == &data)
		std::cout << "Same adress !" << std::endl;
	return (0);
}
