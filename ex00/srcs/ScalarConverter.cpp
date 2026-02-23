/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:06:51 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/23 11:04:33 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>

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

static void	printChar(char c)
{
	if (c < 32 || c > 126)
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: \'" << c << "\'"  << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void	printInt(const std::string& str)
{
	long value = std::strtol(str.c_str(), NULL, 10);
	if (value < INT_MIN || value > INT_MAX)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
	}
	else if (value < 32 || value > 126)
	{
		std::cout << "char: Non Displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	else
	{
		std::cout << "char: \'" << static_cast<char>(value) << "\'"  << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

static void	printDouble(const std::string& str)
{
	(void)str;
	std::cout << "DOUBLE\n";
}

static void	printFloat(const std::string& str)
{
	(void)str;
	std::cout << "FLOAT\n";
}

void	ScalarConverter::convert(const std::string& str)
{
	e_type	type = getType(str);

	switch (type)
	{
		case CHAR:
		{
			if (str.length() == 1)
				printChar(str[0]);
			else
				printChar(str[1]);
			break;
		}
		case INT:
		{
			printInt(str);
			break;
		}
		case FLOAT:
		{
			printFloat(str);
			break;
		}
		case DOUBLE:
		{
			printDouble(str);
			break;
		}
		case NOTHING:
			break;
	}
}

/* ************************************************************************** */
