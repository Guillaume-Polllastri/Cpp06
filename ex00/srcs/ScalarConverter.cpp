/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:06:51 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/20 09:52:32 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>

/* ************************************************************************** */

// Canonical Form

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void) copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

/* ************************************************************************** */

// Method

static e_type	getType(const std::string& str)
{
	if (str.length() == 3)
	{
		if (str[0] == '\'' && str[2] == '\'')
			return (CHAR);
	}
	return (IMPOSSIBLE);
}

static void	printChar(const std::string& str)
{
	if (str[1] < 32 || str[1] > 126)
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: \'" << str[1] << "\'"  << std::endl;
}

void	ScalarConverter::convert(const std::string& str)
{
	e_type	type = getType(str);

	switch (type)
	{
		case CHAR:
			printChar(str);
			break;
		case INT:
			break;
		case FLOAT:
			break;
		case DOUBLE:
			break;
		case IMPOSSIBLE:
			break;
	}
}

/* ************************************************************************** */
