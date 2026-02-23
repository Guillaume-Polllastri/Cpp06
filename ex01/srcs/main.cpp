/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:21:59 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/23 17:35:44 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data	data;
	uintptr_t	raw;

	data.value = 42;
	raw = Serializer::serialize(&data);

	Data	*ptr;

	ptr = Serializer::deserialize(raw);
	std::cout << "data value = " << data.value << std::endl;
	std::cout << "ptr value = " << ptr->value << std::endl;
	if (ptr == &data)
		std::cout << "Same adress !" << std::endl;
	return (0);
}
