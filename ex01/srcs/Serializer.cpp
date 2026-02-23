/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:16:20 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/23 17:29:06 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */

// Canonical Form

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy)
{
	(void) copy;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void) other;
	return *this;
}

Serializer::~Serializer() {}

/* ************************************************************************** */

// Methods

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
